#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h> 
#include <fstream>
#include <string>

using namespace std;

struct Budget {

};

struct expenditure {
    double spend;
    string reason;
    int date;
};

struct income {
    double earn;
    string reason;
    int date;
};

class Budget {
    public:
        void addSpend();
        void removeSpend();
        void viewBudget();
        void invest(); //this is for further down the line, may need to be another class for the functions inside of this.
};

class Finance{
    private:
        vector<int> pin;
        vector<expenditure> reciept;
        vector<income> incomeList;
        double balance;
    public:
        double loadBalance(vector<int>& pin, double& balance){ //returns current budget
            return balance;
            }
        
        void adjustBalance(vector<expenditure> receipt, double balance){ //allows user to adjust balance, every time balance is adjusted, user must give reason for adjustment
            expenditure newSpend;
            income newIncome;
            double currentSpend;
            int choice;
            cout << "Would you like to adjust for an expenditure (1) or income (2):" << endl;
            cin >> choice;
            switch (choice){
                case 1:
                    cout << "Please enter the value of the expenditure:" << endl;
                    cin >> newSpend.spend;
                    cout << "Please enter the date of the expenditure in the format DDMMYYYY:" << endl;
                    cin >> newSpend.date;
                    cout << "Please enter the reason for the expenditure:" << endl;
                    getline(cin, newSpend.reason);
                    balance -= newSpend.spend;
                    receipt.push_back(newSpend);
                    break;
                case 2:
                    cout << "Please enter the value of income:" << endl;
                    cin >> newIncome.earn;
                    cout << "Please enter the date of the income in the format DDMMYYYY:" << endl;
                    cin >> newIncome.date;
                    cout << "Please enter the reason for income:" << endl;
                    getline(cin, newIncome.reason);
                    balance += newIncome.earn;
                    incomeList.push_back(newIncome);
                    break;
            }
            
        }

        void budgetPlan(double& balance){
            int choice;
            cout << "1) View Current Plan: \n2) Create New Plan:" << endl;
            cin >> choice;
            switch (choice){
                case 1:
                    cout << "current balance:" << balance << endl;
                    break;
                case 2:
                    cout << "current balance:" << balance << endl;

                    break;
            }
        }

        void print(){
            int timeChoice;
            int choice;
            cout << "Do you want to print your expenditures(1) or income statement?(2):" << endl;
            cin >> choice;
            cout << "Please select a time period (no input will be read as wanting to see everything):" << endl;
            cin >> timeChoice;
        }

        
    
            
};
