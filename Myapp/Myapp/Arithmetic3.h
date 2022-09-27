#pragma once
#include "RatNum.h"
#include <iostream>
#include "Function.h"

using namespace std;

class Arithmetic3			//三运算符算式类
{
private:
	RatNum e1;
	RatNum e2;
	RatNum e3;
	RatNum e4;
	int sign1;
	int sign2;
	int sign3;
	int Brackets;
public:
	RatNum ans;
	bool success;
	//用于检测过程中是否产生负数或大于10000的数
	Arithmetic3(RatNum e11, int sign11, RatNum e21, int sign21,
		RatNum e31, int sign31, RatNum e41,
		int Brackets1);
	Arithmetic3(string exp);
	//初始化算式（算出答案）
	string StringArithmetic();
	//输出算式
};

