/////////////////////////////////////////////////////////////////////////////
// DragDropListCtrl.cpp : implementation file
//
// Adrian Stanley 13/02/2000
// Totally free source code - use however you like.
// adrian@adrians.demon.co.uk.
//
// This class illustrates how to implement drag and drop for a MFC 
// list control.
//
// It has the following features:
//	Supports dragging of single and multiple selections.
//	Potential drag targets are highlighted (selected) as the mouse moves
//	over them.
//	The list box will scroll when you try to drag out of the top or bottom.
//	Horizontal mouse movement is ignored; if the mouse is to the left or right
//	of the list control, dragging still occurs as though the mouse is over
//	the control.
//	Works with LVS_EX_FULLROWSELECT style on or off.
//	Preserves checked state of dragged items.
//	All code encapulated in the control - no changes required to parent 
//	class.
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DragDropListCtrl.h"
#include "InPlaceEdit.h"
#include "InPlaceCombo.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <afxdisp.h>	// OLE stuff
#include <shlwapi.h>	// Shell functions (PathFindExtension() in this case)
#include <afxpriv.h>	// ANSI to/from Unicode conversion macros


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//#defines
#define FIRST_COLUMN				0
#define MIN_COLUMN_WIDTH			10
#define MAX_DROP_DOWN_ITEM_COUNT	10

static const int SCROLL_TIMER_ID		= 1;

/////////////////////////////////////////////////////////////////////////////
// CDragDropListCtrl

CDragDropListCtrl::CDragDropListCtrl() :
	m_nDropIndex(-1),
	m_pDragImage(NULL),
	m_nPrevDropIndex(-1),
	m_uPrevDropState(NULL),
	m_uScrollTimer(0),
	m_ScrollDirection(scrollNull),
	m_dwStyle(NULL)
{

	/* Setup Drop file mode */
	m_dropMode.iMask = DL_ACCEPT_FILES;
	m_dropMode.pfnCallback = NULL;

	m_dwEditCtrlStyle = ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_LEFT | ES_NOHIDESEL;
	m_dwDropDownCtrlStyle = WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_AUTOVSCROLL | 
							CBS_DROPDOWNLIST | CBS_DISABLENOSCROLL;
}

CDragDropListCtrl::~CDragDropListCtrl()
{
	// Fail safe clean up.
	delete m_pDragImage;
	m_pDragImage = NULL;

	KillScrollTimer();
}


BEGIN_MESSAGE_MAP(CDragDropListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CDragDropListCtrl)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_DROPFILES()
	ON_NOTIFY_REFLECT(LVN_BEGINDRAG, OnBeginDrag)
	ON_WM_TIMER()
	ON_NOTIFY_REFLECT(LVN_BEGINLABELEDIT, OnBeginLabelEdit)
    ON_NOTIFY_REFLECT(LVN_ENDLABELEDIT, OnEndLabelEdit)
	ON_NOTIFY_REFLECT(NM_CLICK, OnClick)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDragDropListCtrl message handlers

void CDragDropListCtrl::OnBeginDrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	if (pNMListView)
	{
		m_nPrevDropIndex	= -1;
		m_uPrevDropState	= NULL;
		
		// Items being dragged - can be one or more.
		m_anDragIndexes.RemoveAll();
		POSITION pos = GetFirstSelectedItemPosition();
		while (pos)
		{
			m_anDragIndexes.Add(GetNextSelectedItem(pos));
		}

		DWORD dwStyle = GetStyle();
		if ((dwStyle & LVS_SINGLESEL) == LVS_SINGLESEL)
		{
			// List control is single select; we need it to be multi-select so
			// we can show both the drag item and potential drag target as selected.
			m_dwStyle = dwStyle;
			ModifyStyle(LVS_SINGLESEL, NULL);
		}

		if (m_anDragIndexes.GetSize() > 0)
		{
			// Create a drag image from the centre point of the item image.
			// Clean up any existing drag image first.
			delete m_pDragImage;
			CPoint ptDragItem;
			m_pDragImage = CreateDragImageEx(&ptDragItem);
			if (m_pDragImage)
			{
				m_pDragImage->BeginDrag(0, ptDragItem);
				m_pDragImage->DragEnter(CWnd::GetDesktopWindow(), pNMListView->ptAction);
			
				// Capture all mouse messages in case the user drags outside the control.
				SetCapture();
			}
		}
	}
	
	*pResult = 0;
}

