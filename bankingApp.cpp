#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

// Declaring functions
void mainMenu(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword);
string createPin(string mainTitle);
string changePin(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword);
void settingsFunct(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword);
void withdrawFunct(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword);
void depositFunct(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword);
void balanceFunct(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword);
void doubleSecurityCheck(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword);
void checkLogs(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword);
void switchDoubleSecurity(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword);


int main(){
    // Defining variables
    int balance = 0;
    string mainTitle = "WHAT ACTIONS WOULD YOU LIKE TO PERFORM?\n";
    string pin = createPin(mainTitle);
    int logSize = 5;
    string transactionLogs[logSize];
    bool doubleSecurity = false;
    char choice;
    string doubleSecurityKeyword = "Enable";

    mainMenu(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
    return 0;
}

// Adding use to the functions
void settingsFunct(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword) {
    // Defining variables
    char choice;
    do {
        cout << "\n********************\n";
        cout << mainTitle;
        cout << "A) Change pin\n";
        cout << "B) " << doubleSecurityKeyword << " double security\n";
        cout << "C) Exit\n";
        cout << "********************\n";
        cin >> choice;
        choice = toupper(choice);
    } while (choice != 'A' && choice != 'B' && choice != 'C');

    switch (choice) {
        case 'A':
            pin = changePin(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
            break;
        case 'B':
            switchDoubleSecurity(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
            break;
        case 'C':
            mainMenu(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
            break;
    }
    
};

// ————————————————————
// MAIN MENU FUNCTION
// ————————————————————
void mainMenu(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword){
    char choice;
    do{
        cout << "\n********************\n";
        cout << mainTitle;
        cout << "A) Withdraw from the bank\n";
        cout << "B) Deposit into the bank\n";
        cout << "C) Check doubloon balance\n";
        cout << "D) Check logs\n";
        cout << "E) Settings\n";
        cout << "F) Exit\n";
        cout << "********************\n";
        cin >> choice;
        choice = toupper(choice);

        if (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' && choice != 'E' && choice != 'F') {
            mainTitle = "INVALID INPUT! TYPE IN ONE OF THE FOLLOWING:\n";
        }
    } while (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' && choice != 'E' && choice != 'F');
    switch (choice){
        case 'A':
            withdrawFunct(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
            break;
        case 'B':
            depositFunct(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
        case 'C':
            balanceFunct(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
            break;
        case 'D':
            checkLogs(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
            break;
        case 'E':
            mainTitle = "BANKING APPLICATION SETTINGS\n";
            settingsFunct(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
            break;
    }
};

// ————————————————————
// CHECK BALANCE FUNCTION
// ————————————————————
void balanceFunct(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword) {
    string inputPin;
    mainTitle = "ENTER YOUR PIN (DOUBLE SECURITY)\n";
    
    
    mainTitle = "YOUR BALANCE: " + to_string(balance) + " doubloons\n";
     mainMenu(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
};

// ————————————————————
// WITHDRAW FUNCTION
// ————————————————————
void withdrawFunct(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword) {
    doubleSecurityCheck(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
    mainTitle = "HOW MUCH WOULD YOU LIKE TO WIDHDRAW?\n";
    int amount;
    do{
        cout << "\n********************\n";
        cout << mainTitle;
        cout << "********************\n";
        cin >> amount;
        if (amount < 1) {
            mainTitle = "YOU CAN'T WITHDRAW AN AMOUNT LESS THAN 0!\n";
        }
    } while (amount < 1);
    balance += amount;

    if (logSize < 5) {
        transactionLogs[logSize] = "Withdrew " + to_string(amount) + " doubloons";
    }
    else {
        for(int i = logSize - 1; i > 0; i--) {
            transactionLogs[i] = transactionLogs[i-1];
        }
        transactionLogs[0] = "Withdrew " + to_string(amount) + " doubloons";
    }

    mainTitle = "WITHDRAWAL SUCCESSFUL!\n";
    mainMenu(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
};

// ————————————————————
// DEPOSIT FUNCTION
// ————————————————————
void depositFunct(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword) {
    doubleSecurityCheck(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
    mainTitle = "HOW MUCH WOULD YOU LIKE TO DEPOSIT INTO THE BANK?\n";
    int amount;
    do{
        cout << "\n********************\n";
        cout << mainTitle;
        cout << "A) to exit the deposit\n";
        cout << "********************\n";
        cin >> amount;
        if (amount < 1) {
            mainTitle = "YOU CAN'T DEPOSIT AN AMOUNT LESS THAN 0!\n";
        }

        if (amount > balance) {
            mainTitle = "YOU DON'T HAVE ENOUGH MONEY IN YOUR ACCOUNT!\n";
            amount = 0;
        }

    } while (amount < 1 || amount > balance || amount != 'A');
    balance -= amount;
    mainTitle = "DEPOSIT SUCCESSFUL!\n";
    mainMenu(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
};

// ————————————————————
// CREATE PIN FUNCTION
// ————————————————————
string createPin(string mainTitle) {
    string pin;
    mainTitle = "WELCOME TO THE BANKING PROGRAM!\nSTART BY CREATING A PIN: (4 DIGITS)\n";
    bool validPin;
    do{
        validPin = true;
        cout << "\n********************\n";
        cout << mainTitle;
        cout << "********************\n";
        cin >> pin;
        
        if(pin.length() != 4) {
            validPin = false;
            mainTitle = "THE LENGHT OF THE PIN MUST BE 4 DIGITS!\n";
        }
        for(char c : pin) {
            if(!isdigit(c)) {
                validPin = false;
                mainTitle = "THE PIN MUST INCLUDE DIGITS ONLY!\n";
            }
        }

        if(validPin) {
            string confirmPin;
            do {
                cout << "\n********************\n";
                cout << "CONFIRM PIN? (YES/NO): " << pin << "\n";
                cout << "********************\n";
                cin >> confirmPin;
            } while (confirmPin != "YES" && confirmPin != "Yes" && confirmPin != "yes" && confirmPin != "NO" && confirmPin != "NO" && confirmPin != "No" && confirmPin != "no");
            
            if (confirmPin == "YES" || confirmPin == "Yes" || confirmPin == "yes") {
                mainTitle = "PIN CREATED SUCCESSFULLY!\n";
            }
            else {
                mainTitle = "PIN CREATION CANCELLED!\nCREATE ANOTHER PIN: (4 DIGITS)\n";
                validPin = false;
            }
        }
    } while (!validPin);
    return pin;
};

// ————————————————————
// CHANGE PIN FUNCTION
// ————————————————————
string changePin(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword) {
    // Defining variables
    mainTitle = "TO CHANGE YOUR PIN PLEASE ENTER YOUR CURRENT PIN\n";
    string pinVerify;
    bool validPin;

    // To change the pin the user has to verify themselves by entering their current pin
    do {
        cout << "\n********************\n";
        cout << mainTitle;
        cout << "A) Back to settings\n"; 
        cout << "********************\n";
        cin >> pinVerify;

        if (pinVerify != "A" && pinVerify != "a" && pinVerify != pin) {
            mainTitle = "THE CURRENT PIN IS INCORRECT! TRY AGAIN\n";
        }

        if (pinVerify == "A" || pinVerify == "a") {
            mainTitle = "PIN CHANGE CANCELLED!\n";
            settingsFunct(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
        }
    } while(pinVerify != pin && pinVerify != "A" && pinVerify != "a");

    if (pinVerify == pin) {
        mainTitle = "VERIFICATION SUCCESSFUL! ENTER YOUR NEW PIN: (4 DIGITS)\n";
        do{
            validPin = true;
            cout << "\n********************\n";
            cout << mainTitle;
            cout << "********************\n";
            cin >> pin;

            // Check if the entered  pin is valid
            if(pin.length() != 4) {
                validPin = false;
                mainTitle = "THE LENGHT OF THE PIN MUST BE 4 DIGITS!\n";
            }

            for(char c : pin) {
                if(!isdigit(c)) {
                    validPin = false;
                    mainTitle = "THE PIN MUST INCLUDE DIGITS ONLY!\n";
                }
            }

            if (pinVerify == pin) {
                validPin = false;
                mainTitle = "YOU CAN'T CHANGE YOUR PIN TO YOUR PREVIOUS PIN!\n TRY AGAIN!\n";
            }

            // If the user enters a valid pin, ask for confirmation
            if(validPin) {
                string confirmPin;
                do {
                    cout << "\n********************\n";
                    cout << "CONFIRM PIN? (YES/NO): " << pin << "\n";
                    cout << "********************\n";
                    cin >> confirmPin;
                } while (confirmPin != "YES" && confirmPin != "Yes" && confirmPin != "yes" && confirmPin != "NO" && confirmPin != "NO" && confirmPin != "No" && confirmPin != "no");
                
                if (confirmPin == "YES" || confirmPin == "Yes" || confirmPin == "yes") {
                    mainTitle = "PIN CREATED SUCCESSFULLY!\n";
                    return pin;
                }
                else {
                    mainTitle = "PIN CREATION CANCELLED!\nCREATE ANOTHER PIN: (4 DIGITS)\n";
                    validPin = false;
                }
            }
        } while (!validPin);
    }
    else {
        mainTitle = "PIN CHANGE CANCELLED!\n";
    }
}

void doubleSecurityCheck(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword) {
    if (doubleSecurity) {
        mainTitle = "PLEASE ENTER YOUR PIN! (DOUBLE SECURITY)\n";
        string inputPin;
        do {
            cout << "\n********************\n";
            cout << mainTitle;
            cout << "A) to exit\n";
            cout << "********************\n";
            cin >> inputPin;
            if (inputPin != pin) {
                mainTitle = "INVALID PIN TRY AGAIN!\n";
            };
            
            if (inputPin == "A" || inputPin == "a") {
                mainTitle = "WHAT ACTIONS WOULD YOU LIKE TO PERFORM?\n";
                mainMenu(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
            };
        }while (inputPin != pin);
    };
};

void checkLogs(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword){
    doubleSecurityCheck(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
    char choice;
    mainTitle = "TRANSACTION LOGS:\n";
    cout << "\n********************\n";
    cout << mainTitle;
    cout << "A) Back to settings\n";
    cout << "********************\n";
    cout << "SHOWING LAST 5 TRANSACTIONS:\n";
    for (int i = 0; i < logSize; i++) {
        cout << i+1 << ". " << transactionLogs[i] << "\n";
    }
    cout << "********************\n";
};

void switchDoubleSecurity(int balance, string pin, bool doubleSecurity, string mainTitle, string transactionLogs[], int logSize, string doubleSecurityKeyword) {
    string pinVerify;
    
    if (doubleSecurityKeyword == "Enable") {
        doubleSecurity = true;
        doubleSecurityKeyword = "Disable";
        mainTitle = "DOUBLE SECURITY ENABLED!\n";
    }
    else if (doubleSecurityKeyword == "Disable") {
        mainTitle = "TO CHANGE DISABLE DOUBLE SECURITY PLEASE ENTER YOUR CURRENT PIN\n";
        do {
            cout << "\n********************\n";
            cout << mainTitle;
            cout << "A) Back to settings\n";
            cout << "********************\n";
            cin >> pinVerify;

            if (pinVerify != "A" && pinVerify != "a" && pinVerify != pin) {
                mainTitle = "THE CURRENT PIN IS INCORRECT! TRY AGAIN\n";
            }

            if (pinVerify == "A" || pinVerify == "a") {
                mainTitle = "PIN CHANGE CANCELLED!\n";
                settingsFunct(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
            }
        } while(pinVerify != pin && pinVerify != "A" && pinVerify != "a");
    }

        doubleSecurity = false;
        doubleSecurityKeyword = "Enable";
        mainTitle = "DOUBLE SECURITY DISABLED!\n";
        settingsFunct(balance, pin, doubleSecurity, mainTitle, transactionLogs, logSize, doubleSecurityKeyword);
};

