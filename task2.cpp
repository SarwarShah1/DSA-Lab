#include <iostream>
using namespace std;

int main()
{
	float val1, val2;
	float* p2val1, * p2val2;
	char oper;
	char* p2oper = &oper;
	p2val1 = &val1;
	p2val2 = &val2;
	cout << "Enter value 1\n";
	cin >> *p2val1;
	cout << "\nEnter value 2\n";
	cin >> *p2val2;
	cout << "Enter operator\n";
	cin >> *p2oper;
	if (*p2oper == '+')
	{
		cout << "Answer is: " << *p2val1 + *p2val2;
	}
	else if (*p2oper == '-')
	{
		cout << "Answer is: " << *p2val1 - *p2val2;
	}
	else if (*p2oper == '/')
	{
		cout << "Answer is: " << *p2val1 / *p2val2;
	}
	else if (*p2oper == '*')
	{
		cout << "Answer is: " << *p2val1 * *p2val2;
	}
}