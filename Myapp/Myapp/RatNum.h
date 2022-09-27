#pragma once
#include <iostream>
#include <string>

using namespace std;

class RatNum								//有理数类
{
private:
	int intPart;
	int mol;
	int deno;
public:
	RatNum(int intPart1, int mol1, int deno1);	//初始化有理数
	RatNum();
	RatNum(string ratnum);
	string StringRatNum();					//有理数的表达
	RatNum SumRatNum(RatNum otherRatNum);	//两个有理数的加法
	RatNum SubRatNum(RatNum subtract);		//两个有理数的减法
	RatNum MultRatNum(RatNum otherRatNum);	//两个有理数的乘法
	RatNum DivRatNum(RatNum divisor);		//两个有理数的除法
	bool InRange(int threshold);			//判断是否在范围内
};

