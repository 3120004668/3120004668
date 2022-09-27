#pragma once
#include "RatNum.h"
#include <iostream>
#include <string>

using namespace std;

const int SUM = 1, SUB = 2, MUL = 3, DIV = 4;
//�Ӽ��˳�

string Sign(int sign);
//����

bool Priority(int sign);
//���ȼ�

RatNum calculate(RatNum e1, int sign, RatNum e2);
//����

size_t FindSizeFront(string exp, size_t p);
//Ѱ�Ҵ�pλ�ÿ�ʼ����һ���������λ��

size_t FindSizeRear(string exp, size_t p);
//Ѱ�Ҵ�pλ�ÿ�ʼ����һ�����������ո��λ��

int getFirstSign(string exp, size_t p);
//�õ���pλ�ÿ�ʼ����һ�������������

int GetAmountSign(string exp);
//�õ������������

string getFirstRatNum(string exp, size_t p);
//�õ���pλ�ÿ�ʼ����һ�����������ַ���

bool ExistsLeftBracket(string exp);
//����ַ����Ƿ����������

bool ExistsRightBracket(string exp);
//����ַ����Ƿ����������