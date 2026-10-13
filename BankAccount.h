#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string> 
#include <limits> 
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string accountHolderName;
    double balance;
       
public: 
    // Constructors
    BankAccount();
    BankAccount(string accNum, string holderName, double bal);

    // the Rule of Three
    BankAccount(const BankAccount& other);  // copy constructor
    BankAccount& operator=(const BankAccount& other);  // copy assignment operator
   
    // destructor 
    virtual ~BankAccount(); 

    // Getters
    string getAccountNumber() const;
    string getAccountHolderName() const;
    double getBalance() const;

    // Setter
    void setAccountHolderName(string holderName);

    // Transaction methods
    void deposit(double amount);
    virtual bool withdraw(double amount);

    // Arithmetic operators
    BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);

    // Comparison operators
    bool operator==(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator>(const BankAccount& other) const;

    // Static Utility Functions
    static void printAccount(const BankAccount& account); 
    static BankAccount createAccountFromInput();

    virtual void displayAccountInfo() const; 
};


#endif // BANKACCOUNT_H
