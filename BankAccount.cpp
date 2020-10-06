#include <bits/stdc++.h>
#include <ctime>

using namespace std;

struct ThisDay{
    int date;
    int month;
    int year;
};

int main() {
    int checkingInitial, savingsInitial;
    // cout << "Initial amount for(input format):  Checking Account, Savings Accoun\nt";
    
    // INPUT HERE INTIAL AMOUNT
    cin >> checkingInitial >> savingsInitial;
    
    // TRANSACTIONS HISTORY STORED IN VECTOR
    vector<pair <ThisDay, pair<string, int>>> transactionsForChecking;
    vector<pair <ThisDay, pair<string, int>>> transactionsForSaving;
    
    // FINAL AMOUNTS
    int finalForChecking = checkingInitial;
    int finalForSaving = savingsInitial;
    
    // CHOICE FOR ACCOUNT
    char whichAccount;
    
    // HOW MANY TRANSACTIONS TO PERFORM
    int iterations;
    cin >> iterations;
    
    while(iterations--) {
        // cout << "Which account or Terminate? (input format): c for checking s for saving and t to terminate\n";
        
        time_t transactionTime = time(0);
        tm *thisDay = localtime(&transactionTime);
        
        ThisDay thisDayStruct;
        
        thisDayStruct.date = thisDay->tm_mday;
        thisDayStruct.month = thisDay->tm_mon;
        thisDayStruct.year = thisDay->tm_year;
        
        // INPUT HERE WHICH ACCOUNT
        cin >> whichAccount;
        
        // cout << "input format: debit/credit (amount in multiple of 500)\n";
        
        if(whichAccount == 'c') {
            string inp;
            
            // INPUT HERE TRANSACTION
            cin >> inp;
            if(inp == "debit") {
                int amount;
                
                // INPUT HERE AMOUNT
                cin >> amount;
                if(amount%500 == 0 && amount <= finalForChecking) {
                     transactionsForChecking.push_back({thisDayStruct, {"debit", amount}});
                     finalForChecking -= amount;
                }
                else if(amount > finalForChecking) cout << "Insufficient Balance in Checking Account!\n";
                else cout << "Warning: Pl enter amount in multiple of 500\n";
            }
            else if(inp == "credit") {
                int amount;
                
                // INPUT HERE AMOUNT
                cin >> amount;
                if(amount%500 == 0) {
                     transactionsForChecking.push_back({thisDayStruct, {"credit", amount}});
                     finalForChecking += amount;
                }
            }
        }
        
        else if (whichAccount == 's'){
            string inp;
            
            // INPUT HERE TRANSACTION
            cin >> inp;
            
            if(inp == "debit") {
                int amount;
                
                // INPUT HERE AMOUNT
                cin >> amount;
                
                if(amount%500 == 0 && amount <= finalForSaving) {
                     transactionsForSaving.push_back({thisDayStruct, {"debit", amount}});
                     finalForSaving -= amount;
                }
                else if(amount > finalForSaving) cout << "Insufficient Balance in Savings Account!\n";
                else cout << "Warning: Pl enter amount in multiple of 500\n";
            }
            else if(inp == "credit") {
                int amount;
                cin >> amount;
                if(amount%500 == 0) {
                     transactionsForSaving.push_back({thisDayStruct, {"credit", amount}});
                     finalForSaving += amount;
                }
                else cout << "Warning: Pl enter amount in multiple of 500\n";
            }
        }
        // else break;
    }
    
    cout << "Transactions History for Checking Account\n";
    for(int i = 0; i < transactionsForChecking.size(); i++) {
        cout << transactionsForChecking[i].first.date << " " << 1+transactionsForChecking[i].first.month << " " << 1900 + transactionsForChecking[i].first.year << ' ';
        cout << transactionsForChecking[i].second.first << ' ' << transactionsForChecking[i].second.second << '\n';
    }
    
    cout << "Final in Checking = " << finalForChecking << '\n';
    
    cout << "Transactions History for Savings Account\n";
    for(int i = 0; i < transactionsForSaving.size(); i++) {
        cout << transactionsForSaving[i].first.date << " " << 1+transactionsForSaving[i].first.month << " " << 1900 + transactionsForSaving[i].first.year << ' ';
        cout << transactionsForSaving[i].second.first << ' ' << transactionsForSaving[i].second.second << '\n';
    }
    
    cout << "Final in Saving = " << finalForSaving << '\n';
    
    return 0;
}
