#pragma once
#include "RatNum.h"
#include <iostream>
#include "Function.h"

using namespace std;

class Arithmetic3			//���������ʽ��
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
	//���ڼ��������Ƿ�������������10000����
	Arithmetic3(RatNum e11, int sign11, RatNum e21, int sign21,
		RatNum e31, int sign31, RatNum e41,
		int Brackets1);
	Arithmetic3(string exp);
	//��ʼ����ʽ������𰸣�
	string StringArithmetic();
	//�����ʽ
};

