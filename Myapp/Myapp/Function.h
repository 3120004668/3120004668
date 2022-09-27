#pragma once
#include "RatNum.h"
#include <iostream>
#include <string>

using namespace std;

const int SUM = 1, SUB = 2, MUL = 3, DIV = 4;
//加减乘除

string Sign(int sign);
//符号

bool Priority(int sign);
//优先级

RatNum calculate(RatNum e1, int sign, RatNum e2);
//计算

size_t FindSizeFront(string exp, size_t p);
//寻找从p位置开始数第一个运算符的位置

size_t FindSizeRear(string exp, size_t p);
//寻找从p位置开始数第一个运算符后面空格的位置

int getFirstSign(string exp, size_t p);
//得到从p位置开始数第一个运算符的类型

int GetAmountSign(string exp);
//得到运算符的数量

string getFirstRatNum(string exp, size_t p);
//得到从p位置开始数第一个有理数的字符串

bool ExistsLeftBracket(string exp);
//检测字符串是否存在左括号

bool ExistsRightBracket(string exp);
//检测字符串是否存在右括号