// Based on code by Frank Kobs.
CImageList* CDragDropListCtrl::CreateDragImageEx(LPPOINT lpPoint)
{
	CRect rectSingle;	
	CRect rectComplete(0, 0, 0, 0);
	int	nIndex	= -1;
	BOOL bFirst	= TRUE;

	// Determine the size of the drag image.
	POSITION pos = GetFirstSelectedItemPosition();
	while (pos)
	{
		nIndex = GetNextSelectedItem(pos);
		GetItemRect(nIndex, rectSingle, LVIR_BOUNDS);
		if (bFirst)
		{
			// Initialize the CompleteRect
			GetItemRect(nIndex, rectComplete, LVIR_BOUNDS);
			bFirst = FALSE;
		}
		rectComplete.UnionRect(rectComplete, rectSingle);
	}

	// Create bitmap in memory DC
	CClientDC dcClient(this);	
	CDC dcMem;	
	CBitmap Bitmap;

	if (!dcMem.CreateCompatibleDC(&dcClient))
	{
		return NULL;
	}

	if (!Bitmap.CreateCompatibleBitmap(&dcClient, rectComplete.Width(), rectComplete.Height()))
	{
		return NULL;
	}
	
	CBitmap* pOldMemDCBitmap = dcMem.SelectObject(&Bitmap);
	// Here green is used as mask color.
	dcMem.FillSolidRect(0, 0, rectComplete.Width(), rectComplete.Height(), RGB(0, 255, 0)); 

	// Paint each DragImage in the DC.
	CImageList* pSingleImageList = NULL;
	CPoint pt;

	pos = GetFirstSelectedItemPosition();
	while (pos)
	{
		nIndex = GetNextSelectedItem(pos);
		GetItemRect(nIndex, rectSingle, LVIR_BOUNDS);

		pSingleImageList = CreateDragImage(nIndex, &pt);
		if (pSingleImageList)
		{
			// Make sure width takes into account not using LVS_EX_FULLROWSELECT style.
			IMAGEINFO ImageInfo;
			pSingleImageList->GetImageInfo(0, &ImageInfo);
			rectSingle.right = rectSingle.left + (ImageInfo.rcImage.right - ImageInfo.rcImage.left);

			pSingleImageList->DrawIndirect(
				&dcMem, 
				0, 
				CPoint(rectSingle.left - rectComplete.left, 
				rectSingle.top - rectComplete.top),
				rectSingle.Size(), 
				CPoint(0,0));

			delete pSingleImageList;
		}
	}

	dcMem.SelectObject(pOldMemDCBitmap);

	// Create the imagelist	with the merged drag images.
	CImageList* pCompleteImageList = new CImageList;
	
	pCompleteImageList->Create(rectComplete.Width(), rectComplete.Height(), ILC_COLOR | ILC_MASK, 0, 1);
	// Here green is used as mask color.
	pCompleteImageList->Add(&Bitmap, RGB(0, 255, 0)); 

	Bitmap.DeleteObject();

	// As an optional service:
	// Find the offset of the current mouse cursor to the imagelist
	// this we can use in BeginDrag().
	if (lpPoint)
	{
		CPoint ptCursor;
		GetCursorPos(&ptCursor);
		ScreenToClient(&ptCursor);
		lpPoint->x = ptCursor.x - rectComplete.left;
		lpPoint->y = ptCursor.y - rectComplete.top;
	}

	return pCompleteImageList;
}

void CDragDropListCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (m_pDragImage)
	{
		// Must be dragging, as there is a drag image.

		// Move the drag image.
		CPoint ptDragImage(point);
		ClientToScreen(&ptDragImage);
		m_pDragImage->DragMove(ptDragImage);
		
		// Leave dragging so we can update potential drop target selection.
		m_pDragImage->DragLeave(CWnd::GetDesktopWindow());

		// Force x coordinate to always be in list control - only interested in y coordinate.
		// In effect the list control has captured all horizontal mouse movement.
		static const int nXOffset = 8;
		CRect rect;
		GetWindowRect(rect);
		CWnd* pDropWnd = CWnd::WindowFromPoint(CPoint(rect.left + nXOffset, ptDragImage.y));

		// Get the window under the drop point.
		if (pDropWnd == this)
		{
			// Still in list control so select item under mouse as potential drop target.
			point.x = nXOffset;	// Ensures x coordinate is always valid.
			UpdateSelection(HitTest(point));
		}

		CRect rectClient;
		GetClientRect(rectClient);
		CPoint ptClientDragImage(ptDragImage);
		ScreenToClient(&ptClientDragImage);

		// Client rect includes header height, so ignore it, i.e.,
		// moving the mouse over the header (and higher) will result in a scroll up.
		CHeaderCtrl* pHeader = (CHeaderCtrl*)GetDlgItem(0);
		if (pHeader)
		{
			CRect rectHeader;
			pHeader->GetClientRect(rectHeader);
			rectClient.top += rectHeader.Height();
		}

		if (ptClientDragImage.y < rectClient.top)
		{
			// Mouse is above the list control - scroll up.
			SetScrollTimer(scrollUp);
		}
		else if (ptClientDragImage.y > rectClient.bottom)
		{
			// Mouse is below the list control - scroll down.
			SetScrollTimer(scrollDown);
		}
		else
		{
			KillScrollTimer();
		}

		// Resume dragging.
		m_pDragImage->DragEnter(CWnd::GetDesktopWindow(), ptDragImage);
	}
	else
	{
		KillScrollTimer();
	}

	CListCtrl::OnMouseMove(nFlags, point);
}

void CDragDropListCtrl::UpdateSelection(int nDropIndex)
{
	if (nDropIndex > -1 && nDropIndex < GetItemCount())
	{
		// Drop index is valid and has changed since last mouse movement.

		RestorePrevDropItemState();

		// Save information about current potential drop target for restoring next time round.
		m_nPrevDropIndex = nDropIndex;
		m_uPrevDropState = GetItemState(nDropIndex, LVIS_SELECTED);

		// Select current potential drop target.
		SetItemState(nDropIndex, LVIS_SELECTED, LVIS_SELECTED);
		m_nDropIndex = nDropIndex;		// Used by DropItem().

		UpdateWindow();
	}
}

void CDragDropListCtrl::RestorePrevDropItemState()
{
	if (m_nPrevDropIndex > -1 && m_nPrevDropIndex < GetItemCount())
	{
		// Restore state of previous potential drop target.
		SetItemState(m_nPrevDropIndex, m_uPrevDropState, LVIS_SELECTED);
	}
}

void CDragDropListCtrl::SetScrollTimer(EScrollDirection ScrollDirection)
{
	if (m_uScrollTimer == 0)
	{
		m_uScrollTimer = SetTimer(SCROLL_TIMER_ID, 100, NULL);
	}
	m_ScrollDirection = ScrollDirection;
}

void CDragDropListCtrl::KillScrollTimer()
{
	if (m_uScrollTimer != 0)
	{
		KillTimer(SCROLL_TIMER_ID);
		m_uScrollTimer		= 0;
		m_ScrollDirection	= scrollNull;
	}
}

void CDragDropListCtrl::OnLButtonDown(UINT nFlags, CPoint obPoint) 
{
	// Get the current column and row
	HitTestEx(obPoint, &m_rowLocation, &m_columnLocation);

	CListCtrl::OnLButtonDown(nFlags, obPoint);
}

void CDragDropListCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if (m_pDragImage)
	{
		KillScrollTimer();

		// Release the mouse capture and end the dragging.
		::ReleaseCapture();
		m_pDragImage->DragLeave(CWnd::GetDesktopWindow());
		m_pDragImage->EndDrag();

		delete m_pDragImage;
		m_pDragImage = NULL;

		// Drop the item on the list.
		DropItem();
	}
	
	CListCtrl::OnLButtonUp(nFlags, point);
}

