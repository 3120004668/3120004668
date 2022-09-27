#pragma once
#include <iostream>
#include <string>

using namespace std;

class RatNum								//��������
{
private:
	int intPart;
	int mol;
	int deno;
public:
	RatNum(int intPart1, int mol1, int deno1);	//��ʼ��������
	RatNum();
	RatNum(string ratnum);
	string StringRatNum();					//�������ı��
	RatNum SumRatNum(RatNum otherRatNum);	//�����������ļӷ�
	RatNum SubRatNum(RatNum subtract);		//�����������ļ���
	RatNum MultRatNum(RatNum otherRatNum);	//�����������ĳ˷�
	RatNum DivRatNum(RatNum divisor);		//�����������ĳ���
	bool InRange(int threshold);			//�ж��Ƿ��ڷ�Χ��
};

