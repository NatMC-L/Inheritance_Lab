#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "BankAccount.h"

class CheckingAccount : public BankAccount {
    private:
        double transactionFee;
    public:
        CheckingAccount(string accNum, string holderName, double bal, double fee);
        bool withdraw(double amount) override; 
        void displayAccountInfo() const; 
};

#endif // CHECKINGACCOUNT_h
