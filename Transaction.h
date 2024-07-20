#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
public:
    Transaction(const std::string& txnID, double amt, const std::string& txnStatus);

    std::string getTransactionID() const;
    double getAmount() const;
    std::string getStatus() const;

private:
    std::string transactionID;
    double amount;
    std::string status;
};

#endif // TRANSACTION_H
