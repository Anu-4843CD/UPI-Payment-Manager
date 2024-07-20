#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(const std::string& userName, const std::string& passWord, double initBalance, const std::string& emailAddr, const std::string& phoneNum);

    std::string getUsername() const;
    std::string getUPIID() const;
    double getBalance() const;
    std::string getEmail() const;
    std::string getPhoneNumber() const;
    bool authenticate(const std::string& passWord) const;
    void deposit(double amount);
    void withdraw(double amount);

private:
    void generateUPIID();
    
    std::string username;
    std::string password;
    double balance;
    std::string email;
    std::string phoneNumber;
    std::string upiID;
};

#endif // USER_H
