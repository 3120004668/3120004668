#include "RatNum.h"

int LeastCommonDivisor(int a, int b) {//辗转相除法求最小公约数
	int r;
	while (b != 0)//当其中一个数为0，另一个数就是两数的最大公约数
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

RatNum::RatNum(int intPart1, int mol1, int deno1) {
	intPart = intPart1;
	//约分
	mol = mol1;
	deno = deno1;
	if (mol == 0 || deno == 0) {
		mol = 0;
		deno = 1;
		intPart = intPart;
	}
	else {
		int x = LeastCommonDivisor(mol, deno);
		//化真分数
		if (mol >= deno) {
			intPart += mol / deno;
			mol = mol % deno;
		}
		mol = mol / x;
		deno = deno / x;
	}
	
}
RatNum::RatNum()
{
}
RatNum::RatNum(string ratnum) {
	string::iterator it = ratnum.begin();
	int num1 = 0, num2 = 0;
	while (it != ratnum.end()) {//删除非数字字符
		if (*it == '\'') {
			num1++;
			it++;
		}
		else if (*it == '/') {
			num2++;
			it++;
		}
		else if ((*it < '0') || (*it > '9')) {
			it = ratnum.erase(it);
		}
		else { 
			it++;
		}
	}
	if (num1 > 1 || num2 > 1) {//存在多个/或者'直接判定为0
		intPart = 0;
		mol = 0;
		deno = 1;
	}
	else {
		string part;
		size_t pos1 = ratnum.find("'");
		size_t pos2 = ratnum.find("/");
		if (pos1 != ratnum.npos) {
			part = ratnum.substr(0, pos1);
			intPart = stoi(part);
			part = ratnum.substr(pos1 + 1, pos2 - pos1 - 1);
			mol = stoi(part);
			part = ratnum.substr(pos2 + 1, ratnum.length() - 1);
			deno = stoi(part);
		}
		else if (pos2 != ratnum.npos) {
			intPart = 0;
			part = ratnum.substr(0, pos2);
			mol = stoi(part);
			part = ratnum.substr(pos2 + 1, ratnum.length() - 1);
			deno = stoi(part);
		}
		else {
			intPart = stoi(ratnum);
			mol = 0;
			deno = 1;
		}
		if (mol == 0 || deno == 0) {
			mol = 0;
			deno = 1;
			intPart = intPart;
		}
		else {
			int x = LeastCommonDivisor(mol, deno);
			//化真分数
			if (mol >= deno) {
				intPart += mol / deno;
				mol = mol % deno;
			}
			mol = mol / x;
			deno = deno / x;
		}
	}
}
string RatNum::StringRatNum() {
	string num;
	string num1;
	int i = 0;
	if (intPart) {
		num1 = to_string(intPart);
		num += num1;
	}
	if (intPart && (deno > 1) &&mol) {
		num += "\'";
	}
	if (mol&&(deno>1)) {
		num1 = to_string(mol);
		num += num1;
		num += "/";
		i++;
		num1 = to_string(deno);
		num += num1;
	}
	if (mol == 0 && intPart == 0) {
		num += "0";
	}
	return num;
}

RatNum RatNum::SumRatNum(RatNum otherRatNum) {
	int mol1, mol2, deno1, deno2, mol, deno;
	mol1 = this->mol + this->deno * this->intPart;
	mol2 = otherRatNum.mol + otherRatNum.deno * otherRatNum.intPart;
	deno1 = this->deno;
	deno2 = otherRatNum.deno;
	int x = LeastCommonDivisor(deno1, deno2);
	deno = deno1 * deno2 / x;
	mol = mol1 * deno2 / x + mol2 * deno1 / x;
	RatNum res(0, mol, deno);
	return res;
}

RatNum RatNum::SubRatNum(RatNum subtract) {
	int mol1, mol2, deno1, deno2, mol, deno;
	mol1 = this->mol + this->deno * this->intPart;
	mol2 = subtract.mol + subtract.deno * subtract.intPart;
	deno1 = this->deno;
	deno2 = subtract.deno;
	int x = LeastCommonDivisor(deno1, deno2);
	deno = deno1 * deno2 / x;
	mol = mol1 * deno2 / x - mol2 * deno1 / x;
	RatNum res(0, mol, deno);
	return res;
}

RatNum RatNum::MultRatNum(RatNum otherRatNum) {
	int mol1, mol2, deno1, deno2, mol, deno;
	mol1 = this->mol + this->deno * this->intPart;
	mol2 = otherRatNum.mol + otherRatNum.deno * otherRatNum.intPart;
	deno1 = this->deno;
	deno2 = otherRatNum.deno;
	mol = mol1 * mol2;
	deno = deno1 * deno2;
	RatNum res(0, mol, deno);
	return res;
}

RatNum RatNum::DivRatNum(RatNum divisor){
	int mol1, mol2, deno1, deno2, mol, deno;
	mol1 = this->mol + this->deno * this->intPart;
	mol2 = divisor.mol + divisor.deno * divisor.intPart;
	deno1 = this->deno;
	deno2 = divisor.deno;
	mol = mol1 * deno2;
	deno = deno1 * mol2;
	RatNum res(0, mol, deno);
	return res;
}

bool RatNum::InRange(int threshold) {
	if (mol < threshold&&deno < threshold&&intPart < threshold&&mol >= 0 && deno>0 && intPart >= 0) {
		return true;
	}
	else {
		return false;
	}
}