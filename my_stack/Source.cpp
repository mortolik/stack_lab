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
	cout <<  check << endl;
	

	std::string ab = "((((2+3)*5)/4)^2)";
	TCalculator c(ab);
	double res = (((2.0 + 3) * 5) / 4) * (((2.0 + 3) * 5) / 4);
	cout << res << endl;
	cout << c.calc();
}