//sort out bugging, actions need to go back to main menu
//save (file I/O)
//more features from there


#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Transaction {
    string description;
    double amount;
    int date;
    string action;
};

class Budget {
public:
    void addSpend();
    void removeSpend();
    void viewBudget();
    void invest(); 
};

class Finance {
    private:
        vector<Transaction> transactions;
        vector<Transaction> incomes;
        vector<Transaction> outgoings;
        double balance = 0;

    public:
        vector<Transaction>& getTransactions() { return transactions; }
        vector<Transaction>& getIncomes() { return incomes; }
        vector<Transaction>& getOutgoings() { return outgoings; }
        double& getBalanceRef() { return balance; }
        double getBalance() { 
            return balance;
        }

        void adjustBalance(vector<Transaction>& transactions, double& balance) {
            char another;
            do {
                Transaction newTransaction;
                int choice;
                cout << "Would you like to adjust for an expenditure (1) or income (2): ";
                cin >> choice;
    
                while (!(choice == 1 || choice == 2)) {
                    cout << "Please enter a valid choice (1 or 2): ";
                    cin >> choice;
                }
    
                cout << "Enter the amount (- for expenditure): ";
                cin >> newTransaction.amount;
    
                if (newTransaction.amount > 0) {
                    newTransaction.action = "Income:";
                } else {
                    newTransaction.action = "Expenditure:";
                }
    
                cin.ignore();
                cout << "Enter the date (DDMMYYYY): ";
                cin >> newTransaction.date;
                cin.ignore();
    
                cout << "Enter the reason: ";
                getline(cin, newTransaction.description);
    
                if (choice == 1) {
                    balance += newTransaction.amount;
                } else {
                    balance += newTransaction.amount;
                }
    
                transactions.push_back(newTransaction);
    
                cout << "Would you like to add another transaction? (y/n): ";
                cin >> another;
                cin.ignore();
    
            } while (another == 'y' || another == 'Y');
        }

        void budgetPlan(double& balance, vector<Transaction>& incomes, vector<Transaction>& outgoings) {
            int choice;
            double incomeTotal = 0;
            double outTotal = 0;
            cout << "1) View Current Plan: \n2) Create New Plan:" << endl;
            cin >> choice;

            if (choice == 1) {
                if (incomes.empty() && outgoings.empty()) {
                    cout << "There is currently no budget plan." << endl;
                    cout << "\nPress Enter to return to the menu...";
                    cin.ignore();
                    cin.get();  // Pause until the user presses Enter
                } else {
                    for (const auto& ins : incomes) {
                        cout << "Value: " << ins.amount << " Reason: " << ins.description << endl;
                        incomeTotal += ins.amount;
                    }
                    cout << "Total Income: " << incomeTotal << "\n\n";
                    cout << "Current Expenditure:" << endl;
                    for (const auto& outs : outgoings) {
                        cout << "Value: " << outs.amount << " Reason: " << outs.description << endl;
                        outTotal += outs.amount;
                    }
                    cout << "Total Expenditure: " << outTotal << "\n\n";
                    cout << "\nPress Enter to return to the menu...";
                    cin.get();  // Pause until the user presses Enter
                    cin.ignore();
                }
            } else {
                char another;
                do {
                    incomes.clear();
                outgoings.clear();
                double copyBalance = balance;
                Transaction newTransaction;
                
                cout << "Current balance: " << balance << endl;
                cout << "Would you like to add an expenditure (1) or income (2)?" << endl;
                cin >> choice;
                cin.ignore();

                cout << "Enter the amount:" << endl;
                cin >> newTransaction.amount;
                cin.ignore();

                cout << "Enter the reason:" << endl;
                getline(cin, newTransaction.description);

                if (choice == 1) {
                    copyBalance -= newTransaction.amount;
                    outgoings.push_back(newTransaction);
                } else {
                    copyBalance += newTransaction.amount;
                    incomes.push_back(newTransaction);
                }

                cout << "Updated balance: " << copyBalance << endl;
                cout << "Would you like to add another transaction? (y/n): ";
                cin >> another;
                cin.ignore();
    
                } while (another == 'y' || another == 'Y');
            }
        }

        void print(const vector<Transaction>& transactions, const string& type) {
            cout << "\n\n" << type << " Statement:" << endl;
            for (const auto& obj : transactions) {
                cout << obj.action << " " << "Value: " << obj.amount << " Description: " << obj.description << endl;
            }
        }
};

int main() {
    Finance financeObj;
    int choice;
    while (true) { // Infinite loop ensures the menu always comes back
        cout << "Jamie's Finance Tracker" << endl;
        cout << "1) See Balance:\n\n"
             << "2) Adjust Balance:\n\n"
             << "3) View/Create Budget: \n\n"
             << "4) Print Financial Statement:\n\n"
             << "5) Exit: \n\n" << endl;
        cin >> choice;
        cin.ignore();  // Ensure buffer is clear before taking further input

        switch (choice) {
            case 1:
                cout << "Balance: " << financeObj.getBalance() << endl;
                cout << "\nPress Enter to return to the menu...";
                cin.get();  // Pause until the user presses Enter
                break;
            case 2:
                financeObj.adjustBalance(financeObj.getTransactions(), financeObj.getBalanceRef());
                break;
            case 3:
                financeObj.budgetPlan(financeObj.getBalanceRef(), financeObj.getIncomes(), financeObj.getOutgoings());
                break;
            case 4:
                financeObj.print(financeObj.getTransactions(), "Financial");
                cout << "\nPress Enter to return to the menu...";
                cin.get();  // Pause until the user presses Enter
                break;
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
                cout << "\nPress Enter to return to the menu...";
                cin.get();  // Pause until the user presses Enter
                break;
        }
    }
    return 0;
}
