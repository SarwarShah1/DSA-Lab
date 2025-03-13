#include <iostream>
using namespace std;

int main()
{
	int price;
	int* p2price = &price;
	cout << "Enter the price of the car\n";
	cin >> *p2price;
	cout << "\n1st installment is: " << (((*p2price) / 100) * 12) + 15000;
}