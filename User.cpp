#include "User.h"
#include <iostream>   
#include <sstream>
#include <iomanip>
#include <cstdlib>

User::User(const std::string& userName, const std::string& passWord, double initBalance, const std::string& emailAddr, const std::string& phoneNum)
    : username(userName), password(passWord), balance(initBalance), email(emailAddr), phoneNumber(phoneNum) {
    generateUPIID();
}

std::string User::getUsername() const {
    return username;
}

std::string User::getUPIID() const {
    return upiID;
}

double User::getBalance() const {
    return balance;
}

std::string User::getEmail() const {
    return email;
}

std::string User::getPhoneNumber() const {
    return phoneNumber;
}

bool User::authenticate(const std::string& passWord) const {
    return password == passWord;
}

void User::deposit(double amount) {
    balance += amount;
}

void User::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
    } else {
        std::cout << "Error: Insufficient funds to withdraw " << amount << std::endl;
    }
}

void User::generateUPIID() {
    std::stringstream ss;
    ss << "UPI" << std::setw(4) << std::setfill('0') << rand() % 10000;
    upiID = ss.str();
}
