#include "Function.h"

string Sign(int sign) {
	switch (sign)
	{
	case SUM:
		return " + ";
		break;
	case SUB:
		return " - ";
		break;
	case MUL:
		return " ¡Á ";
		break;
	case DIV:
		return " ¡Â ";
		break;
	}
}
bool Priority(int sign) {
	if (sign == SUM || sign == SUB) {
		return false;
	}
	else {
		return true;
	}
}
RatNum calculate(RatNum e1, int sign, RatNum e2) {
	if (sign == SUM) {
		return e1.SumRatNum(e2);
	}
	if (sign == SUB) {
		return e1.SubRatNum(e2);
	}
	if (sign == MUL) {
		return e1.MultRatNum(e2);
	}
	if (sign == DIV) {
		return e1.DivRatNum(e2);
	}
}

size_t FindSizeFront(string exp, size_t p) {
	size_t pos, pos1, pos2, pos3, pos4;
	pos1 = exp.find("+", p);
	pos2 = exp.find("-", p);
	pos3 = exp.find("¡Á", p);
	pos4 = exp.find("¡Â", p);
	pos = pos1;
	if (pos > pos2) {
		pos = pos2;
	}
	if (pos > pos3) {
		pos = pos3;
	}
	if (pos > pos4) {
		pos = pos4;
	}
	return pos;
}

size_t FindSizeRear(string exp, size_t p) {
	return FindSizeFront(exp, p) + (Priority(getFirstSign(exp, p)) ? 2 : 1);
}

int getFirstSign(string exp, size_t p) {
	size_t pos, pos1, pos2, pos3, pos4;
	pos = FindSizeFront(exp, p);
	pos1 = exp.find("+", p);
	pos2 = exp.find("-", p);
	pos3 = exp.find("¡Á", p);
	pos4 = exp.find("¡Â", p);
	if (pos == pos1) return SUM;
	if (pos == pos2) return SUB;
	if (pos == pos3) return MUL;
	if (pos == pos4) return DIV;
}

int GetAmountSign(string exp) {
	size_t p,pos;
	p = FindSizeRear(exp, 0);
	pos = FindSizeFront(exp, p);
	if (pos == exp.npos) {
		return 1;
	}
	p = FindSizeRear(exp, p);
	pos = FindSizeFront(exp, p);
	if (pos == exp.npos) {
		return 2;
	}
	return 3;
}

string getFirstRatNum(string exp, size_t p) {
	size_t pos;
	pos = FindSizeFront(exp, p);
	return exp.substr(p, pos-p);
}

bool ExistsLeftBracket(string exp) {
	size_t pos = exp.find("(");
	if (pos != exp.npos) {
		return true;
	}
	else {
		return false;
	}
}

bool ExistsRightBracket(string exp) {
	size_t pos = exp.find(")");
	if (pos != exp.npos) {
		return true;
	}
	else {
		return false;
	}
}