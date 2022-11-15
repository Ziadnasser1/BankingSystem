//
// Created by Ziad Nasser on 2022-11-08.
//

#ifndef BANKINGSYSTEM_CLEINT_H
#define BANKINGSYSTEM_CLEINT_H

#include <iostream>
#include "BankAccount.h"
#include "SavingsBankAccount.h"

using namespace std;

class Client {
    string name;
    string address;
    string phone;
    BankAccount *account{};
    SavingsBankAccount *savingsAccount{};
public:
    Client(string n, string a, string p, BankAccount *acc);
    Client(string n, string a, string p, SavingsBankAccount *acc);
    void setName(string n);
    void setAddress(string a);
    void setPhone(string p);
    void setAccount(BankAccount *acc);
    void setSavingsAccount(SavingsBankAccount *acc);
    string getName();
    string getAddress();
    string getPhone();
    BankAccount *getAccount();
    SavingsBankAccount *getSavingsAccount();
};

#endif //BANKINGSYSTEM_CLEINT_H