void CDragDropListCtrl::DropItem()
{
	RestorePrevDropItemState();

	// Drop after currently selected item.
	m_nDropIndex++;
	if (m_nDropIndex < 0 || m_nDropIndex > GetItemCount() - 1)
	{
		// Fail safe - invalid drop index, so drop at end of list.
		m_nDropIndex = GetItemCount();
	}

	int nColumns = 1;
	CHeaderCtrl* pHeader = (CHeaderCtrl*)GetDlgItem(0);
	if (pHeader)
	{
		nColumns = pHeader->GetItemCount();
	}

	// Move all dragged items to their new positions.
	for (int nDragItem = 0; nDragItem < m_anDragIndexes.GetSize(); nDragItem++)
	{
		int nDragIndex = m_anDragIndexes[nDragItem];

		if (nDragIndex > -1 && nDragIndex < GetItemCount())
		{
			// Get information about this drag item.
			char szText[256];
			LV_ITEM lvItem;
			ZeroMemory(&lvItem, sizeof(LV_ITEM));
			lvItem.iItem		= nDragIndex;
			lvItem.mask			= LVIF_TEXT | LVIF_IMAGE | LVIF_STATE | LVIF_PARAM;
			lvItem.stateMask	= LVIS_DROPHILITED | LVIS_FOCUSED | LVIS_SELECTED | LVIS_STATEIMAGEMASK;
			lvItem.pszText		= (LPWSTR)szText;
			lvItem.cchTextMax	= sizeof(szText) - 1;
			GetItem(&lvItem);
			BOOL bChecked = GetCheck(nDragIndex);
			
			// Before moving drag item, make sure it is deselected in its original location,
			// otherwise GetSelectedCount() will return 1 too many.
			SetItemState(nDragIndex, static_cast<UINT>(~LVIS_SELECTED), LVIS_SELECTED);

			// Insert the dragged item at drop index.
			lvItem.iItem		= m_nDropIndex;
			InsertItem(&lvItem);
			if (bChecked)
			{
				SetCheck(m_nDropIndex);
			}
			
			// Index of dragged item will change if item has been dropped above itself.
			if (nDragIndex > m_nDropIndex)
			{
				nDragIndex++;
			}

			// Fill in all the columns for the dragged item.
			lvItem.mask		= LVIF_TEXT;
			lvItem.iItem	= m_nDropIndex;

			for (int nColumn = 1; nColumn < nColumns; nColumn++)
			{
				_tcscpy(lvItem.pszText, (LPCTSTR)(GetItemText(nDragIndex, nColumn)));
				lvItem.iSubItem = nColumn;
				SetItem(&lvItem);
			}
			
			// Delete the original item.
			DeleteItem(nDragIndex);

			// Need to adjust indexes of remaining drag items.
			for (int nNewDragItem = nDragItem; nNewDragItem < m_anDragIndexes.GetSize(); nNewDragItem++)
			{
				int nNewDragIndex = m_anDragIndexes[nNewDragItem];

				if (nDragIndex < nNewDragIndex && nNewDragIndex < m_nDropIndex)
				{
					// Item has been removed from above this item, and inserted after it,
					// so this item moves up the list.
					m_anDragIndexes[nNewDragItem] = max(nNewDragIndex - 1, 0);
				}
				else if (nDragIndex > nNewDragIndex && nNewDragIndex > m_nDropIndex)
				{
					// Item has been removed from below this item, and inserted before it,
					// so this item moves down the list.
					m_anDragIndexes[nNewDragItem] = nNewDragIndex + 1;
				}
			}
			if (nDragIndex > m_nDropIndex)
			{
				// Item has been added before the drop target, so drop target moves down the list.
				m_nDropIndex++;
			}
		}
	}

	if (m_dwStyle != NULL)
	{
		// Style was modified, so return it back to original style.
		ModifyStyle(NULL, m_dwStyle);
		m_dwStyle = NULL;
	}
}

void CDragDropListCtrl::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == SCROLL_TIMER_ID && m_pDragImage)
	{
		WPARAM wParam	= NULL;
		int nDropIndex	= -1;
		if (m_ScrollDirection == scrollUp)
		{
			wParam		= MAKEWPARAM(SB_LINEUP, 0);
			nDropIndex	= m_nDropIndex - 1;
		}
		else if (m_ScrollDirection == scrollDown)
		{
			wParam		= MAKEWPARAM(SB_LINEDOWN, 0);
			nDropIndex	= m_nDropIndex + 1;
		}
		m_pDragImage->DragShowNolock(FALSE);
		SendMessage(WM_VSCROLL, wParam, NULL);
		UpdateSelection(nDropIndex);
		m_pDragImage->DragShowNolock(TRUE);
	}
	else
	{
		CListCtrl::OnTimer(nIDEvent);
	}
}

