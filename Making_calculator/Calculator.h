#pragma once
#include<iostream>
#include<vector>

using namespace std;

class Calculator
{
protected:
	float first_op;
public:
	float getOp() { return first_op; }
	
	static float result_num;
	virtual void arithmetic(float a, float b)=0;
	
};
