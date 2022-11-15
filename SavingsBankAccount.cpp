//
// Created by Ziad Nasser on 2022-11-08.
//

#include "SavingsBankAccount.h"

#include <utility>

SavingsBankAccount::SavingsBankAccount(string ID, double b, double minBalance): BankAccount(std::move(ID), b) {
    minimumBalance = minBalance;
}
SavingsBankAccount::SavingsBankAccount() {
    minimumBalance = 1000;
}

void SavingsBankAccount::setMinimumBalance(double minBalance) {
    minimumBalance = minBalance;
}

double SavingsBankAccount::getMinimumBalance() {
    return minimumBalance;
}

int SavingsBankAccount::withdraw(double amount) {
    if(amount > (getBalance() - minimumBalance)) {
        cout << "Sorry.This is more than what you can withdraw." << endl;
        return 0;
    }
    else {
        setBalance(getBalance() - amount);
        return 1;
    }
}

int SavingsBankAccount::deposit(double amount) {
    if(amount >=100){
        setBalance(getBalance() + amount);
        return 1;
        }
    else {
//        cout << "Sorry. the deposit is less than the required amount (100)." << endl;
        return 0;
    }
}



