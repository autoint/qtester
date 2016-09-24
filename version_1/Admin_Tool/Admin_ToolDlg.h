// Admin_ToolDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "PlayList.h"
#include "afxwin.h"
#include <afxole.h>
#include "DragDropListCtrl.h"


// CAdmin_ToolDlg dialog
class CAdmin_ToolDlg : public CDialog
{
// Construction
public:
	CAdmin_ToolDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_ADMIN_TOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLvnItemchangedFileList(NMHDR *pNMHDR, LRESULT *pResult);
public:

public:
//	afx_msg void OnLvnInsertitemFileList(NMHDR *pNMHDR, LRESULT *pResult);
public:
	afx_msg void OnBnClickedButton4();
private:
	bool OnFileOpen(int OpenType);
	afx_msg void OnBnClickedOpen();

	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg LRESULT PopulateComboList(WPARAM wParam, LPARAM lParam);

	void OnBnClickedCheck(int CheckItem);

	CButton m_ctlCheckBox[4];
	CEdit m_ctlEditBox[4];
	CEdit m_ctlEditKeyBox[4];
	afx_msg void OnEnChangeEdit5();
	CDragDropListCtrl m_ctlListCtrl;

	CFile PlayListFile;
	PlayList ThePlayList;
	PlayList::tPlayListItem PlayListItem;
	afx_msg void OnNMRclickFileList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMLclickMenuDelete (int item_number);
	afx_msg void OnBnClickedButton2();
	bool Edit_Mode;
	bool Data_Saved;
};
