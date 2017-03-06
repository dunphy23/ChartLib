#include "stdafx.h"
#include "FirstChart.h"
#include "visitor.h"

FirstChart::FirstChart()
{

}
FirstChart::~FirstChart()
{

}

void FirstChart::Accept(Visitor* v)
{
	v->VisitChart(this);

}
void FirstChart::OperationA()
{
	//FirstChart ±¸ÇöºÎ
	printf("visit ConcreteElement A\n");
}
void FirstChart::Draw()
{


}