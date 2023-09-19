#pragma once
#include "Calculator.h"

class Addition :public Calculator
{
public:
	Addition();
	virtual void arithmetic(float a, float b);
};

