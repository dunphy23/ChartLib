#include "stdafx.h"
#include "ConcreteVisitor.h"
#include "FirstChart.h"

ConcreteVisitor::ConcreteVisitor()
{

}
ConcreteVisitor::~ConcreteVisitor(){
}


//��Ʈ �湮 �޼ҵ� �߰�
void ConcreteVisitor::VisitChart(FirstChart* ele)
{
	ele->OperationA();
}