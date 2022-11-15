//
// Created by Ziad Nasser on 2022-11-08.
//

#ifndef BANKINGSYSTEM_BANKAPPLICATION_H
#define BANKINGSYSTEM_BANKAPPLICATION_H

#include <iostream>
#include "BankApplication.h"
#include "SavingsBankAccount.h"
#include "cleint.h"

using namespace std;

class BankApplication {
public:
    void BankApp();
    void addAccount();
    void listClients();
    void withdrawMoney();
    void depositMoney();
    static void fillUserData(string name, string address, string phone, string accountID, double balance,string t);
    static string generateID();
    string getbalance(string accountID);
    void changeOldFile();
    void deleteTempFile();
};
#endif //BANKINGSYSTEM_BANKAPPLICATION_H
