//
// Created by Ziad Nasser on 2022-11-08.
//

#include "BankAccount.h"

#include <utility>

BankAccount::BankAccount(string ID, double b) {
    accountID = std::move(ID);
    balance = b;
}

BankAccount::BankAccount() {
    balance = 0;
}

void BankAccount::setBalance(double b) {
    balance = b;
}

void BankAccount::setAccountID(string ID) {
    accountID = ID;
}

double BankAccount::getBalance() {
    return balance;
}

string BankAccount::getAccountID() {
    return accountID;
}

int BankAccount::deposit(double amount) {
    balance += amount;
    return 1;
}

int BankAccount::withdraw(double amount) {
    if(amount > balance) {
        cout << "Sorry.This is more than what you can withdraw." << endl;
        return 0;
    }
    else {
        balance -= amount;
        return 1;
    }
}
