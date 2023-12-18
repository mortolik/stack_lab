#pragma once
#include <string>
#include <cmath>
#include <string.h>
#include "TStack.h"
using namespace ListStack;
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
	public:
		TCalculator(string& str) :inf(str) { };
		bool expression();
		void set_infix(string str);
		string get_infix();
		double calc();
};
