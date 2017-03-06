
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

	DDX_Control(pDX, IDC_CHARTCTRL, m_ChartCtrl);
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

	//exam01. 17.03.06
/*
	// Disable the refresh of the control (avoid multiple refresh).
	m_ChartCtrl.EnableRefresh(false);
	// Create a bottom and left axes
	CChartStandardAxis* pBottomAxis =
		m_ChartCtrl.CreateStandardAxis(CChartCtrl::BottomAxis);
	CChartStandardAxis* pLeftAxis =
		m_ChartCtrl.CreateStandardAxis(CChartCtrl::LeftAxis);
	// Sets the min and max values of the bottom and left axis to -15 -> 15
	pBottomAxis->SetMinMax(-15,15);
	pLeftAxis->SetMinMax(-15,15);

	// Add a new series of type line to the control and add data to it
	CChartLineSerie* pLineSeries = m_ChartCtrl.CreateLineSerie();
	// Specifies that the points in the series are not ordered (needed to be able
	// to draw an ellipse).
	pLineSeries->SetSeriesOrdering(poNoOrdering);
	for (int i=0;i<361;i++)
	{
		double X = 10 * sin(i/360.0 * 2 * 3.141592);
		double Y = 10 * cos( (i-60)/360.0 * 2 * 3.141592);

		pLineSeries->AddPoint(X,Y);
	}

	// Defines the different colors (back color, axes color, ...)
	COLORREF BackColor = RGB(0,50,0);
	COLORREF GridColor = RGB(0,180,0);
	COLORREF TextColor = RGB(0,180,0);
	COLORREF SerieColor = RGB(0,255,0);

	// Specifies a sunken border for the control
	m_ChartCtrl.SetEdgeType(EDGE_SUNKEN);

	// Sets the color of the border and the back color
	m_ChartCtrl.SetBorderColor(TextColor);
	m_ChartCtrl.SetBackColor(BackColor);

	//Sets the color of the different elements of the bottom axis
	m_ChartCtrl.GetBottomAxis()->SetAxisColor(TextColor);
	m_ChartCtrl.GetBottomAxis()->SetTextColor(TextColor);
	m_ChartCtrl.GetBottomAxis()->GetGrid()->SetColor(GridColor);

	// Sets the color of the different elements of the left axis
	m_ChartCtrl.GetLeftAxis()->SetAxisColor(TextColor);
	m_ChartCtrl.GetLeftAxis()->SetTextColor(TextColor);
	m_ChartCtrl.GetLeftAxis()->GetGrid()->SetColor(GridColor);

	// Sets the color of the title, change the font to Times New Roman
	// and add a string
	m_ChartCtrl.GetTitle()->SetColor(TextColor);
	m_ChartCtrl.GetTitle()->SetFont(140,_T("Times New Roman"));
	m_ChartCtrl.GetTitle()->AddString(_T("An example of oscilloscope"));

	// Change the color of the line series
	pLineSeries->SetColor(SerieColor);

	// Finally re-enable the refresh of the control. This will refresh the
	// control if any refresh was still 'pending'.
	m_ChartCtrl.EnableRefresh(true);
*/

	srand((unsigned int)time(NULL));

	// Disable the refresh
	m_ChartCtrl.EnableRefresh(false);
	//COleDateTime Min(2008,1,1,0,0,0);
	//COleDateTime Max(2008,12,1,0,0,0);

	// Create the bottom axis and configure it properly
