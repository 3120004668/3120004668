#include "Arithmetic3.h"

Arithmetic3::Arithmetic3(RatNum e11, int sign11, RatNum e21, int sign21,
	RatNum e31, int sign31, RatNum e41,
	   int Brackets1) {
	e1 = e11;
	e2 = e21;
	e3 = e31;
	e4 = e41;
	sign1 = sign11;
	sign2 = sign21;
	sign3 = sign31;
	Brackets = Brackets1;
	success = true;
	if (Brackets == 0) {//·ûºÅ¼ÆËãË³Ðò1->2->3
		ans = calculate(calculate(calculate(e1, sign1, e2), sign2, e3), sign3, e4);
		if (!calculate(e1, sign1, e2).InRange(10000)
			|| !calculate(calculate(e1, sign1, e2), sign2, e3).InRange(10000) || !ans.InRange(10000)) {
			success = false;
		}
	}
	else if (Brackets == 1) {//·ûºÅ¼ÆËãË³Ðò1->3->2»òÕß3->1->2
		ans = calculate(calculate(e1, sign1, e2), sign2, calculate(e3, sign3, e4));
		if (!calculate(e3, sign3, e4).InRange(10000)
			|| !calculate(e1, sign1, e2).InRange(10000) || !ans.InRange(10000)) {
			success = false;
		}
	}
	else if (Brackets == 2) {//·ûºÅ¼ÆËãË³Ðò2->1->3
		ans = calculate(calculate(e1, sign1, calculate(e2, sign2, e3)), sign3, e4);
		if (!calculate(e2, sign2, e3).InRange(10000)
			|| !calculate(e1, sign1, calculate(e2, sign2, e3)).InRange(10000) || !ans.InRange(10000)) {
			success = false;
		}
	}
	else if (Brackets == 3) {//·ûºÅ¼ÆËãË³Ðò2->3->1
		ans = calculate(e1, sign1, calculate(calculate(e2, sign2, e3), sign3, e4));
		if (!calculate(e2, sign2, e3).InRange(10000)
			|| !calculate(calculate(e2, sign2, e3), sign3, e4).InRange(10000) || !ans.InRange(10000)) {
			success = false;
		}
	}
	else if (Brackets == 4) {//·ûºÅ¼ÆËãË³Ðò3->2->1
		ans = calculate(e1, sign1, calculate(e2, sign2, calculate(e3, sign3, e4)));
		if (!calculate(e3, sign3, e4).InRange(10000)
			|| !calculate(e2, sign2, calculate(e3, sign3, e4)).InRange(10000) || !ans.InRange(10000)) {
			success = false;
		}
	}
}

