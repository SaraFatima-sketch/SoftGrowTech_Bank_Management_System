#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNum, string name, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = name;
        balance = initialBalance;
    }

    int getAccountNumber() const { return accountNumber; }
    string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\n[Success] Amount Deposited Successfully! New Balance: $" << balance << endl;
        } else {
            cout << "\n[Error] Invalid Deposit Amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "\n[Success] Amount Withdrawn Successfully! Remaining Balance: $" << balance << endl;
        } else if (amount > balance) {
            cout << "\n[Error] Insufficient Balance!" << endl;
        } else {
            cout << "\n[Error] Invalid Withdrawal Amount!" << endl;
        }
    }

    void display() const {
        cout << "\n-----------------------------------";
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nAccount Holder : " << accountHolderName;
        cout << "\nBalance        : $" << balance;
        cout << "\n-----------------------------------" << endl;
    }
};

class BankManagementSystem {
private:
    vector<BankAccount> accounts;

public:
    void createAccount() {
        int accNum;
        string name;
        double initialBalance;

        cout << "\nEnter Account Number: ";
        cin >> accNum;

        cout << "Enter Account Holder Name: ";
        cin >> name;

        cout << "Enter Initial Balance: $";
        cin >> initialBalance;

        BankAccount newAccount(accNum, name, initialBalance);
        accounts.push_back(newAccount);
        cout << "\n[Success] Account Created Successfully!" << endl;
    }

    void depositMoney() {
        int accNum;
        double amount;
        cout << "\nEnter Account Number: ";
        cin >> accNum;

        for (auto &acc : accounts) {
            if (acc.getAccountNumber() == accNum) {
                cout << "Enter Amount to Deposit: $";
                cin >> amount;
                acc.deposit(amount);
                return;
            }
        }
        cout << "\n[Error] Account Not Found!" << endl;
    }

    void withdrawMoney() {
        int accNum;
        double amount;
        cout << "\nEnter Account Number: ";
        cin >> accNum;

        for (auto &acc : accounts) {
            if (acc.getAccountNumber() == accNum) {
                cout << "Enter Amount to Withdraw: $";
                cin >> amount;
                acc.withdraw(amount);
                return;
            }
        }
        cout << "\n[Error] Account Not Found!" << endl;
    }

    void displayDetails() const {
        int accNum;
        cout << "\nEnter Account Number: ";
        cin >> accNum;

        for (const auto &acc : accounts) {
            if (acc.getAccountNumber() == accNum) {
                acc.display();
                return;
            }
        }
        cout << "\n[Error] Account Not Found!" << endl;
    }
};

int main() {
    BankManagementSystem bank;
    int choice;

    do {
        cout << "\n====== BANK MANAGEMENT SYSTEM ======\n";
        cout << "1. Create New Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\n[Error] Invalid Input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.depositMoney();
                break;
            case 3:
                bank.withdrawMoney();
                break;
            case 4:
                bank.displayDetails();
                break;
            case 5:
                cout << "\nThank you for using Bank Management System!\n";
                break;
            default:
                cout << "\n[Error] Invalid Choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}