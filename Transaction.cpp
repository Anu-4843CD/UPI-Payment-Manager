#include "Transaction.h"

Transaction::Transaction(const std::string& txnID, double amt, const std::string& txnStatus)
    : transactionID(txnID), amount(amt), status(txnStatus) {}

std::string Transaction::getTransactionID() const {
    return transactionID;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getStatus() const {
    return status;
}