// HitTestEx	- Determine the row index and column index for a point
// Returns	- the row index or -1 if point is not over a row
// point	- point to be tested.
// col		- to hold the column index
int CDragDropListCtrl::HitTestEx(CPoint &point, int *row_loc, int *col)
{
	int colnum = 0;
	int row = HitTest( point, NULL );

	*row_loc = row;
	
	if( col ) *col = 0;

	// Make sure that the ListView is in LVS_REPORT
	if( (GetWindowLong(m_hWnd, GWL_STYLE) & LVS_TYPEMASK) != LVS_REPORT )
		return row;

	// Get the top and bottom row visible
	row = GetTopIndex();
	int bottom = row + GetCountPerPage();
	if( bottom > GetItemCount() )
		bottom = GetItemCount();
	
	// Get the number of columns
	CHeaderCtrl* pHeader = (CHeaderCtrl*)GetDlgItem(0);
	int nColumnCount = pHeader->GetItemCount();

	// Loop through the visible rows
	for( ;row <=bottom;row++)
	{
		// Get bounding rect of item and check whether point falls in it.
		CRect rect;
		GetItemRect( row, &rect, LVIR_BOUNDS );
		if( rect.PtInRect(point) )
		{
			// Now find the column
			for( colnum = 0; colnum < nColumnCount; colnum++ )
			{
				int colwidth = GetColumnWidth(colnum);
				if( point.x >= rect.left 
					&& point.x <= (rect.left + colwidth ) )
				{
					if( col ) *col = colnum;
					return row;
				}
				rect.left += colwidth;
			}
		}
	}
	return -1;
}


void CDragDropListCtrl::OnClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	if ((m_rowLocation == -1) || (m_columnLocation == -1))
	{
		m_rowLocation = -1;
		m_columnLocation = -1;
		return;
	}

	// If column is not read only then
	// If the SHIFT or CTRL key is down call the base class
	// Check the high bit of GetKeyState to determine whether SHIFT or CTRL key is down
	if ((GetKeyState(VK_SHIFT) & 0x80) || (GetKeyState(VK_CONTROL) & 0x80))
	{
		m_rowLocation = -1;
		m_columnLocation = -1;
		return;
	}

	// Get the current selection before creating the in place combo box
	CString strCurSelection = GetItemText(m_rowLocation, m_columnLocation);
	
	if (-1 != m_rowLocation)
	{
		UINT flag = LVIS_FOCUSED;
		
		if ((GetItemState(m_rowLocation, flag ) & flag) == flag)
		{
			// Add check for LVS_EDITLABELS
			if (GetWindowLong(m_hWnd, GWL_STYLE) & LVS_EDITLABELS)
			{
				// If combo box is supported
				// Create and show the in place combo box
				if (IsCombo(m_columnLocation))
				{
					CStringList obComboItemsList;
										
					GetParent()->SendMessage(WM_SET_ITEMS, (WPARAM)m_columnLocation, (LPARAM)&obComboItemsList);  
					
					CInPlaceCombo* pInPlaceComboBox = ShowInPlaceList(m_rowLocation, m_columnLocation, obComboItemsList, strCurSelection);
					ASSERT(pInPlaceComboBox); 
					
					// Set the selection to previous selection
					pInPlaceComboBox->SelectString(-1, strCurSelection);
				}
				// If combo box is not read only
				// Create and show the in place edit control
				else if (!IsReadOnly(m_columnLocation))
				{
					CInPlaceEdit* pInPlaceEdit = ShowInPlaceEdit(m_rowLocation, m_columnLocation, strCurSelection);
				}
			}
		}
	}  

	/*NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	EditLabel (pNMListView->iSubItem);*/
	m_rowLocation = -1;
	m_columnLocation = -1;

    *pResult = 0;
}

void CDragDropListCtrl::OnBeginLabelEdit (NMHDR* pNMHDR, LRESULT* pResult) 
{
    LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
    *pResult = 1;
    
    CRect ItemRect;
    GetItemRect (pDispInfo->item.iItem, ItemRect, LVIR_LABEL);

    HWND hWnd = (HWND)SendMessage (LVM_GETEDITCONTROL);
    ASSERT (hWnd != NULL);
    if (m_Edit.m_hWnd != 0)
		m_Edit.DestroyWindow ();
    VERIFY (m_Edit.SubclassWindow (hWnd));

    //m_Edit.x = ItemRect.left;
    //m_Edit.y = ItemRect.top - 1;
    m_Edit.SetWindowText (GetItemText (pDispInfo->item.iItem, 0));

    *pResult = 0;
} // OnBeginLabelEdit

// when the editing ends, we need to unsubclass the edit box before it gets destroyed
void CDragDropListCtrl::OnEndLabelEdit (NMHDR* pNMHDR, LRESULT* pResult) 
{
    LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
    int iField = (int)pDispInfo->item.lParam;
    CString NewText (pDispInfo->item.pszText);
    
    SetItem (&pDispInfo->item);
    *pResult = 1;

    if (m_Edit.m_hWnd)
		VERIFY (m_Edit.UnsubclassWindow () != NULL);
} // OnEndLabelEdit

