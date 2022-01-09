// TXTDlg.h : header file
//

#pragma once

// CTXTDlg dialog
class CTXTDlg : public CDialogEx
{
// Construction
public:
	CTXTDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TXT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	int c_line;
	int c_word;
	int c_letter;
	CString start_folder;
	
	// if true extension 
	BOOL check_cpp;
	BOOL check_txt;
	BOOL check_c;
public:
	afx_msg void OnBnClickedStart();
	void scan_begin(CString, BOOL flags[]);
	
	afx_msg void OnBnClickedCheckCpp();
	afx_msg void OnBnClickedCheckTxt();
	afx_msg void OnBnClickedCheckC();
};
