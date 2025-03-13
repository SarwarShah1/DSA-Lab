#include <iostream>
using namespace std;

class BankAccount {
	char* title;
	char* accountNumber;
	double balance;
	char* dateOfOpening;
public:
	void deposit(){}
	void withdraw(){}
};

class SavingsAccount : public BankAccount {
	double interestRate;
public:
	void calculateInterest() {}
};

class CheckingAccount : public BankAccount
{
	float fee;
};

int main()
{

	return 0;
}