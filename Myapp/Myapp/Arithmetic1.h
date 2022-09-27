#pragma once
#include "RatNum.h"
#include <iostream>
#include "Function.h"
#include <string>

using namespace std;

class Arithmetic1
{
private:
	RatNum e1;
	RatNum e2;
	int sign;
public:
	RatNum ans;
	bool success;
	Arithmetic1(RatNum e11, int sign1, RatNum e21);
	Arithmetic1(string exp);
	//初始化算式（算出答案）
	string StringArithmetic();
	//输出算式
};

