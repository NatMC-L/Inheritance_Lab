#include <iostream>
#include <limits>
#include <vector>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
using namespace std;

int findAccount(const vector<BankAccount*>& accounts, 
    const string& accountNumber) {

    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getAccountNumber() == accountNumber) {
            return i; 
        }
    }

    return -1; 
}

int main() {
    vector<BankAccount*> accounts; 
    int choice;
    
    BankAccount* checking = new CheckingAccount("3023", "Juan", 5230, 2.3);
    BankAccount* savings = new SavingsAccount("3024", "Lily", 3200, 0.04); 
    checking->withdraw(100);
    savings->withdraw(200);

    cout << "Checking Balance: $" << checking->getBalance() << endl;
    cout << "Savings Balance: $" << savings->getBalance() << endl;

    delete checking;
    delete savings;


    do {
        cout << "\n ====== Bank Management System ======\n";
        cout << "1. Create Account\n";
        cout << "2. View Accounts\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Update Account Holder Name\n";
        cout << "6. Compare Accounts\n";
        cout << "7. Test Copy Constructor\n";
        cout << "8. Test Assignment Operator\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";

        while (!(cin >> choice)) {
            cout << "Inalid input. Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            // create a account 
            case 1: {
                int accountType;
                cout << "1. Checking Account\n";
                cout << "2. Savings Account\n";
                cout << "Select Account Type: ";
                cin >> accountType;

                string accNum;
                string holderName;
                double balance;
                
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Account Holder Name: ";
                cin >> holderName;
                cout << "Enter Initial Balance: ";
                cin >> balance;
                
                if (accountType == 1) {
                    double fee;
                    cout << "Enter Transaction Fee: ";
                    cin >> fee;
                    accounts.push_back(new CheckingAccount(accNum, holderName, balance, fee)); 
                }
                else if (accountType == 2) {
                    double rate;
                    cout << "Enter Interest Rate: ";
                    cin >> rate;
                    accounts.push_back(new SavingsAccount(accNum, holderName, balance, rate));
                }
                else {
                    cout << "Invalid Account Type.\n";
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Account Created Successfully.\n";
                break; 
            }
            // view accounts
            case 2: {
                if (accounts.empty()) {
                    cout << "No accounts found.\n";
                }
                else {
                    for (const auto& account : accounts) {
                        BankAccount::printAccount(*account);
                    }
                }
                break;
            }
            // deposit 
            case 3: {
                string accNum;
                double amount;
                
                cout <<"Enter Account Number: ";
                getline(cin, accNum);

                int index = findAccount(accounts, accNum);

                if(index == -1) {
                    cout << "Account not found.\n";
                    break; 
                }

                cout << "Enter Deposit Amount: ";

                while (!(cin >> amount)|| amount <=0) {
                    cout << "Invalid amount. Try again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                // perform deposit operation 
                *accounts[index] += amount; 

                cout << "Deposit sucessful.\n";
                break;
            }
            // withdrawal
            case 4: {
                string accNum;
                double amount;
                
                cout << "Enter Account Number: ";
                getline(cin, accNum);

                int index = findAccount(accounts, accNum);

                if (index == -1) {
                    cout << "Account not found.\n";
                    break;
                }

                cout << "Enter Withdrawal Amount: ";

                while (!(cin>> amount) || amount <= 0) {
                    cout << "Invalid amount. Try again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                double oldBalance = accounts[index]->getBalance();

                // perform withdrawal operation 
                accounts[index]->withdraw(amount);

                if (accounts[index]->getBalance() < oldBalance) {
                    cout << "Withdrawal successful.\n";
                }
                else {
                    cout << "Insufficient funds.\n";
                }
                break;
            }
            // update account holder name
            case 5: {
                string accNum;
                string newName;

                cout << "Enter Accout Number: ";
                getline(cin, accNum);

                int index = findAccount(accounts, accNum);

                if (index == -1) {
                    cout << "Acount not found.\n";
                    break;
                }

                cout <<"Enter New Account Holder Name: ";
                getline(cin, newName);

                accounts[index]->setAccountHolderName(newName);

                cout << "Name updated successfully.\n";
                break;
            }
            // compare accounts 
            case 6: {
                if (accounts.size() < 2) {
                    cout << "Need at least two account.\n";
                    break;
                }
                if (*accounts[0] == *accounts[1]) {
                    cout << "The accounts have the same accoount number.\n";
                }
                else {
                    cout << "The accounts have different account numbers.\n";
                }

                if (*accounts[0] > *accounts[1]) {
                    cout << "Account 1 has a greater balance.\n";
                }
                else if (*accounts[0] < *accounts[1]) {
                    cout << "Account 2 has a greater balance.\n";
                }
                else {
                    cout << "Both accounts have the same balance.\n";
                }
                break;
            }

            // copy constructor 
            case 7:{
                if (accounts.empty()) {
                    cout << "No accounts available.\n";
                    break;
                }
                // demonstrates copy constructor 
                BankAccount copiedAccount(*accounts[0]);

                cout << "\nCopied Constructor Test:\n";
                BankAccount::printAccount(copiedAccount);
                break;
            }

            // copy assignment 
            case 8: {
                if (accounts.empty()) {
                    cout << "No accounts available.\n";
                    break;
                }
                BankAccount assignedAccount;

                // demonstrates copy assignment 
                assignedAccount = *accounts[0];

                cout << "\nAssigned Operator Test:\n";
                BankAccount::printAccount(assignedAccount);
                break;
            }

            // exit program 
            case 9: {
                cout << "Have a Good Day!\n";
                break;
            }
            
            default:
                cout << "Invaild menu choice.\n";    
        }

    } while (choice != 9);


    for (BankAccount* account : accounts) {
        delete account;
    }
    return 0;
}