/*************************** STUFF Drag Drop Files ***********************************************************/

void CDragDropListCtrl::OnDropFiles(HDROP dropInfo)
{
	//
	// Get the number of pathnames (files or folders) dropped
	//
	UINT nNumFilesDropped = DragQueryFile(dropInfo, 0xFFFFFFFF, NULL, 0);

	//
	// Iterate through the pathnames and process each one
	//
	TCHAR szFilename[MAX_PATH + 1];
	CString csPathname;
	CString csExpandedFilename;

	for (UINT nFile = 0 ; nFile < nNumFilesDropped; nFile++)
	{
		//
		// Get the pathname
		//
		DragQueryFile(dropInfo, nFile, szFilename, MAX_PATH + 1);

		//
		// It might be shortcut, so try and expand it
		//
		csPathname = szFilename;
		csExpandedFilename = ExpandShortcut(csPathname);
		if(!csExpandedFilename.IsEmpty())
		{
			csPathname = csExpandedFilename;
		}


		//
		// Now see if its something we allow to be dropped
		//
		UINT iPathType = 0;
		if(ValidatePathname(csPathname, iPathType))
		{
			//
			// By default, we insert the filename into the list
			// ourselves, but if our parent wants to do something flashy
			// with it (maybe get the filesize and insert that as an extra
			// column), they will have installed a callback for each
			// droppped item
			//
			if(m_dropMode.iMask & DL_USE_CALLBACK)
			{
				//
				// Let them know about this list control and the item
				// droppped onto it
				//
				if(m_dropMode.pfnCallback)
					m_dropMode.pfnCallback(this, csPathname, iPathType);
			}
			else
			{
				InsertPathname(csPathname);
			}
		}
	}


	//
	// Free the dropped-file info that was allocated by windows
	//
	DragFinish(dropInfo);
}

//////////////////////////////////////////////////////////////////
//
//	ExpandShortcut()
//
//	Uses IShellLink to expand a shortcut.
//
//	Return value:
//		the expanded filename, or "" on error or if filename
//		wasn't a shortcut
//
//	Adapted from CShortcut, 1996 by Rob Warner
//	rhwarner@southeast.net
//	http://users.southeast.net/~rhwarner

CString CDragDropListCtrl::ExpandShortcut(CString& csFilename) const
{
	USES_CONVERSION;		// For T2COLE() below
	CString csExpandedFile;

	//
    // Make sure we have a path
	//
	if(csFilename.IsEmpty())
	{
		ASSERT(FALSE);
		return csExpandedFile;
	}

	//
    // Get a pointer to the IShellLink interface
	//
    HRESULT hr;
    IShellLink* pIShellLink;

    hr = ::CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER,
							IID_IShellLink, (LPVOID*) &pIShellLink);

    if (SUCCEEDED(hr))
    {

		//
        // Get a pointer to the persist file interface
		//
		IPersistFile* pIPersistFile;
        hr = pIShellLink->QueryInterface(IID_IPersistFile, (LPVOID*) &pIPersistFile);

        if (SUCCEEDED(hr))
        {
			//
            // Load the shortcut and resolve the path
			//
            // IPersistFile::Load() expects a UNICODE string
			// so we're using the T2COLE macro for the conversion
			//
			// For more info, check out MFC Technical note TN059
			// (these macros are also supported in ATL and are
			// so much better than the ::MultiByteToWideChar() family)
			//
            hr = pIPersistFile->Load(T2COLE(csFilename), STGM_READ);
			
			if (SUCCEEDED(hr))
			{
				WIN32_FIND_DATA wfd;
				hr = pIShellLink->GetPath(csExpandedFile.GetBuffer(MAX_PATH),
										  MAX_PATH,
										  &wfd,
										  SLGP_UNCPRIORITY);

				csExpandedFile.ReleaseBuffer(-1);
            }
            pIPersistFile->Release();
        }
        pIShellLink->Release();
    }

    return csExpandedFile;
}
//////////////////////////////////////////////////////////////////
//
//	ValidatePathname()
//
//	Checks if a pathname is valid based on these options set:
//		Allow directories to be dropped
//		Allow files to be dropped
//		Only allow files with a certain extension to be dropped
//
//	Return value:
//		TRUE:	the pathname is suitable for selection, or
//		FALSE:	the pathname failed the checks.
//
//		If successful, iPathType specifies the type of path
//		validated - either a file or a folder.

