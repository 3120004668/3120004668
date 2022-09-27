#include "Arithmetic2.h"

Arithmetic2::Arithmetic2(RatNum e11, int sign11, RatNum e21, int sign21,
	RatNum e31, int Brackets1) {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
	e1 = e11;
	e2 = e21;
	e3 = e31;
	sign1 = sign11;
	sign2 = sign21;
	Brackets = Brackets1;
	success = true;
	if (Brackets == 0) {
		ans = calculate(calculate(e1, sign1, e2), sign2, e3);
		if (!calculate(e1, sign1, e2).InRange(10000)|| !ans.InRange(10000)) {
			success = false;
		}
	}
	else if (Brackets == 1) {
		ans = calculate(e1, sign1, calculate(e2, sign2, e3));
		if (!calculate(e2, sign2, e3).InRange(10000)||!ans.InRange(10000)) {
			success = false;
		}
	}
}

Arithmetic2::Arithmetic2(string exp) {
	size_t p1, p2;
	p1 = FindSizeRear(exp, 0);
	p2 = FindSizeRear(exp, p1);
	RatNum e11(getFirstRatNum(exp, 0)); e1 = e11;
	int sign11 = getFirstSign(exp, 0); sign1 = sign11;
	RatNum e21(getFirstRatNum(exp, p1)); e2 = e21;
	int sign21 = getFirstSign(exp, p1); sign2 = sign21;
	RatNum e31(getFirstRatNum(exp, p2)); e3 = e31;
	if (ExistsLeftBracket(getFirstRatNum(exp, 0)) && ExistsRightBracket(getFirstRatNum(exp, p1))) {
		Brackets = 0;
	}
	else if (ExistsLeftBracket(getFirstRatNum(exp, p1)) && ExistsRightBracket(getFirstRatNum(exp, p2))) {
		Brackets = 1;
	}
	else {
		if (!Priority(sign1) && Priority(sign2)) {
			Brackets = 1;
		}
		else {
			Brackets = 0;
		}
	}
	success = true;
	if (Brackets == 0) {
		ans = calculate(calculate(e1, sign1, e2), sign2, e3);
		if (!calculate(e1, sign1, e2).InRange(10000) || !ans.InRange(10000)) {
			success = false;
		}
	}
	else if (Brackets == 1) {
		ans = calculate(e1, sign1, calculate(e2, sign2, e3));
		if (!calculate(e2, sign2, e3).InRange(10000) || !ans.InRange(10000)) {
			success = false;
		}
	}
}

string Arithmetic2::StringArithmetic() {
	string exp;
	if (Brackets == 0 && !Priority(sign1) && Priority(sign2)) {
		exp += "(";
	}
	exp += e1.StringRatNum();
	exp += Sign(sign1);
	if (Brackets == 1 && Priority(sign1) && !Priority(sign2)) {
		exp += "(";
	}
	if (Brackets == 1 && sign1 == DIV && Priority(sign2)) {
		exp += "(";
	}
	if (Brackets == 1 && sign1 == SUB && !Priority(sign2)) {
		exp += "(";
	}
	exp += e2.StringRatNum();
	if (Brackets == 0 && !Priority(sign1) && Priority(sign2)) {
		exp += ")";
	}
	exp += Sign(sign2);
	exp += e3.StringRatNum();
	if (Brackets == 1 && Priority(sign1) && !Priority(sign2)) {
		exp += ")";
	}
	if (Brackets == 1 && sign1 == DIV && Priority(sign2)) {
		exp += ")";
	}
	if (Brackets == 1 && sign1 == SUB && !Priority(sign2)) {
		exp += ")";
	}
	exp += " = ";
	return exp;
}