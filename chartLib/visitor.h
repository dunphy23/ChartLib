#include "stdafx.h"

#pragma  once

//�߰����� ��Ʈ ���� �߰�
class FirstChart;


//
class Visitor
{
public:
	virtual ~Visitor(){}

	//visitChart ���� �����
	virtual void VisitChart(FirstChart* chart){};


	//
protected:
	Visitor(){}
};

