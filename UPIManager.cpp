#include "UPIManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void UPIManager::registerUser() {
    std::string username, password, email, phoneNumber;
    double initialBalance;

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Enter initial balance: ";
    std::cin >> initialBalance;
    std::cout << "Enter email: ";
    std::cin >> email;
    std::cout << "Enter phone number: ";
    std::cin >> phoneNumber;

    users.push_back(User(username, password, initialBalance, email, phoneNumber));
    std::cout << "User registered successfully!" << std::endl;
    std::cout << "Your UPI ID: " << users.back().getUPIID() << std::endl;
}

bool UPIManager::loginUser(User& loggedInUser) {
    std::string username, password;

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    for (auto& user : users) {
        if (user.getUsername() == username && user.authenticate(password)) {
            loggedInUser = user;
            return true;
        }
    }
    return false;
}

void UPIManager::initiatePayment(User& user) {
    double amount;
    std::cout << "Enter amount to pay: ";
    std::cin >> amount;

    if (user.getBalance() >= amount) {
        user.withdraw(amount);
        std::string transactionID = "TXN" + std::to_string(rand() % 10000);
        transactions.push_back(Transaction(transactionID, amount, "Success"));
        std::cout << "Payment successful! Transaction ID: " << transactionID << std::endl;
    } else {
        std::cout << "Insufficient balance!" << std::endl;
    }
}

void UPIManager::viewTransactionStatus() {
    std::cout << "Transaction ID\tAmount\tStatus" << std::endl;
    for (const auto& txn : transactions) {
        std::cout << txn.getTransactionID() << "\t" << txn.getAmount() << "\t" << txn.getStatus() << std::endl;
    }
}

void UPIManager::generateQRCode(const User& user) {
    std::cout << "Generating QR Code for UPI payment..." << std::endl;
    std::cout << "UPI ID for user: " << user.getUPIID() << std::endl;
    // For actual QR code generation, you would need a library
    std::cout << "QR Code: [***]" << std::endl; // Placeholder for QR code
}

void UPIManager::adminFunctions() {
    int adminChoice;
    std::cout << "Admin Functions: " << std::endl;
    std::cout << "1. View all transactions" << std::endl;
    std::cout << "2. View all users" << std::endl;
    std::cout << "3. Add balance to user" << std::endl;
    std::cout << "4. Logout" << std::endl;

    std::cout << "Enter your choice: ";
    std::cin >> adminChoice;

    switch (adminChoice) {
        case 1:
            viewTransactionStatus();
            break;
        case 2:
            for (const auto& user : users) {
                std::cout << "Username: " << user.getUsername() << ", Email: " << user.getEmail() << ", Phone: " << user.getPhoneNumber() << ", Balance: " << user.getBalance() << std::endl;
            }
            break;
        case 3: {
            std::string username;
            double amount;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter amount to add: ";
            std::cin >> amount;

            for (auto& user : users) {
                if (user.getUsername() == username) {
                    user.deposit(amount);
                    std::cout << "Balance added successfully!" << std::endl;
                    break;
                }
            }
            break;
        }
        case 4:
            std::cout << "Logging out..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
    }
}

void UPIManager::checkBalance(const User& user) {
    std::cout << "Current balance for user " << user.getUsername() << ": " << user.getBalance() << std::endl;
}
