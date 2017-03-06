#pragma once
#include "visitor.h"

class ConcreteVisitor :public Visitor
{
public:
	ConcreteVisitor();
	virtual ~ConcreteVisitor();

	//visitChart 원형 선언부
	virtual void VisitChart(FirstChart*) override;
};