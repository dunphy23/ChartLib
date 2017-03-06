#include "stdafx.h"
#include "ConcreteVisitor.h"
#include "FirstChart.h"

ConcreteVisitor::ConcreteVisitor()
{

}
ConcreteVisitor::~ConcreteVisitor(){
}


//차트 방문 메소드 추가
void ConcreteVisitor::VisitChart(FirstChart* ele)
{
	ele->OperationA();
}