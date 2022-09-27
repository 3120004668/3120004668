#pragma once
#include "RatNum.h"
#include <iostream>
#include "Function.h"
#include <string>

using namespace std;

class Arithmetic2 //两个符号的算式类
{
private:
	RatNum e1;
	RatNum e2;
	RatNum e3;
	int sign1;
	int sign2;
	int Brackets;
public:
	RatNum ans;
	bool success;
	Arithmetic2(RatNum e11, int sign11, RatNum e21, int sign21,
		RatNum e31, int Brackets1);
	Arithmetic2(string exp);
	//初始化算式（算出答案）
	string StringArithmetic();
	//输出算式
};

