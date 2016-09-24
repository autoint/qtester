#if !defined(AFX_DRAGDROPLISTCTRL_H__17F6D56D_591C_4319_B0EB_9D6D9B45BC79__INCLUDED_)
#define AFX_DRAGDROPLISTCTRL_H__17F6D56D_591C_4319_B0EB_9D6D9B45BC79__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DragDropListCtrl.h : header file
//

class CInPlaceCombo;
class CInPlaceEdit;

// User define message 
// This message is posted to the parent
// The message can be handled to make the necessary validations, if any
#define WM_VALIDATE		WM_USER + 0x7FFD

// User define message 
// This message is posted to the parent
// The message should be handled to spcify the items to the added to the combo
#define WM_SET_ITEMS	WM_USER + 0x7FFC

/////////////////////////////////////////////////////////////////////////////
// CDragDropListCtrl window

class CDragDropListCtrl : public CListCtrl
{
protected:
	CDWordArray			m_anDragIndexes;
	int					m_nDropIndex;
	CImageList*			m_pDragImage;
	int					m_nPrevDropIndex;
	UINT				m_uPrevDropState;
	DWORD				m_dwStyle;

	enum EScrollDirection
	{
		scrollNull,
		scrollUp,
		scrollDown
	};
	EScrollDirection	m_ScrollDirection;
	UINT				m_uScrollTimer;

// Construction
public:
	CDragDropListCtrl();
	bool IsDragging() const { return m_pDragImage != NULL; }
	typedef HRESULT (CALLBACK FAR * LPFN_DROP_FILES_CALLBACK)(CListCtrl*, const CString&, const UINT&);

// Attributes
public:
	enum DLDropFlags
	{
		DL_ACCEPT_FILES =       0x01,	// Allow files to be dropped
		DL_ACCEPT_FOLDERS =		0x02,	// Allow folders to be droppped
		DL_ALLOW_DUPLICATES =	0x04,	// Allow a pathname to be dropped even if its already in the list (ignored if you specify a callback function)
		DL_FILTER_EXTENSION =	0x10,	// Only accept files with the specified extension. Specify in csFileExt
		DL_USE_CALLBACK =		0x20,	// Receive a callback for each item dropped, specified in pfnCallback (you have responsibility for inserting items into the list)

		DL_FOLDER_TYPE =		0x40,	// Returned to the callback function - indicating the type of path dropped
		DL_FILE_TYPE =			0x80
	};

	struct DROPLISTMODE { 
		UINT iMask;								// Specifies what type of items to accept - a combination of the above flags
		CString csFileExt;						// The file extension on which to filter. Use the format ".extension". Ignored unless DL_FILTER_EXTENSION is specified
		LPFN_DROP_FILES_CALLBACK pfnCallback;	// Address of your callback function. Ignored unless DL_USE_CALLBACK is specified
	}; 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDragDropListCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDragDropListCtrl();
		// Sets/Resets the column which support the in place combo box
	void SetComboColumns(int iColumnIndex, bool bSet = true);
	
	// Sets/Resets the column which support the in place edit control
	void SetReadOnlyColumns(int iColumnIndex, bool bSet = true);

	// Sets the valid characters for the edit ctrl
	void SetValidEditCtrlCharacters(CString& rstrValidCharacters);

protected:
	void DropItem();
	void RestorePrevDropItemState();
	void UpdateSelection(int nDropIndex);
	void SetScrollTimer(EScrollDirection ScrollDirection);
	void KillScrollTimer();
	int HitTestEx(CPoint &point, int *row, int *col);
	afx_msg void OnBeginLabelEdit(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void OnEndLabelEdit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClick(NMHDR* pNMHDR, LRESULT* pResult);
	CImageList* CreateDragImageEx(LPPOINT lpPoint);
	

	virtual int InsertPathname(const CString& csFilename);
	
// Generated message map functions
protected:
	CEdit m_Edit;
	//{{AFX_MSG(CDragDropListCtrl)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBeginDrag(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void CDragDropListCtrl::OnDropFiles(HDROP dropInfo);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
	DROPLISTMODE m_dropMode;
	int m_rowLocation, m_columnLocation;
	CString ExpandShortcut(CString& csFilename) const;
	BOOL ValidatePathname(const CString& csPathname, UINT& iPathType) const;
	CInPlaceEdit* ShowInPlaceEdit(int iRowIndex, int iColumnIndex, CString& rstrCurSelection);
	// Creates and displays the in place combo box
	CInPlaceCombo* ShowInPlaceList(int iRowIndex, int iColumnIndex, CStringList& rComboItemsList, CString strCurSelecetion, int iSel = -1);
	void CalculateCellRect(int iColumnIndex, int iRowIndex, CRect& robCellRect);
	void ScrollToView(int iColumnIndex, /*int iOffSet, */CRect& robCellRect);

	bool IsCombo(int iColumnIndex);

	// Checks whether column is read only
	bool IsReadOnly(int iColumnIndex);

	// Attributes
	
	// List of columns that support the in place combo box
	CList<int, int> m_ComboSupportColumnsList;

	// List of columns that are read only
	CList<int, int> m_ReadOnlyColumnsList;

	// Valid characters
	CString m_strValidEditCtrlChars;

	// The window style of the in place edit ctrl
	DWORD m_dwEditCtrlStyle;

	// The window style of the in place combo ctrl
	DWORD m_dwDropDownCtrlStyle;
	
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAGDROPLISTCTRL_H__17F6D56D_591C_4319_B0EB_9D6D9B45BC79__INCLUDED_)
