#include <iostream>
#include <string>
#include <vector>
#include <iomanip>  
#include <cstdlib>   
#include <ctime>     

using namespace std;


struct Transaction {
    string type;
    double amount;
    double balanceAfter;
};


class ATM {
private:
    string accountNumber;
    string pin;
    double balance;
    vector<Transaction> history;

    
    string bankName;
    string branchName;
    string ifscCode;
    string accountHolder;
    string mobileNumber;

public:
    
    ATM(string accNum, string p, double bal,
        string bank, string branch, string ifsc, string holder, string mobile)
        : accountNumber(accNum), pin(p), balance(bal),
          bankName(bank), branchName(branch), ifscCode(ifsc),
          accountHolder(holder), mobileNumber(mobile) {}


    bool authenticate(string enteredPin) {
        return enteredPin == pin;
    }


    void checkBalance() {
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
    }

  
    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
            return false;
        }
        balance -= amount;
        history.push_back({"Withdraw", amount, balance});
        cout << "Withdrawal successful. New Balance: $" << fixed << setprecision(2) << balance << endl;
        return true;
    }


    void deposit(double amount) {
        balance += amount;
        history.push_back({"Deposit", amount, balance});
        cout << "Deposit successful. New Balance: $" << fixed << setprecision(2) << balance << endl;
    }

    
    void viewHistory() {
        if (history.empty()) {
            cout << "No transactions yet." << endl;
            return;
        }
        cout << "\nTransaction History:" << endl;
        cout << left << setw(10) << "Type" << setw(10) << "Amount" << "Balance After" << endl;
        for (const auto& trans : history) {
            cout << left << setw(10) << trans.type
                 << "$" << setw(9) << fixed << setprecision(2) << trans.amount
                 << "$" << trans.balanceAfter << endl;
        }
    }

   
    void viewBankDetails() {
        cout << "\n===== Bank Account Details =====" << endl;
        cout << "Account Holder : " << accountHolder << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Bank Name      : " << bankName << endl;
        cout << "Branch Name    : " << branchName << endl;
        cout << "IFSC Code      : " << ifscCode << endl;
        cout << "Registered Mob.: " << mobileNumber << endl;
        cout << "--------------------------------" << endl;
    }

    
    int generateOTP() {
        srand(time(0)); 
        return rand() % 9000 + 1000; 
    }


    void changePIN() {
        cout << "\n--- Change ATM PIN ---" << endl;
        cout << "To change your PIN, an OTP will be sent to your registered mobile number ending with ****"
             << mobileNumber.substr(mobileNumber.length() - 4) << endl;

        int otp = generateOTP();
        cout << "\n[DEBUG: OTP sent to your mobile: " << otp << "]" << endl; // In real life, user gets SMS

        int enteredOTP;
        cout << "Enter the OTP: ";
        cin >> enteredOTP;

        if (enteredOTP == otp) {
            string newPin, confirmPin;
            cout << "Enter new 4-digit PIN: ";
            cin >> newPin;
            cout << "Confirm new PIN: ";
            cin >> confirmPin;

            if (newPin == confirmPin && newPin.length() == 4) {
                pin = newPin;
                cout << "✅ PIN changed successfully!" << endl;
            } else {
                cout << "❌ PIN mismatch or invalid length! Try again." << endl;
            }
        } else {
            cout << "❌ Incorrect OTP. PIN change failed." << endl;
        }
    }

   
    string getAccountNumber() {
        return accountNumber;
    }
};

int main() {
    
    ATM atm("123456789", "1234", 1000.00,
            "State Bank of India", "Jaipur Main Branch", "SBIN0001203", "Hemant Verma", "9876543210");

    string enteredPin;
    cout << "Welcome to the ATM Machine!" << endl;
    cout << "Enter your PIN: ";
    cin >> enteredPin;

    if (!atm.authenticate(enteredPin)) {
        cout << "Invalid PIN. Exiting..." << endl;
        return 0;
    }

    cout << "Login successful! Account: " << atm.getAccountNumber() << endl;

    int choice;
    do {
        cout << "\nATM Menu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. View Transaction History" << endl;
        cout << "5. View Bank Details" << endl;
        cout << "6. Change ATM PIN" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                atm.checkBalance();
                break;
            case 2: {
                double amount;
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                if (amount <= 0) {
                    cout << "Invalid amount!" << endl;
                } else {
                    atm.withdraw(amount);
                }
                break;
            }
            case 3: {
                double amount;
                cout << "Enter amount to deposit: $";
                cin >> amount;
                if (amount <= 0) {
                    cout << "Invalid amount!" << endl;
                } else {
                    atm.deposit(amount);
                }
                break;
            }
            case 4:
                atm.viewHistory();
                break;
            case 5:
                atm.viewBankDetails();
                break;
            case 6:
                atm.changePIN();
                break;
            case 7:
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}