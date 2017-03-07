
// chartLibDlg.cpp : implementation file
//

#include "stdafx.h"
#include "chartLib.h"
#include "chartLibDlg.h"




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


// CchartLibDlg dialog




CchartLibDlg::CchartLibDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CchartLibDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CchartLibDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//DDX_Control(pDX, IDC_CHARTCTRL, m_ChartCtrl);
	DDX_Control(pDX, IDC_CHARTCTRL, m_ChartMgr.m_ChartCtrl);
}

BEGIN_MESSAGE_MAP(CchartLibDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CchartLibDlg message handlers

BOOL CchartLibDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	m_ChartMgr.TempFunc();

	m_ChartMgr.Draw();
	//FirstChart* firstChart = new FirstChart();
	//firstChart->Draw();

	/*CDC* pDC = GetDC();

	CRect rect;
	GetClientRect(rect);

	//�޸� DC�� BITMAP ����
	CDC MemDC;
	CBitmap* pOldBitmap;
	CBitmap bmp;

	//�޸� DC �� BITMAP�� ���� DC ���� ��ġ��Ű��
	MemDC.CreateCompatibleDC(pDC);
	bmp.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	pOldBitmap = (CBitmap*)MemDC.SelectObject(&bmp);
	MemDC.PatBlt(0, 0, rect.Width(), rect.Height(), WHITENESS);

	//�޸� DC�� �׸���
	//!! TODO MemDC Here
	//ex) DrawImage(&MemDC);

	//17.03.06 ������ ���� �׽�Ʈ
	
	FirstChart* firstChart = new FirstChart();
	firstChart->Draw(&MemDC);

	//�۾� ���� ��, �޸� DC�� ���� DC�� ����
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &MemDC, 0, 0, SRCCOPY);

	//���� �޸� DC �� BITMAP ����
	MemDC.SelectObject(pOldBitmap);
	MemDC.DeleteDC();


*/

	/*Visitor* v1 = new ConcreteVisitor();
	Chart* eA = new FirstChart();

	eA->Accept(v1);
*/

	//17.2.22
	/*
	CRect rect;
	//Get size and position of the picture control
	GetDlgItem(IDC_OPENGL)->GetWindowRect(rect);
	//Convert screen coordinates to client coordinates
	ScreenToClient(rect);
	//create opengl control window
	m_oglWindow.oglCreate(rect, this);
	//setup the openGL window's timer to render
	m_oglWindow.m_unpTimer = m_oglWindow.SetTimer(1, 1, 0);
	*/


	//todo

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CchartLibDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CchartLibDlg::OnPaint()
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
HCURSOR CchartLibDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CchartLibDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//printf("dlg move\n");
	CDialog::OnMouseMove(nFlags, point);
}
