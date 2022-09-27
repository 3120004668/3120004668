#include <iostream>
#include <ctime>
#include <fstream>
#include "RatNum.h"
#include "Arithmetic1.h"
#include "Arithmetic2.h"
#include "Arithmetic3.h"
#include "Function.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if (!strcmp(argv[1], "-n")) {
		int amount, range;
		amount = atoi(argv[2]);
		if (!strcmp(argv[3], "-r")) {
			range = atoi(argv[4]);
		}
		else {
			cout << "请按“-n 参数（题数） -r 参数（数值范围）”或者“-e 参数（题目文件名） -a 参数（答案文件名）”格式输入，参数应当输入大于0的纯数字或者带后缀文件名";
			return 0;
		}
		if (amount <= 0) {
			cout << "请按“-n 参数（题数） -r 参数（数值范围）”或者“-e 参数（题目文件名） -a 参数（答案文件名）”格式输入，参数应当输入大于0的纯数字或者带后缀文件名";
			return 0;
		}
		if (range <= 0) {
			cout << "请按“-n 参数（题数） -r 参数（数值范围）”或者“-e 参数（题目文件名） -a 参数（答案文件名）”格式输入，参数应当输入大于0的纯数字或者带后缀文件名";
			return 0;
		}
		int i = 0, choose;
		ofstream ofs1, ofs2;
		ofs1.open("Exercises.txt");
		ofs2.open("Answers.txt");
		srand(time(NULL));
		while (i < amount) {
			choose = rand() % 3 + 1;
			if (choose == 3) {//3个运算符
				RatNum e1(rand() % range, rand() % range, rand() % range + 1);
				RatNum e2(rand() % range, rand() % range, rand() % range + 1);
				RatNum e3(rand() % range, rand() % range, rand() % range + 1);
				RatNum e4(rand() % range, rand() % range, rand() % range + 1);
				int sign1, sign2, sign3, brackets;
				sign1 = rand() % 4 + 1;
				sign2 = rand() % 4 + 1;
				sign3 = rand() % 4 + 1;
				brackets = rand() % 5;
				Arithmetic3 exp(e1, sign1, e2, sign2, e3, sign3, e4, brackets);
				if (exp.ans.InRange(range) && exp.success) {
					string p1, p2;
					p1 += exp.StringArithmetic();
					p2 += exp.ans.StringRatNum();
					ofs1 << i + 1 << '.' << p1 << endl;
					ofs2 << i + 1 << '.' << p2 << endl;
					i++;
				}
			}
			else if (choose == 2) {//2个运算符
				RatNum e1(rand() % range, rand() % range, rand() % range + 1);
				RatNum e2(rand() % range, rand() % range, rand() % range + 1);
				RatNum e3(rand() % range, rand() % range, rand() % range + 1);
				int sign1, sign2, brackets;
				sign1 = rand() % 4 + 1;
				sign2 = rand() % 4 + 1;
				brackets = rand() % 2;
				Arithmetic2 exp(e1, sign1, e2, sign2, e3, brackets);
				if (exp.ans.InRange(range) && exp.success) {
					string p1, p2;
					p1 += exp.StringArithmetic();
					p2 += exp.ans.StringRatNum();
					ofs1 << i + 1 << '.' << p1 << endl;
					ofs2 << i + 1 << '.' << p2 << endl;
					i++;
				}
			}
			else if (choose == 1) {//1个运算符
				RatNum e1(rand() % range, rand() % 10, rand() % range + 1);
				RatNum e2(rand() % range, rand() % 10, rand() % range + 1);
				int sign;
				sign = rand() % 4 + 1;

				Arithmetic1 exp(e1, sign, e2);
				if (exp.ans.InRange(range) && exp.success) {
					string p1, p2;
					p1 += exp.StringArithmetic();
					p2 += exp.ans.StringRatNum();
					ofs1 << i + 1 << '.' << p1 << endl;
					ofs2 << i + 1 << '.' << p2 << endl;
					i++;
				}
			}

		}
		ofs1.close();
		ofs2.close();
	}
	else if (!strcmp(argv[1], "-e")) {
		if (strcmp(argv[3], "-a")) {
			cout << "请按“-n 参数（题数） -r 参数（数值范围）”或者“-e 参数（题目文件名） -a 参数（答案文件名）”格式输入，参数应当输入大于0的纯数字或者带后缀文件名";
			return 0;
		}
		ifstream exercises(argv[2], ios::in);
		if (!exercises.is_open()) {
			cout << "未成功打开题目文件";
			return 0;
		}
		ifstream answer(argv[4], ios::in);
		if (!answer.is_open()) {
			cout << "未成功打开答案文件";
			return 0;
		}
		string exp, ans;
		int i = 1;
		string correct, wrong;
		bool co = true, wr = true;
		int conum = 0, wrnum = 0;
		while (getline(exercises, exp) && getline(answer, ans)) {
			size_t p;
			p = exp.find(".");
			exp.erase(0, p+1);
			p = ans.find(".");
			ans.erase(0, p+1);
			if (GetAmountSign(exp) == 1) {
				Arithmetic1 exp1(exp);
//				cout << exp1.StringArithmetic() << " = " << exp1.ans.StringRatNum() << endl;
				if (!ans.compare(exp1.ans.StringRatNum())) {
					if (co) {
						correct += to_string(i);
						conum++;
						co = false;
					}
					else {
						correct += "," + to_string(i);
						conum++;
					}
				}
				else {
					if (wr) {
						wrong += to_string(i);
						wrnum++;
						wr = false;
					}
					else {
						wrong += "," + to_string(i);
						wrnum++;
					}
				}
				i++;
			}
			else if (GetAmountSign(exp) == 2) {
				Arithmetic2 exp1(exp);
//				cout << exp1.StringArithmetic() << " = " << exp1.ans.StringRatNum() << endl;
				if (!ans.compare(exp1.ans.StringRatNum())) {
					if (co) {
						correct += to_string(i);
						conum++;
						co = false;
					}
					else {
						correct += "," + to_string(i);
						conum++;
					}
				}
				else {
					if (wr) {
						wrong += to_string(i);
						wrnum++;
						wr = false;
					}
					else {
						wrong += "," + to_string(i);
						wrnum++;
					}
				}
				i++;
			}
			else if (GetAmountSign(exp) == 3) {
				Arithmetic3 exp1(exp);
//				cout << exp1.StringArithmetic()<<" = " << exp1.ans.StringRatNum() << endl;
				if (!ans.compare(exp1.ans.StringRatNum())) {
					if (co) {
						correct += to_string(i);
						conum++;
						co = false;
					}
					else {
						correct += "," + to_string(i);
						conum++;
					}
				}
				else {
					if (wr) {
						wrong += to_string(i);
						wrnum++;
						wr = false;
					}
					else {
						wrong += "," + to_string(i);
						wrnum++;
					}
				}
				i++;
			}
		}
		ofstream ofs;
		ofs.open("Grade.txt");
		ofs << "Correct:" << conum << "(" << correct << ")" << endl;
		ofs << "Wrong:" << wrnum << "(" << wrong << ")" << endl;
	}
	else {
		cout << "请按“-n 参数（题数） -r 参数（数值范围）”或者“-e 参数（题目文件名） -a 参数（答案文件名）”格式输入，参数应当输入大于0的纯数字或者带后缀文件名";
		return 0;
	}
}