BOOL CDragDropListCtrl::ValidatePathname(const CString& csPathname, UINT& iPathType) const
{
	//
	// Get some info about that path so we can filter out dirs
	// and files if need be
	//
	BOOL bValid = FALSE;

	struct _stat buf;
	int result = _tstat( csPathname, &buf );
	if( result == 0 )
	{
		//
		// Do we have a directory? (if we want dirs)
		//
		if ((m_dropMode.iMask & DL_ACCEPT_FOLDERS) &&
			((buf.st_mode & _S_IFDIR) == _S_IFDIR)) 
	    {
			bValid = TRUE;
			iPathType = DL_FOLDER_TYPE;
		} 
	    else if ((m_dropMode.iMask & DL_ACCEPT_FILES) &&
				((buf.st_mode & _S_IFREG) == _S_IFREG)) 
	    {
			// 
			// We've got a file and files are allowed.
			//
			iPathType = DL_FILE_TYPE;

			//
			// Now if we are filtering out specific types,
			// check the file extension.
			//
			if(m_dropMode.iMask & DL_FILTER_EXTENSION)
			{
				LPTSTR pszFileExt = PathFindExtension(csPathname);
				if(CString(pszFileExt).CompareNoCase(m_dropMode.csFileExt) == 0)
				{
					bValid = TRUE;
				}
			}
			else
			{
				bValid = TRUE;
			}
		}
	}

	return bValid;
}


//////////////////////////////////////////////////////////////////
//
//	InsertPathname()
//
//	This is used to insert a dropped item when a callback function
//	hasn't been specified.
//
//	It also checks if duplicate files are allowed to be inserted
//	and does the necessary.
//

int CDragDropListCtrl::InsertPathname(const CString& csFilename)
{

	LPWSTR JustfileName;

	JustfileName = (LPWSTR) PathFindFileName(csFilename);

	if(!(m_dropMode.iMask & DL_ALLOW_DUPLICATES))
	{
		//
		// We don't allow duplicate pathnames, so
		// see if this one is already in the list.
		//
		LVFINDINFO lvInfo;
		lvInfo.flags = LVFI_STRING;
		lvInfo.psz = JustfileName;

		if(FindItem(&lvInfo, -1) != -1)
			return -1;
	}

	return InsertItem(0, JustfileName);
}

/*************************** STUFF For Edit Box ***********************************************************/

CInPlaceEdit* CDragDropListCtrl::ShowInPlaceEdit(int iRowIndex, int iColumnIndex, CString& rstrCurSelection)
{
	// Create an in-place edit control
	CInPlaceEdit* pInPlaceEdit = CInPlaceEdit::GetInstance();
		
	CRect obCellRect(0, 0, 0, 0);
	CalculateCellRect(iColumnIndex, iRowIndex, obCellRect);
			
	pInPlaceEdit->ShowEditCtrl(m_dwEditCtrlStyle, obCellRect, this, 0, 
							   iRowIndex, iColumnIndex,
							   (CString) TEXT(""), rstrCurSelection);

	return pInPlaceEdit;
}

CInPlaceCombo* CDragDropListCtrl::ShowInPlaceList(int iRowIndex, int iColumnIndex, CStringList& rComboItemsList, 
											   CString strCurSelecetion /*= ""*/, int iSel /*= -1*/)
{
	// The returned obPointer should not be saved
	
	// Make sure that the item is visible
	if (!EnsureVisible(iRowIndex, TRUE))
	{
		return NULL;
	}

	// Make sure that iColumnIndex is valid 
	CHeaderCtrl* pHeader = static_cast<CHeaderCtrl*> (GetDlgItem(FIRST_COLUMN));

	int iColumnCount = pHeader->GetItemCount();

	if (iColumnIndex >= iColumnCount || GetColumnWidth(iColumnIndex) < MIN_COLUMN_WIDTH) 
	{
		return NULL;
	}

	// Calculate the rectangle specifications for the combo box
	CRect obCellRect(0, 0, 0, 0);
	CalculateCellRect(iColumnIndex, iRowIndex, obCellRect);

	int iHeight = obCellRect.Height();  
	int iCount = rComboItemsList.GetCount();

	iCount = (iCount < MAX_DROP_DOWN_ITEM_COUNT) ? 
		iCount + MAX_DROP_DOWN_ITEM_COUNT : (MAX_DROP_DOWN_ITEM_COUNT + 1); 

	obCellRect.bottom += iHeight * iCount; 

	// Create the in place combobox
	CInPlaceCombo* pInPlaceCombo = CInPlaceCombo::GetInstance();
	pInPlaceCombo->ShowComboCtrl(m_dwDropDownCtrlStyle, obCellRect, this, 0, iRowIndex, iColumnIndex, &rComboItemsList, 
								 strCurSelecetion, iSel);
	
	return pInPlaceCombo;
}


