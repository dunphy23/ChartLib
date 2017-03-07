#pragma once
#include "FirstChart.h"
#include "ConcreteVisitor.h"
#include "Chart.h"

class ChartManager
{
public:
	ChartManager(void);
	~ChartManager(void);

	CChartCtrl m_ChartCtrl;
	void Draw();
	void TempFunc();
	//Chart m_chart;
};
