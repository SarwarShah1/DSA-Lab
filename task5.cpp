#include <iostream>
#include <cstring>
using namespace std;

class BankAccount {
protected:
    char* title;
    char* accountNumber;
    double balance;
    char* dateOfOpening;

public:
    BankAccount(const char* t, const char* accNum, double bal, const char* date) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);

        accountNumber = new char[strlen(accNum) + 1];
        strcpy(accountNumber, accNum);

        balance = bal;

        dateOfOpening = new char[strlen(date) + 1];
        strcpy(dateOfOpening, date);
    }

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    virtual void display() {
        cout << "Account Title: " << title << "\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: " << balance << "\n";
        cout << "Date of Opening: " << dateOfOpening << "\n";
    }

    virtual ~BankAccount() {
        delete[] title;
        delete[] accountNumber;
        delete[] dateOfOpening;
    }
};

class SavingsAccount : public BankAccount {
    double interestRate;

public:
    SavingsAccount(const char* t, const char* accNum, double bal, const char* date, double rate)
        : BankAccount(t, accNum, bal, date), interestRate(rate) {}

    void deposit(double amount) override {
        balance += amount - (amount * interestRate / 100);
    }

    void withdraw(double amount) override {
        balance -= amount + (amount * interestRate / 100);
    }

    void calculateInterest() {
        balance += (balance * interestRate / 100);
    }
};

class CheckingAccount : public BankAccount {
    double fee;

public:
    CheckingAccount(const char* t, const char* accNum, double bal, const char* date, double f)
        : BankAccount(t, accNum, bal, date), fee(f) {}

    void deposit(double amount) override {
        balance += amount - fee;
    }

    void withdraw(double amount) override {
        if (amount + fee <= balance) {
            balance -= (amount + fee);
        } else {
            cout << "Insufficient balance including transaction fee!\n";
        }
    }
};

int main() {
    SavingsAccount savings("John Doe", "12345", 1000.0, "2023-01-01", 5.0);
    CheckingAccount checking("Jane Doe", "67890", 2000.0, "2023-01-01", 10.0);

    cout << "Initial Account Details:\n";
    savings.display();
    checking.display();

    savings.deposit(500);
    savings.withdraw(200);
    savings.calculateInterest();

    checking.deposit(1000);
    checking.withdraw(500);

    cout << "\nAfter Transactions:\n";
    savings.display();
    checking.display();

    return 0;
}
