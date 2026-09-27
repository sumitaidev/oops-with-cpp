#include <iostream>
#include <string>

// 1. GLOBAL SCOPE
// This variable can be accessed by ANY function or class in this file.
//add some new comment 
std::string globalBankName = "Global C++ Bank"; 

// 2. CLASS DEFINITION (The Blueprint)
class BankAccount {
// Class Scope - Private (Hidden from outside)
private: 
    double balance; // Only functions inside BankAccount can touch this

// Class Scope - Public (Accessible from outside)
public: 
    std::string ownerName;

    // Constructor (called automatically when an object is created)
    BankAccount(std::string name, double initialDeposit) {
        ownerName = name;
        balance = initialDeposit;
    }

    // Public method to safely interact with the private balance
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited $" << amount << ". New balance: $" << balance << "\n";
        }
    }
};

int main() {
    // 3. LOCAL SCOPE
    // 'bonus' only exists inside the main() function.
    double localBonus = 230.0; 

    std::cout << "Welcome to " << globalBankName << "\n";

    // 4. OBJECT CREATION (Building the house)
    // 'account1' is an Object created from the BankAccount Class
    BankAccount account1("sumit haldar", 123.0); 

    // We can access 'ownerName' because it is PUBLIC
    std::cout << "Account created for: " << account1.ownerName << "\n";

    // ERROR: account1.balance = 5000; 
    // We CANNOT do this because 'balance' is PRIVATE scope.

    // We MUST use a public method to change the private balance
    account1.deposit(localBonus);

    return 0; // 'localBonus' and 'account1' are destroyed here when local scope ends
}
