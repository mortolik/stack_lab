#pragma once
#include <string>
#include <cmath>
#include <string.h>
#include "TStack.h"
using namespace ListStack;
//using namespace ArrayStack;
using namespace std;

class TCalculator
{
	TStack<char> c;
	TStack<double> d;
	string inf;
	int prioritet(char op)
			{
				if (op == '(' || op == ')')
					return 0;
				if (op == '+' || op == '-')
					return 1;
				if (op == '*' || op == '/')
					return 2;
				if (op == '^')
					return 3;
			}
	//void CurrIndostfix();
	public:
		TCalculator(string& str) :inf(str) { /*CurrIndostfix();*/ };
		bool expression();
		void set_infix(string str);
		string get_infix();
		double calc();
};

//class TCalculator
//{
//	string  inf,postf;
//	TStack<char> c=TStack<char>(10);
//	TStack<double> d = TStack<double>(10);
//
//	int prioritet(char op)
//	{
//		if (op == '(' || op == ')')
//			return 0;
//		if (op == '+' || op == '-')
//			return 1;
//		if (op == '*' || op == '/')
//			return 2;
//		if (op == '^')
//			return 3;
//	}
//	void CurrIndostfix();
//public:
//	TCalculator(string& str) :inf(str) { CurrIndostfix(); };
//	bool expression();
//	void set_infix(string str);
//	string get_postfix();
//	string get_infix();
//	double CalcPostfix();
//	double calc();
//};

