// Admin_ToolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Admin_Tool.h"
#include "Admin_ToolDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CAdmin_ToolDlg dialog




CAdmin_ToolDlg::CAdmin_ToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdmin_ToolDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAdmin_ToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FILE_LIST, m_ctlListCtrl);

	DDX_Control(pDX, IDC_CHECK1, m_ctlCheckBox[0]);
	DDX_Control(pDX, IDC_CHECK2, m_ctlCheckBox[1]);
	DDX_Control(pDX, IDC_CHECK3, m_ctlCheckBox[2]);
	DDX_Control(pDX, IDC_CHECK4, m_ctlCheckBox[3]);

	DDX_Control(pDX, IDC_EDIT1, m_ctlEditBox[0]);
	DDX_Control(pDX, IDC_EDIT2, m_ctlEditBox[1]);
	DDX_Control(pDX, IDC_EDIT3, m_ctlEditBox[2]);
	DDX_Control(pDX, IDC_EDIT4, m_ctlEditBox[3]);

	DDX_Control(pDX, IDC_EDIT5, m_ctlEditKeyBox[0]);
	DDX_Control(pDX, IDC_EDIT6, m_ctlEditKeyBox[1]);
	DDX_Control(pDX, IDC_EDIT7, m_ctlEditKeyBox[2]);
	DDX_Control(pDX, IDC_EDIT8, m_ctlEditKeyBox[3]);
}

