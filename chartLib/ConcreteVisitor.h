#pragma once
#include "visitor.h"

class ConcreteVisitor :public Visitor
{
public:
	ConcreteVisitor();
	virtual ~ConcreteVisitor();

	//visitChart ���� �����
	virtual void VisitChart(FirstChart*) override;
};