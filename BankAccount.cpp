#include "BankAccount.h"

// Default constructor 
BankAccount::BankAccount() {
    accountNumber = "";
    accountHolderName = "";
    balance = 0.0;
}
// Parameterized constructor
BankAccount::BankAccount(string accNum, string holderName, double bal) {
    accountNumber = accNum;
    accountHolderName = holderName;
    balance = bal;
}
// Rule of Three - copy constructor 
BankAccount::BankAccount(const BankAccount& other) : 
accountNumber(other.accountNumber), 
accountHolderName(other.accountHolderName), 
balance(other.balance) {}

// Rule of Three - copy assignment operator
BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        accountNumber = other.accountNumber;
        accountHolderName = other.accountHolderName;
        balance = other.balance;
    }
    return *this;

}

// Rule of three - destructor
BankAccount::~BankAccount() {}

// getter functions
string BankAccount::getAccountNumber() const {
    return accountNumber; 
}

string BankAccount:: getAccountHolderName() const {
    return accountHolderName;
}

double BankAccount::getBalance() const{
    return balance; 
}
// setter function 
void BankAccount::setAccountHolderName(string holderName) {
    accountHolderName = holderName;
}
// deposit function 
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}
// withdraw funtion 
bool BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true; 
    }
   
    return false; 
}

// arithmetic operator 
BankAccount& BankAccount::operator+=(double amount) {
    if (amount > 0) {
        balance += amount;
    }
    return *this; 
}
BankAccount& BankAccount::operator-=(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount; 
    }
    return *this; 
}
// comparsion operators
// operator ==
bool BankAccount::operator==(const BankAccount& other) const {
    return accountNumber == other.accountNumber;
}
// operator < 
bool BankAccount::operator<(const BankAccount& other) const {
    return balance < other.balance;
}
// operator > 
bool BankAccount::operator>(const BankAccount& other) const {
    return balance > other.balance;
}
// Static function 
void BankAccount::printAccount(const BankAccount& account) {
    cout << "\n Account Number: " << account.accountNumber << endl;
    cout << " Account Holder Name: " << account.accountHolderName << endl;
    cout << " Balance: $" << account.balance << endl;
}
// static account creator 
BankAccount BankAccount::createAccountFromInput() {
    string accNum;
    string holderName;
    double bal;

    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter Account Holder Name: ";
    cin >> holderName;
    cout << "Enter Initial Balance: ";
    cin >> bal;

    while (!(cin>> bal) || bal < 0) {
        cout << "Invalid balance. Enter Initial Balance: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return BankAccount(accNum, holderName, bal);
}