void CDragDropListCtrl::CalculateCellRect(int iColumnIndex, int iRowIndex, CRect& robCellRect)
{
	GetItemRect(iRowIndex, &robCellRect, LVIR_BOUNDS);
	
	CRect rcClient;
	GetClientRect(&rcClient);

	if (robCellRect.right > rcClient.right) 
	{
		robCellRect.right = rcClient.right;
	}

	ScrollToView(iColumnIndex, robCellRect); 
}

void CDragDropListCtrl::ScrollToView(int iColumnIndex, /*int iOffSet, */CRect& robCellRect)
{
	// Now scroll if we need to expose the column
	CRect rcClient;
	GetClientRect(&rcClient);

	int iColumnWidth = GetColumnWidth(iColumnIndex);

	// Get the column iOffset
	int iOffSet = 0;
	for (int iIndex_ = 0; iIndex_ < iColumnIndex; iIndex_++)
	{
		iOffSet += GetColumnWidth(iIndex_);
	}

	// If x1 of cell rect is < x1 of ctrl rect or
	// If x1 of cell rect is > x1 of ctrl rect or **Should not ideally happen**
	// If the width of the cell extends beyond x2 of ctrl rect then
	// Scroll

	CSize obScrollSize(0, 0);

	if (((iOffSet + robCellRect.left) < rcClient.left) || 
		((iOffSet + robCellRect.left) > rcClient.right))
	{
		obScrollSize.cx = iOffSet + robCellRect.left;
	}
	else if ((iOffSet + robCellRect.left + iColumnWidth) > rcClient.right)
	{
		obScrollSize.cx = iOffSet + robCellRect.left + iColumnWidth - rcClient.right;
	}

	Scroll(obScrollSize);
	robCellRect.left -= obScrollSize.cx;
	
	// Set the width to the column width
	robCellRect.left += iOffSet;
	robCellRect.right = robCellRect.left + iColumnWidth;
}


void CDragDropListCtrl::SetValidEditCtrlCharacters(CString &rstrValidCharacters)
{
	m_strValidEditCtrlChars = rstrValidCharacters;
}

void CDragDropListCtrl::SetComboColumns(int iColumnIndex, bool bSet /*= true*/)
{
	// If the Column Index is not present && Set flag is false
	// Then do nothing 
	// If the Column Index is present && Set flag is true
	// Then do nothing
	POSITION Pos = m_ComboSupportColumnsList.Find(iColumnIndex);

	// If the Column Index is not present && Set flag is true
	// Then Add to list
	if ((NULL == Pos) && bSet) 
	{
		m_ComboSupportColumnsList.AddTail(iColumnIndex); 
	}

	// If the Column Index is present && Set flag is false
	// Then Remove from list
	if ((NULL != Pos) && !bSet) 
	{
		m_ComboSupportColumnsList.RemoveAt(Pos); 
	}
}

void CDragDropListCtrl::SetReadOnlyColumns(int iColumnIndex, bool bSet /*= true*/)
{
	// If the Column Index is not present && Set flag is false
	// Then do nothing 
	// If the Column Index is present && Set flag is true
	// Then do nothing
	POSITION Pos = m_ReadOnlyColumnsList.Find(iColumnIndex);

	// If the Column Index is not present && Set flag is true
	// Then Add to list
	if ((NULL == Pos) && bSet) 
	{
		m_ReadOnlyColumnsList.AddTail(iColumnIndex); 
	}

	// If the Column Index is present && Set flag is false
	// Then Remove from list
	if ((NULL != Pos) && !bSet) 
	{
		m_ReadOnlyColumnsList.RemoveAt(Pos); 
	}
}

bool CDragDropListCtrl::IsReadOnly(int iColumnIndex)
{
	if (m_ReadOnlyColumnsList.Find(iColumnIndex))
	{
		return true;
	}
	
	return false;
}

bool CDragDropListCtrl::IsCombo(int iColumnIndex)
{
	if (m_ComboSupportColumnsList.Find(iColumnIndex))
	{
		return true;
	}

	return false;
}