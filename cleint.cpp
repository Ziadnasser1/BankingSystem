//
// Created by Ziad Nasser on 2022-11-08.
//

#include "cleint.h"

#include <utility>

Client::Client(string n, string a, string p, BankAccount *acc) {
    name = std::move(n);
    address = std::move(a);
    phone = std::move(p);
    account = acc;
}

Client::Client(string n, string a, string p, SavingsBankAccount *acc) {
    name = std::move(n);
    address = std::move(a);
    phone = std::move(p);
    savingsAccount = acc;

}


void Client::setName(string n) {
    name = std::move(n);
}

void Client::setAddress(string a) {
    address = std::move(a);
}

void Client::setPhone(string p) {
    phone = std::move(p);
}

void Client::setAccount(BankAccount *acc) {
    account = acc;
}
void Client::setSavingsAccount(SavingsBankAccount *acc) {
    savingsAccount = acc;
}

string Client::getName() {
    return name;
}

string Client::getAddress() {
    return address;
}

string Client::getPhone() {
    return phone;
}

BankAccount *Client::getAccount() {
    return account;
}

SavingsBankAccount *Client::getSavingsAccount() {
    return savingsAccount;
}