//	CChartDateTimeAxis* pBottomAxis =m_ChartCtrl.CreateDateTimeAxis(CChartCtrl::BottomAxis);
	CChartStandardAxis* pBottomAxis =m_ChartCtrl.CreateStandardAxis(CChartCtrl::BottomAxis);
		
	//pBottomAxis->SetMinMax(Min,Max);
	pBottomAxis->SetMinMax(0,100);
	pBottomAxis->SetDiscrete(true);
	//pBottomAxis->SetTickIncrement(false,CChartDateTimeAxis::tiMonth,1);
	pBottomAxis->SetTickIncrement(false, 10);
	//pBottomAxis->SetTickLabelFormat(false,_T("%b"));
	pBottomAxis->GetLabel()->SetText(_T("X"));
	// Create the left axis and configure it properly
	CChartStandardAxis* pLeftAxis =
		m_ChartCtrl.CreateStandardAxis(CChartCtrl::LeftAxis);
	pLeftAxis->SetMinMax(0,100);
	pLeftAxis->GetLabel()->SetText(_T("Y"));
	
	
	/*// Create the right axis and configure it properly
	CChartStandardAxis* pRightAxis =
		m_ChartCtrl.CreateStandardAxis(CChartCtrl::RightAxis);
	pRightAxis->SetVisible(true);
	pRightAxis->GetLabel()->SetText(_T("Income (kEuros)"));
	pRightAxis->SetMinMax(0,200);
*/


	// Configure the legend
	m_ChartCtrl.GetLegend()->SetVisible(false);
	m_ChartCtrl.GetLegend()->SetHorizontalMode(true);
	m_ChartCtrl.GetLegend()->UndockLegend(80,50);
	// Add text to the title and set the font & color
	m_ChartCtrl.GetTitle()->AddString(_T("Mappers Chart Test"));
	CChartFont titleFont;
	titleFont.SetFont(_T("Arial Black"),120,false,false,true);
	m_ChartCtrl.GetTitle()->SetFont(titleFont);
	m_ChartCtrl.GetTitle()->SetColor(RGB(0,0,128));

	// Sets a gradient background
	//m_ChartCtrl.SetBackGradient(RGB(255,255,255),RGB(150,150,255),gtVertical);

	// Create two bar series and a line series and populate them with data
	CChartBarSerie* pBarSeries1 = m_ChartCtrl.CreateBarSerie();
	CChartBarSerie* pBarSeries2 = m_ChartCtrl.CreateBarSerie();
	//CChartLineSerie* pLineSeries = m_ChartCtrl.CreateLineSerie(false,true);
	int lowIndex = -1;
	int lowVal = 999;
	for (int i=0;i<100;i+=10)
	{
		//COleDateTime TimeVal(2008,i+1,1,0,0,0);
		int DesktopVal = 20 + rand()%(100-30);
		//pBarSeries1->AddPoint(TimeVal,DesktopVal);
		pBarSeries1->AddPoint(i+1,DesktopVal);

		int LaptopVal = 10 + rand()%(80-20);
		//pBarSeries2->AddPoint(TimeVal,LaptopVal);
		pBarSeries2->AddPoint(i+1,LaptopVal);

		/*
		int Income = DesktopVal + LaptopVal*1.5;
		if (Income < lowVal)
		{
			lowVal = Income;
			lowIndex = i;
		}
		pLineSeries->AddPoint(TimeVal,Income);
		*/
	}
	// Configure the series properly
	pBarSeries1->SetColor(RGB(255,0,0));
	pBarSeries1->SetName(_T("first"));
	pBarSeries1->SetBarWidth(10);


	pBarSeries2->SetColor(RGB(68,68,255));
	pBarSeries2->SetInterSpace(0);
	pBarSeries2->SetBarWidth(10);
	////바 차트 내부 패턴 넣기	
	//pBarSeries2->SetGradient(RGB(200,200,255),gtVerticalDouble);

	pBarSeries2->SetName(_T("second"));
	//경계 넣기
	//pBarSeries2->SetBorderColor(RGB(0,0,255));
	//pBarSeries2->SetBorderWidth(3);

	/*pLineSeries->SetColor(RGB(0,180,0));
	pLineSeries->SetName(_T("Total income"));
	pLineSeries->SetWidth(2);
	pLineSeries->EnableShadow(true);
*/
	// Add a label on the line series.
	/*TChartStringStream labelStream;
	labelStream << _T("Min income: ") << lowVal;
	CChartBalloonLabel<SChartXYPoint>* pLabel =
		pLineSeries->CreateBalloonLabel(lowIndex, labelStream.str() + _T(" kEuros"));
	CChartFont labelFont;
	labelFont.SetFont(_T("Microsoft Sans Serif"),100,false,true,false);
	pLabel->SetFont(labelFont);*/

	// Re enable the refresh
	m_ChartCtrl.EnableRefresh(true);
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
