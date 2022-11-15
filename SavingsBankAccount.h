//
// Created by Ziad Nasser on 2022-11-08.
//

#ifndef BANKINGSYSTEM_SAVINGSBANKACCOUNT_H
#define BANKINGSYSTEM_SAVINGSBANKACCOUNT_H

#include <iostream>
#include "BankAccount.h"
using namespace std;

class SavingsBankAccount: public BankAccount{
    double minimumBalance = 1000;
public:
    SavingsBankAccount();
    SavingsBankAccount(string ID, double b, double minBalance);
    void setMinimumBalance(double minBalance);
    double getMinimumBalance();

    int withdraw(double amount) override ;
    int deposit(double amount) override;
};
#endif //BANKINGSYSTEM_SAVINGSBANKACCOUNT_H
