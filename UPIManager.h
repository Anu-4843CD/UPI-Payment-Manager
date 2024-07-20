#ifndef UPIMANAGER_H
#define UPIMANAGER_H

#include <vector>
#include "User.h"
#include "Transaction.h"

class UPIManager {
public:
    void registerUser();
    bool loginUser(User& loggedInUser);
    void initiatePayment(User& user);
    void viewTransactionStatus();
    void generateQRCode(const User& user);
    void adminFunctions();
    void checkBalance(const User& user);

private:
    std::vector<User> users;
    std::vector<Transaction> transactions;
};

#endif // UPIMANAGER_H
