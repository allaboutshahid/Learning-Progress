#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    Account(int number, string name, double initialBalance)
        : accountNumber(number),
          holderName(name),
          balance(initialBalance) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\nAmount deposited successfully.\n";
        } else {
            cout << "\nInvalid amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "\nInvalid amount.\n";
        }
        else if (amount > balance) {
            cout << "\nInsufficient balance.\n";
        }
        else {
            balance -= amount;
            cout << "\nAmount withdrawn successfully.\n";
        }
    }

    void display() const {
        cout << "\n--------------------------------\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Holder Name    : " << holderName << endl;
        cout << "Balance        : Rs. "
             << fixed << setprecision(2)
             << balance << endl;
        cout << "--------------------------------\n";
    }
};

class Bank {
private:
    vector<Account> accounts;

    Account* findAccount(int number) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == number)
                return &account;
        }
        return nullptr;
    }

public:
    void createAccount() {
        int number;
        string name;
        double balance;

        cout << "\nEnter Account Number: ";
        cin >> number;

        if (findAccount(number) != nullptr) {
            cout << "Account already exists.\n";
            return;
        }

        cout << "Enter Holder Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        if (balance < 0) {
            cout << "Invalid balance.\n";
            return;
        }

        accounts.emplace_back(number, name, balance);

        cout << "\nAccount created successfully.\n";
    }

    void depositMoney() {
        int number;
        double amount;

        cout << "\nEnter Account Number: ";
        cin >> number;

        Account* account = findAccount(number);

        if (account == nullptr) {
            cout << "Account not found.\n";
            return;
        }

        cout << "Enter Amount: ";
        cin >> amount;

        account->deposit(amount);
    }

    void withdrawMoney() {
        int number;
        double amount;

        cout << "\nEnter Account Number: ";
        cin >> number;

        Account* account = findAccount(number);

        if (account == nullptr) {
            cout << "Account not found.\n";
            return;
        }

        cout << "Enter Amount: ";
        cin >> amount;

        account->withdraw(amount);
    }

    void searchAccount() {
        int number;

        cout << "\nEnter Account Number: ";
        cin >> number;

        Account* account = findAccount(number);

        if (account != nullptr)
            account->display();
        else
            cout << "Account not found.\n";
    }

    void displayAll() const {
        if (accounts.empty()) {
            cout << "\nNo accounts available.\n";
            return;
        }

        cout << "\n========== ALL ACCOUNTS ==========\n";

        for (const auto &account : accounts)
            account.display();
    }
};

int main() {
    Bank bank;
    int choice;

    while (true) {
        cout << "\n\n========== BANK MANAGEMENT SYSTEM ==========\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Search Account\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";
        cout << "===========================================\n";

        cout << "Enter Choice: ";
        cin >> choice;

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
                bank.searchAccount();
                break;

            case 5:
                bank.displayAll();
                break;

            case 6:
                cout << "\nExiting program...\n";
                return 0;

            default:
                cout << "\nInvalid choice!\n";
        }
    }
}