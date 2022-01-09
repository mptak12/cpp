
// TXTDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "TXT.h"
#include "TXTDlg.h"
#include "afxdialogex.h"

#include "scanner.h"
#include "reader.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTXTDlg dialog



CTXTDlg::CTXTDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TXT_DIALOG, pParent)
	, c_line(0)
	, c_word(0)
	, c_letter(0)
	, start_folder(_T(""))
	, check_cpp(FALSE)
	, check_txt(FALSE)
	, check_c(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTXTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_C_LINE, c_line);
	DDX_Text(pDX, IDC_C_WORD, c_word);
	DDX_Text(pDX, IDC_C_LETTER, c_letter);
	DDX_Text(pDX, IDC_MFCEDITBROWSE1, start_folder);
	DDX_Check(pDX, IDC_CHECK_CPP, check_cpp);
	DDX_Check(pDX, IDC_CHECK_TXT, check_txt);
	DDX_Check(pDX, IDC_CHECK_C, check_c);
}

BEGIN_MESSAGE_MAP(CTXTDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CTXTDlg::OnBnClickedStart)

	ON_BN_CLICKED(IDC_CHECK_CPP, &CTXTDlg::OnBnClickedCheckCpp)
	ON_BN_CLICKED(IDC_CHECK_TXT, &CTXTDlg::OnBnClickedCheckTxt)
	ON_BN_CLICKED(IDC_CHECK_C, &CTXTDlg::OnBnClickedCheckC)
END_MESSAGE_MAP()


// CTXTDlg message handlers

BOOL CTXTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTXTDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTXTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTXTDlg::OnBnClickedStart()	//START button 
{
	UpdateData();
	CString str;
	str = (start_folder);

	BOOL flags[] = { check_cpp,check_txt, check_c };	//variables from check-boxes

	if (str.GetLength() < 3)
		AfxMessageBox(_T("Select another path"));
	else {
		
		scan_begin(str, flags);
		UpdateData(FALSE);

		AfxMessageBox(L"Done", MB_OK | MB_ICONASTERISK);
	}
}


void CTXTDlg::scan_begin(CString s_f, BOOL flags[])
{
	/// <summary>
	/// start parameters: catalog, where scan begins & extensions
	/// initialize other classes
	/// updates MFC variables with variables from classes
	
	std::wstring a(s_f.GetString()); //CString -> wstring conversion

	reader* files = new reader(a, flags);
	files->read();				//looking for files
	vect fil_p = files->get_paths(); //get files' paths

	//SCANNER
	scanner* analyze = new scanner(fil_p);
	analyze->summ();		//looking for words,lines and letters

	//update variables
	c_letter = analyze->get_letters();	
	c_word = analyze->get_words();
	c_line = analyze->get_lines();
}


void CTXTDlg::OnBnClickedCheckCpp()
{
	check_cpp = !check_cpp;	//if clicked switch false -> true
}


void CTXTDlg::OnBnClickedCheckTxt()
{
	check_txt = !check_txt;
}

void CTXTDlg::OnBnClickedCheckC()
{
	check_c = !check_c;
}