Arithmetic3::Arithmetic3(string exp) {
	size_t p1, p2, p3;
	p1 = FindSizeRear(exp, 0);
	p2 = FindSizeRear(exp, p1);
	p3 = FindSizeRear(exp, p2);
	RatNum e11(getFirstRatNum(exp, 0)); e1 = e11;
	int sign11 = getFirstSign(exp, 0); sign1 = sign11;
	RatNum e21(getFirstRatNum(exp, p1)); e2 = e21;
	int sign21 = getFirstSign(exp, p1); sign2 = sign21;
	RatNum e31(getFirstRatNum(exp, p2)); e3 = e31;
	int sign31 = getFirstSign(exp, p2); sign3 = sign31;
	RatNum e41(getFirstRatNum(exp, p3)); e4 = e41;
	//ÏÈÌÖÂÛ´æÔÚÁ½¸öÀ¨ºÅµÄ3ÔËËã·ûËãÊ½
	if (ExistsLeftBracket(getFirstRatNum(exp, 0)) && ExistsRightBracket(getFirstRatNum(exp, p1))
		&& ExistsRightBracket(getFirstRatNum(exp, p2))) {
		Brackets = 0;
	}
	else if (ExistsLeftBracket(getFirstRatNum(exp, 0)) && ExistsLeftBracket(getFirstRatNum(exp, p1))
		&& ExistsRightBracket(getFirstRatNum(exp, p2))) {
		Brackets = 2;
	}
	else if (ExistsLeftBracket(getFirstRatNum(exp, p1)) && ExistsLeftBracket(getFirstRatNum(exp, p2))
		&& ExistsRightBracket(getFirstRatNum(exp, p3))) {
		Brackets = 4;
	}
	else if (ExistsLeftBracket(getFirstRatNum(exp, p1)) && ExistsRightBracket(getFirstRatNum(exp, p2))
		&& ExistsRightBracket(getFirstRatNum(exp, p3))) {
		Brackets = 3;
	}
	else if (ExistsLeftBracket(getFirstRatNum(exp, 0)) && ExistsRightBracket(getFirstRatNum(exp, p1))
		&& ExistsLeftBracket(getFirstRatNum(exp, p2)) && ExistsRightBracket(getFirstRatNum(exp, p3))) {
		Brackets = 1;
	}
	//ÔÙÌÖÂÛ´æÔÚÒ»¸öÀ¨ºÅµÄÇé¿ö
	else if (ExistsLeftBracket(getFirstRatNum(exp, 0)) && ExistsRightBracket(getFirstRatNum(exp, p1))) {
		if (!Priority(sign2) && Priority(sign3)) {
			Brackets = 1;
		}
		else {
			Brackets = 0;
		}
	}
	else if(ExistsLeftBracket(getFirstRatNum(exp, 0)) && ExistsRightBracket(getFirstRatNum(exp, p2))){
		if (!Priority(sign1) && Priority(sign2)) {
			Brackets = 2;
		}
		else {
			Brackets = 0;
		}
	}
	else if (ExistsLeftBracket(getFirstRatNum(exp, p1)) && ExistsRightBracket(getFirstRatNum(exp, p2))) {
		if (!Priority(sign1) && Priority(sign3)) {
			Brackets =3;
		}
		else {
			Brackets = 2;
		}
	}
	else if (ExistsLeftBracket(getFirstRatNum(exp, p1)) && ExistsRightBracket(getFirstRatNum(exp, p3))) {
		if (!Priority(sign2) && Priority(sign3)) {
			Brackets = 4;
		}
		else {
			Brackets = 3;
		}
	}
	else if (ExistsLeftBracket(getFirstRatNum(exp, p2)) && ExistsRightBracket(getFirstRatNum(exp, p3))) {
		if (!Priority(sign1) && Priority(sign2)) {
			Brackets = 4;
		}
		else {
			Brackets = 1;
		}
	}
	//×îºóÌÖÂÛÃ»ÓÐÀ¨ºÅµÄÇé¿ö
	else {
		if (Priority(sign1) && !Priority(sign2) && Priority(sign3)) {
			Brackets = 1;
		}
		else if (!Priority(sign1) && !Priority(sign2) && Priority(sign3)) {
			Brackets = 1;
		}
		else if (!Priority(sign1) && Priority(sign2) && !Priority(sign3)) {
			Brackets = 2;
		}
		else if (!Priority(sign1) && Priority(sign2) && Priority(sign3)) {
			Brackets = 3;
		}
		else {
			Brackets = 0;
		}
	}
	success = true;
	if (Brackets == 0) {//·ûºÅ¼ÆËãË³Ðò1->2->3
		ans = calculate(calculate(calculate(e1, sign1, e2), sign2, e3), sign3, e4);
		if (!calculate(e1, sign1, e2).InRange(10000)
			|| !calculate(calculate(e1, sign1, e2), sign2, e3).InRange(10000) || !ans.InRange(10000)) {
			success = false;
		}
	}
	else if (Brackets == 1) {//·ûºÅ¼ÆËãË³Ðò1->3->2»òÕß3->1->2
		ans = calculate(calculate(e1, sign1, e2), sign2, calculate(e3, sign3, e4));
		if (!calculate(e3, sign3, e4).InRange(10000)
			|| !calculate(e1, sign1, e2).InRange(10000) || !ans.InRange(10000)) {
			success = false;
		}
	}
	else if (Brackets == 2) {//·ûºÅ¼ÆËãË³Ðò2->1->3
		ans = calculate(calculate(e1, sign1, calculate(e2, sign2, e3)), sign3, e4);
		if (!calculate(e2, sign2, e3).InRange(10000)
			|| !calculate(e1, sign1, calculate(e2, sign2, e3)).InRange(10000) || !ans.InRange(10000)) {
			success = false;
		}
	}
	else if (Brackets == 3) {//·ûºÅ¼ÆËãË³Ðò2->3->1
		ans = calculate(e1, sign1, calculate(calculate(e2, sign2, e3), sign3, e4));
		if (!calculate(e2, sign2, e3).InRange(10000)
			|| !calculate(calculate(e2, sign2, e3), sign3, e4).InRange(10000) || !ans.InRange(10000)) {
			success = false;
		}
	}
	else if (Brackets == 4) {//·ûºÅ¼ÆËãË³Ðò3->2->1
		ans = calculate(e1, sign1, calculate(e2, sign2, calculate(e3, sign3, e4)));
		if (!calculate(e3, sign3, e4).InRange(10000)
			|| !calculate(e2, sign2, calculate(e3, sign3, e4)).InRange(10000) || !ans.InRange(10000)) {
			success = false;
		}
	}
}

