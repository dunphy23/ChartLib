#pragma once

#include "ChartCtrl.h"
#include "ChartLineSerie.h"
#include "ChartStandardAxis.h"
#include "ChartBarSerie.h"
#include "ChartAxisLabel.h"
class Visitor;

class Chart
{
public:	
	virtual ~Chart(){}
	virtual void Accept(Visitor*) = 0;
	virtual void Draw(CDC *pDC)=0;

	CChartCtrl m_ChartCtrl;
protected:
	Chart(){}
};