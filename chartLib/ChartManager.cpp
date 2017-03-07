#include "StdAfx.h"
#include "ChartManager.h"

ChartManager::ChartManager(void)
{
}

ChartManager::~ChartManager(void)
{
}

void ChartManager::TempFunc()
{
	printf("ChartManager func test\n");
}
void ChartManager::Draw()
{

	//exam01. 17.03.06
	srand((unsigned int)time(NULL));
	//m_ChartCtrl.SetDC(pDC);
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
}