string Arithmetic3::StringArithmetic() {
	string exp;
	if (Brackets == 0 && !Priority(sign1) && Priority(sign2)) {
		exp += "(";
	}
	if (Brackets == 0 && !Priority(sign2) && Priority(sign3)) {
		exp += "(";
	}
	if (Brackets == 1 && !Priority(sign1) && Priority(sign2)) {
		exp += "(";
	}
	if (Brackets == 2 && !Priority(sign1) && Priority(sign3)) {
		exp += "(";
	}
	exp += e1.StringRatNum();
	exp += Sign(sign1);
	if (Brackets == 2 && Priority(sign1) && !Priority(sign2)) {
		exp += "(";
	}
	if (Brackets == 2 && sign1 == DIV && Priority(sign2)) {
		exp += "(";
	}
	if (Brackets == 2 && sign1 == SUB && !Priority(sign2)) {
		exp += "(";
	}
	if (Brackets == 3 && !Priority(sign2) && Priority(sign3)) {
		exp += "(";
	}
	if (Brackets == 3 && Priority(sign1) && !Priority(sign3)) {
		exp += "(";
	}
	if (Brackets == 3 && sign1 == DIV && Priority(sign3)) {
		exp += "(";
	}
	if (Brackets == 3 && sign1 == SUB && !Priority(sign3)) {
		exp += "(";
	}
	if (Brackets == 4 && Priority(sign1) && !Priority(sign2)) {
		exp += "(";
	}
	if (Brackets == 4 && sign1 == DIV && Priority(sign2)) {
		exp += "(";
	}
	if (Brackets == 4 && sign1 == SUB && !Priority(sign2)) {
		exp += "(";
	}
	exp += e2.StringRatNum();
	if (Brackets == 0 && !Priority(sign1) && Priority(sign2)) {
		exp += ")";
	}
	if (Brackets == 1 && !Priority(sign1) && Priority(sign2)) {
		exp += ")";
	}
	exp += Sign(sign2);
	if (Brackets == 1 && !Priority(sign3) && Priority(sign2)) {
		exp += "(";
	}
	if (Brackets == 1 && sign2 == DIV && Priority(sign3)) {
		exp += "(";
	}
	if (Brackets == 1 && sign2 == SUB && !Priority(sign3)) {
		exp += "(";
	}
	if (Brackets == 4 && Priority(sign2) && !Priority(sign3)) {
		exp += "(";
	}
	if (Brackets == 4 && sign2 == DIV && Priority(sign3)) {
		exp += "(";
	}
	if (Brackets == 4 && sign2 == SUB && !Priority(sign3)) {
		exp += "(";
	}
	exp += e3.StringRatNum();
	if (Brackets == 0 && !Priority(sign2) && Priority(sign3)) {
		exp += ")";
	}
	if (Brackets == 2 && !Priority(sign1) && Priority(sign3)) {
		exp += ")";
	}
	if (Brackets == 2 && Priority(sign1) && !Priority(sign2)) {
		exp += ")";
	}
	if (Brackets == 2 && sign1 == DIV && Priority(sign2)) {
		exp += ")";
	}
	if (Brackets == 2 && sign1 == SUB && !Priority(sign2)) {
		exp += ")";
	}
	if (Brackets == 3 && !Priority(sign2) && Priority(sign3)) {
		exp += ")";
	}
	exp += Sign(sign3);
	exp += e4.StringRatNum();
	if (Brackets == 1 && !Priority(sign3) && Priority(sign2)) {
		exp += ")";
	}
	if (Brackets == 1 && sign2 == DIV && Priority(sign3)) {
		exp += ")";
	}
	if (Brackets == 1 && sign2 == SUB && !Priority(sign3)) {
		exp += ")";
	}
	if (Brackets == 3 && Priority(sign1) && !Priority(sign3)) {
		exp += ")";
	}
	if (Brackets == 3 && sign1 == DIV && Priority(sign3)) {
		exp += ")";
	}
	if (Brackets == 3 && sign1 == SUB && !Priority(sign3)) {
		exp += ")";
	}
	if (Brackets == 4 && Priority(sign2) && !Priority(sign3)) {
		exp += ")";
	}
	if (Brackets == 4 && sign2 == DIV && Priority(sign3)) {
		exp += ")";
	}
	if (Brackets == 4 && sign2 == SUB && !Priority(sign3)) {
		exp += ")";
	}
	if (Brackets == 4 && Priority(sign1) && !Priority(sign2)) {
		exp += ")";
	}
	if (Brackets == 4 && sign1 == DIV && Priority(sign2)) {
		exp += ")";
	}
	if (Brackets == 4 && sign1 == SUB && !Priority(sign2)) {
		exp += ")";
	}
	exp += " = ";
	return exp;
}