#pragma once
#include "RatNum.h"
#include <iostream>
#include "Function.h"
#include <string>

using namespace std;

class Arithmetic2 //�������ŵ���ʽ��
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
	//��ʼ����ʽ������𰸣�
	string StringArithmetic();
	//�����ʽ
};

