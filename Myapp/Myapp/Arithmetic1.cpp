#include "Arithmetic1.h"

Arithmetic1::Arithmetic1(RatNum e11, int sign1, RatNum e21) {//一个运算符的算式类
	e1 = e11;
	e2 = e21;
	sign = sign1;
	success = true;
	ans = calculate(e1, sign, e2);
	if (!ans.InRange(10000)) {
		success = false;
	}
}

Arithmetic1::Arithmetic1(string exp) {
	RatNum e11(getFirstRatNum(exp, 0));
	int sign1 = getFirstSign(exp, 0);
	RatNum e21(getFirstRatNum(exp, FindSizeRear(exp,0)));
	e1 = e11;
	e2 = e21;
	sign = sign1;
	success = true;
	ans = calculate(e1, sign, e2);
	if (!ans.InRange(10000)) {
		success = false;
	}
}

string Arithmetic1::StringArithmetic() {
	string exp;
	exp += e1.StringRatNum();
	exp += Sign(sign);
	exp += e2.StringRatNum();
	exp += " = ";
	return exp;
}