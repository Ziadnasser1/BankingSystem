cmake_minimum_required(VERSION 3.23)
project(bankingSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(bankingSystem main.cpp cleint.cpp cleint.h SavingsBankAccount.cpp SavingsBankAccount.h BankAccount.cpp BankAccount.h BankApplication.cpp BankApplication.h)
