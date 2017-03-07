#pragma once
#include "Chart.h"
class FirstChart : public Chart
{
public:
	FirstChart();
	virtual ~FirstChart();
	virtual void Accept(Visitor*)override;
	virtual void OperationA();
	virtual void Draw(CDC* pDC) override;
};