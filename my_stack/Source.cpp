#include <string>
#include <iostream>
#include "TStack.h"
#include "Calculator.h"

using namespace std;

int main()
{
	string s = "((5.5+2)*3)^2";
	TCalculator a(s);
	bool check = a.expression();
	cout << a.calc()<<endl;
	cout <<  check;
}