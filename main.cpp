#include "UPIManager.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(static_cast<unsigned>(time(0))); 

    UPIManager upiManager;
    User currentUser("", "", 0.0, "", ""); 

    int choice;
    do {
        std::cout << "1. Register\n2. Login\n3. Initiate Payment\n4. View Transactions\n5. Admin Functions\n6. Check Balance\n7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                upiManager.registerUser();
                break;
            case 2:
                if (upiManager.loginUser(currentUser)) {
                    std::cout << "Login successful!" << std::endl;
                } else {
                    std::cout << "Invalid username or password!" << std::endl;
                }
                break;
            case 3:
                upiManager.initiatePayment(currentUser);
                break;
            case 4:
                upiManager.viewTransactionStatus();
                break;
            case 5:
                upiManager.adminFunctions();
                break;
            case 6:
                upiManager.checkBalance(currentUser);
                break;
            case 7:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
    } while (choice != 7);

    return 0;
}
