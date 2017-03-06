#pragma once
class Visitor;

class Chart
{
public:	
	virtual ~Chart(){}
	virtual void Accept(Visitor*) = 0;
	virtual void Draw()=0;
protected:
	Chart(){}
};