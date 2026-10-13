#include "SavingsAccount.h" 

SavingsAccount::SavingsAccount(string accNum, string holderName, double bal, double rate): BankAccount(accNum, holderName, bal) {
    interestRate = rate;
}

void SavingsAccount::calculateInterest() {
    balance += balance * interestRate;
}

void SavingsAccount::displayAccountInfo() const {
    cout << "\n--- Savings Account Information ---\n";
    printAccount(*this);
    cout <<"Interest Rate: " << interestRate * 100 <<"%\n";
}