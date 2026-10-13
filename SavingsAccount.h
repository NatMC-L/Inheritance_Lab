#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_h
#include "BankAccount.h"

class SavingsAccount: public BankAccount {
    private:
        double interestRate;
    public: 
        SavingsAccount(string accNum, string holderName, double bal, double rate);
        void calculateInterest();
        void displayAccountInfo() const; 
};

#endif // SAVINGSACOUNT_H