BEGIN_MESSAGE_MAP(CAdmin_ToolDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON4, &CAdmin_ToolDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_OPEN, &CAdmin_ToolDlg::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_CHECK1, &CAdmin_ToolDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CAdmin_ToolDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CAdmin_ToolDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CAdmin_ToolDlg::OnBnClickedCheck4)
	ON_EN_CHANGE(IDC_EDIT5, &CAdmin_ToolDlg::OnEnChangeEdit5)
	ON_NOTIFY(NM_RCLICK, IDC_FILE_LIST, &CAdmin_ToolDlg::OnNMRclickFileList)
	ON_MESSAGE(WM_SET_ITEMS, PopulateComboList)
	ON_BN_CLICKED(IDC_BUTTON2, &CAdmin_ToolDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CAdmin_ToolDlg message handlers

BOOL CAdmin_ToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	for (int i=0; i < 4; i++)
	{
		m_ctlEditBox[i].SetWindowText(TEXT("Not a valid option"));
		m_ctlEditBox[i].SetWindowText(TEXT("Not a valid option"));
		m_ctlEditBox[i].SetWindowText(TEXT("Not a valid option"));
		m_ctlEditBox[i].SetWindowText(TEXT("Not a valid option"));
	}

	m_ctlListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_ctlListCtrl.InsertColumn(0, TEXT("File Name"), LVCFMT_LEFT, 100, -1);
	m_ctlListCtrl.InsertColumn(1, TEXT("Correct Option"), LVCFMT_LEFT, 150, -1);
	m_ctlListCtrl.SetComboColumns(1);

	Edit_Mode = false;
	Data_Saved = false;
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAdmin_ToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAdmin_ToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAdmin_ToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CAdmin_ToolDlg::OnBnClickedButton4()
{

	if ((Edit_Mode == true) && (Data_Saved == false))
	{
		if(AfxMessageBox(TEXT("Warning: If you continue, changes since your last save will be lost.\nDo you want to continue?"),MB_YESNO,0)==IDNO   )
		{
			return;
		}
	}

	OnFileOpen(CFile::modeCreate|CFile:: modeReadWrite);

	int nIndex = m_ctlListCtrl.GetItemCount();
	for(int i=0; i <= nIndex; i++)
	{
		m_ctlListCtrl.DeleteItem(0);
	}
	ThePlayList.RewindPlayList();


}

void CAdmin_ToolDlg::OnBnClickedOpen()
{
	if ((Edit_Mode == true) && (Data_Saved == false))
	{
		if(AfxMessageBox(TEXT("Warning: If you continue, changes since your last save will be lost.\nDo you want to continue?"),MB_YESNO,0)==IDNO   )
		{
			return;
		}
	}



	if (OnFileOpen(CFile::modeReadWrite) == false)
	{
		return;
	}
	else
	{
		UINT BufferSize = PlayListFile.GetLength();
		char* Buffer = (char *) malloc((size_t)BufferSize);
		int nIndex = m_ctlListCtrl.GetItemCount();

		for(int i=0; i <= nIndex; i++)
		{
			m_ctlListCtrl.DeleteItem(0);
		}

		PlayListFile.Read(Buffer, BufferSize);		
		ThePlayList.RewindPlayList();
		ThePlayList.ReadPlayList(Buffer, BufferSize);
		ThePlayList.NextItemOnPlayList(&PlayListItem);

		

		for(int i = 0; i < 4; i++)
		{
			if(PlayListItem.OptionCommand[i] == '*')
			{
				m_ctlCheckBox[i].SetCheck(0);
				m_ctlEditBox[i].SetWindowText(TEXT("Not a valid input"));
				m_ctlEditKeyBox[i].SetWindowText(TEXT(""));
			}
			else
			{
				CString TempStr, TempStr2;
				m_ctlCheckBox[i].SetCheck(1);
				TempStr2 = PlayListItem.OptionLabel[i];
				m_ctlEditBox[i].SetWindowText(TempStr2);
				TempStr.AppendChar(PlayListItem.OptionCommand[i]);
				m_ctlEditKeyBox[i].SetWindowText(TempStr);
			}
		}

		for(int itemNumber = 0; PlayListItem.Valid == true; itemNumber++)
		{
			CString TempStr; 
			int nIndex;
			TempStr = PlayListItem.FileToPlay;
			nIndex = m_ctlListCtrl.InsertItem(itemNumber, TempStr);
			m_ctlEditBox[PlayListItem.CorrectOptionNumber-1].GetLine(0,TempStr.GetBuffer(128), 128);
			m_ctlListCtrl.SetItemText(nIndex,1, TempStr);

			ThePlayList.NextItemOnPlayList(&PlayListItem);
		}
	}
}

bool CAdmin_ToolDlg::OnFileOpen(int OpenType) 
{

	// Create an Open dialog; the default file name extension is ".my".
   CFileDialog fileDlg (TRUE, TEXT("csv"), TEXT("*.csv"),
      OFN_HIDEREADONLY,  TEXT("QTester Files (*.csv)|*.csv|All Files (*.*)|*.*||"), this);
   
   // Display the file dialog. When user clicks OK, fileDlg.DoModal() 
   // returns IDOK.
   if( fileDlg.DoModal ()==IDOK )
   {
	  CFileException pError;
	  CString pathName = fileDlg.GetPathName();
	 
	  if (PlayListFile.m_hFile != CFile::hFileNull)
	  {
		  // Pop up error here..
		  PlayListFile.Close();
	  }
   
	  if (PlayListFile.Open(LPCTSTR (pathName), OpenType, &pError) == TRUE)
	  {  
		  Edit_Mode = true;
		  Data_Saved = false;
		  SetWindowText(pathName);
	  }
	  else
	  {
		  SetWindowText(TEXT("File Open Failed, please try again...."));
	  }
	  return true;
   }
   else
   {
	   return false;
   }
   

}



void CAdmin_ToolDlg::OnBnClickedCheck1()
{
	
	OnBnClickedCheck(0);
}

void CAdmin_ToolDlg::OnBnClickedCheck2()
{
	OnBnClickedCheck(1);
}

void CAdmin_ToolDlg::OnBnClickedCheck3()
{
	OnBnClickedCheck(2);
}

void CAdmin_ToolDlg::OnBnClickedCheck4()
{
	OnBnClickedCheck(3);
}

void CAdmin_ToolDlg::OnBnClickedCheck(int CheckItem)
{
	if (Edit_Mode == false)
	{
		AfxMessageBox(TEXT("Error: You must open or create a new file first."),0,0);
		return;
	}

	if (m_ctlCheckBox[CheckItem].GetCheck() == 1)
	{
		m_ctlEditBox[CheckItem].SetWindowText(TEXT(""));
		m_ctlEditKeyBox[CheckItem].SetWindowText(TEXT(""));
	}
	else
	{
		m_ctlEditBox[CheckItem].SetWindowText(TEXT("Not a valid input"));
		m_ctlEditKeyBox[CheckItem].SetWindowText(TEXT(""));
	}

}

void CAdmin_ToolDlg::OnEnChangeEdit5()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CAdmin_ToolDlg::OnNMRclickFileList(NMHDR *pNMHDR, LRESULT *pResult)
{
	CPoint point;
    GetCursorPos(&point);
	int returnitem = 0;
	int iItem = 0;

	if (Edit_Mode == false)
	{
		AfxMessageBox(TEXT("Error: You must open or create a new file first."),0,0);
		*pResult = 0;
		return;
	}

    CMenu mnuTop;
    mnuTop.LoadMenu(IDR_POP_UP_MENU1);

    CMenu* pPopup = mnuTop.GetSubMenu(0);
    ASSERT_VALID(pPopup);

    returnitem = pPopup->TrackPopupMenu(TPM_LEFTBUTTON | TPM_LEFTALIGN | TPM_RETURNCMD, 
		                    point.x, point.y, AfxGetMainWnd(), NULL);

	iItem = (int) m_ctlListCtrl.GetNextItem(-1, LVNI_SELECTED);
	switch (returnitem)
	{
		case ID_DELETECURRENTLINE:
		{
			if (iItem != -1)
			{
				m_ctlListCtrl.DeleteItem(iItem);
			}
		}
		break;
		case ID_ADDNEWLINE:
		{
			CString TempStr = TEXT("<FileName>");
			int nIndex;

			if (iItem == -1) /* Add to end */
			{
				nIndex = m_ctlListCtrl.GetItemCount();
				nIndex = m_ctlListCtrl.InsertItem(nIndex, TempStr);
				m_ctlListCtrl.SetItemText(nIndex,1, TEXT("<Key>"));
			}
			else
			{
				nIndex = m_ctlListCtrl.InsertItem(iItem+1, TempStr);
				m_ctlListCtrl.SetItemText(nIndex,1, TEXT("<Key>"));
			}

		}
		break;
		default:
		{
		}
		break;
	}
	*pResult = 0;
}

LRESULT CAdmin_ToolDlg::PopulateComboList(WPARAM wParam, LPARAM lParam)
{
	// Get the Combobox window pointer
	CComboBox* pInPlaceCombo = static_cast<CComboBox*> (GetFocus());

	// Get the inplace combbox top left
	CRect obWindowRect;

	pInPlaceCombo->GetWindowRect(&obWindowRect);
	
	CPoint obInPlaceComboTopLeft(obWindowRect.TopLeft()); 
	
	// Get the active list
	// Get the control window rect
	// If the inplace combobox top left is in the rect then
	// The control is the active control
	m_ctlListCtrl.GetWindowRect(&obWindowRect);
	
	int iColIndex = wParam;
	
	CStringList* pComboList = reinterpret_cast<CStringList*>(lParam);
	pComboList->RemoveAll(); 

	if (obWindowRect.PtInRect(obInPlaceComboTopLeft)) 
	{
		if (1 == iColIndex)
		{
			for (int i=0; i < 4; i++)
			{
				if (m_ctlCheckBox[i].GetCheck() == 1)
				{
					CString Line;
					m_ctlEditBox[i].GetLine(0, Line.GetBuffer(128), 128);
					pComboList->AddTail(Line);
				}
			}
		}
	}
	
	return true;
}

/* Save */
void CAdmin_ToolDlg::OnBnClickedButton2()
{
	int nIndex = m_ctlListCtrl.GetItemCount();
	PlayList::tPlayListItem item;
	char * writeBuffer = NULL;
	int sizeofBuffer = 0;

	ThePlayList.RewindPlayList();

	for (int i=0; i < 4; i++)
	{
		if (m_ctlCheckBox[i].GetCheck() == 1)
		{
			CString Line;
			size_t CharactersConverted = 0;
			char tmp[2] = "";
			
			m_ctlEditBox[i].GetLine(0, Line.GetBuffer(128), 128);
			wcstombs_s(&CharactersConverted, item.OptionLabel[i], MAX_LABEL_LENGTH, Line, _TRUNCATE);
			
			m_ctlEditKeyBox[i].GetLine(0, Line.GetBuffer(128), 128);
			wcstombs_s(&CharactersConverted, tmp, 2, Line, _TRUNCATE);
			item.OptionCommand[i] = tmp[0];
		}
	}

	for(int i=0; i < nIndex; i++)
	{
		CString mainItem, subItem;
		size_t CharactersConverted = 0;
		char tmp[MAX_LABEL_LENGTH] = "";

		mainItem = m_ctlListCtrl.GetItemText(i,0);
		wcstombs_s(&CharactersConverted, item.FileToPlay, MAX_PATH_LENGTH, mainItem, _TRUNCATE);

		subItem = m_ctlListCtrl.GetItemText(i,1);
		wcstombs_s(&CharactersConverted, tmp, MAX_LABEL_LENGTH, subItem, _TRUNCATE);

		if (strcmp(tmp, item.OptionLabel[0])==0)
		{
			item.CorrectOptionNumber = (char) 1;
		}
		else if (strcmp(tmp, item.OptionLabel[1])==0)
		{
			item.CorrectOptionNumber = (char) 2;
		}
		else if (strcmp(tmp, item.OptionLabel[2])==0)
		{
			item.CorrectOptionNumber = (char) 3;
		}
		else if (strcmp(tmp, item.OptionLabel[3])==0)
		{
			item.CorrectOptionNumber = (char) 4;
		}
		ThePlayList.AddItemOnPlayList(item);
	}

	writeBuffer = (char*) malloc((size_t)(sizeof(PlayList::tPlayListItem)*100));
	sizeofBuffer = ThePlayList.PrepareDumpFile(writeBuffer);

	PlayListFile.SeekToBegin();
	PlayListFile.Write(writeBuffer, sizeofBuffer);

	AfxMessageBox(TEXT("Success: You Playlist has been saved."),0,0);
	Data_Saved = true;
}
