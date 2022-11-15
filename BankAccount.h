//
// Created by Ziad Nasser on 2022-11-08.
//

#ifndef BANKINGSYSTEM_BANKACCOUNT_H
#define BANKINGSYSTEM_BANKACCOUNT_H

#include <iostream>
using namespace std;

class BankAccount {
    string accountID;
    double balance;
public:
    BankAccount(string ID, double b);
    BankAccount();

    void setBalance(double b);
    void setAccountID(string ID);
    double getBalance();
    string getAccountID();

    virtual int deposit(double amount);
    virtual int withdraw(double amount);
};


#endif //BANKINGSYSTEM_BANKACCOUNT_H
