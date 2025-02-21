#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Transaction {
    string description;
    double amount;
    int date;
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
        double balance;

    public:
        double getBalance() const { 
            return balance; 
        }

        void adjustBalance(vector<Transaction>& transactions, double& balance) {
            Transaction newTransaction;
            int choice;
            cout << "Would you like to adjust for an expenditure (1) or income (2):" << endl;
            cin >> choice;
            cin.ignore(); // Fixes getline() issue

            cout << "Enter the amount:" << endl;
            cin >> newTransaction.amount;
            cin.ignore();

            cout << "Enter the date (DDMMYYYY):" << endl;
            cin >> newTransaction.date;
            cin.ignore();

            cout << "Enter the reason:" << endl;
            getline(cin, newTransaction.description);

            if (choice == 1) {
                balance -= newTransaction.amount;
            } else {
                balance += newTransaction.amount;
            }

            transactions.push_back(newTransaction);
        }

        void budgetPlan(double& balance, vector<Transaction>& incomes, vector<Transaction>& outgoings) {
            int choice;
            cout << "1) View Current Plan: \n2) Create New Plan:" << endl;
            cin >> choice;

            if (choice == 1) {
                if (incomes.empty() && outgoings.empty()) {
                    cout << "There is currently no budget plan." << endl;
                } else {
                    cout << "Current balance: " << balance << endl;
                    cout << "Current Income:" << endl;
                    for (const auto& ins : incomes) {
                        cout << "Value: " << ins.amount << " Reason: " << ins.description << endl;
                    }
                    cout << "Current Expenditure:" << endl;
                    for (const auto& outs : outgoings) {
                        cout << "Value: " << outs.amount << " Reason: " << outs.description << endl;
                    }
                }
            } else {
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
            }
        }

        void print(const vector<Transaction>& transactions, const string& type) {
            cout << type << " Statement:" << endl;
            for (const auto& obj : transactions) {
                cout << "Value: " << obj.amount << " Description: " << obj.description << endl;
            }
        }
};

int main(){
    Finance financeObj;
    int choice;
    cout << "Jamie's Finance Tracker" << endl;
    cout << "1) See Balance:\n\n" << "2) Adjust Balance:\n\n" << "3) View/Create Budget:" << "4) Print Financial Statement:\n\n" << endl;
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "Balance: " << financeObj.getBalance() << endl;
            break;
        case 2:
            financeObj.adjustBalance(financeObj.transactions,financeObj.balance);
            break;
        case 3:
            financeObj.budgetPlan(financeObj.balance,financeObj.incomes,financeObj.outgoings);
            break;
        case 4:
            financeObj.print(financeObj.transactions,"Financial Statement");
            break;
    }
return 0;
}
