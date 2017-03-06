#include "stdafx.h"

#pragma  once

//추가적인 차트 종류 추가
class FirstChart;


//
class Visitor
{
public:
	virtual ~Visitor(){}

	//visitChart 원형 선언부
	virtual void VisitChart(FirstChart* chart){};


	//
protected:
	Visitor(){}
};

