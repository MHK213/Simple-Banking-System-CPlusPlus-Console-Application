#include <iostream>

using namespace std;

// Enum: enTransaction
// Defines the available transaction types in the system.
enum enTransaction { Balance = 1, DepositAmount = 2, WithdrawAmount = 3, Exit = 0};

// Function: ReadPinCode
// Purpose: Prompts the user with a message and reads the PIN code as a string.
// Returns: The entered PIN code.
string ReadPinCode(string Message) {
    string PinCode;
    cout << Message;
    cin >> PinCode;

    return PinCode;
}

// Function: ReadPositiveNumber
// Purpose: Prompts the user to enter a positive float number.
// Keeps asking until a non-negative number is entered.
float ReadPositiveNumber(string Message) {
    float Number;

    do {
        cout << Message;
        cin >> Number;
    } while (Number < 0);

    return Number;
}

// Function: Login
// Purpose : Authenticates the user by verifying the entered PIN against a stored PIN.
// Returns : true if the correct PIN is entered within 3 attempts, false otherwise.
bool Login() {
    const string TruePinCode = "1234";
    int Counter = 3;
    string PinCode;
    do {
        PinCode = ReadPinCode("Enter your PinCode? \n");
        if (PinCode == TruePinCode) {
            return true;
        }
        else {
            system("color 4F");
            Counter--;
            cout << "Wrong Pin, you have " << Counter << " more tries\n" << endl;
        }
    } while (Counter != 0 && PinCode != "1234");

    return false;
}

// Function: TransactionMenu
// Purpose: Displays the list of available banking operations.
void TransactionMenu() {
    cout << "Welcome to our Banking System: \n";
    cout << "******************************\n\n";
    cout << "choose your operation? \n";
    cout << "(1) Check account balance\n";
    cout << "(2) Deposit money\n";
    cout << "(3) Withdraw money\n";
    cout << "(0) Exit\n";
    cout << "******************************" << endl;
}

// Function: ReadUserOperationChoice
// Purpose: Reads the user's menu choice and casts it to enTransaction.
enTransaction ReadUserOperationChoice() {
    float UserChoice = ReadPositiveNumber("Enter number of your operation (1 / 2 / 3 / 0)?\n");
    return (enTransaction)UserChoice;

}

// Function: CheckBalance
// Purpose: Returns the current balance (passed by reference).
float CheckBalance(float& Balance) {
    return Balance;
}

// Function: Deposit
// Purpose: Adds a deposit amount to the balance.
// Returns the new balance.
float Deposit(float& Balance) {
    float DepositAmount = ReadPositiveNumber("Enter the amount you want to deposit? \n");

    return  Balance+= DepositAmount;
}

// Function: Withdraw
// Purpose: Subtracts a withdrawal amount from the balance
// after verifying sufficient funds.
// Returns the new balance.
float Withdraw(float& Balance) {
    float WithdrawAmount = ReadPositiveNumber("Enter the amount you want to withdraw? \n");
    while (WithdrawAmount > Balance) {
        cout << "Insufficient balance.\n";
        WithdrawAmount = ReadPositiveNumber("Enter the amount you want to withdraw? \n");
    }

    return Balance -= WithdrawAmount;
}

// Function: PrintOperation
// Purpose: Executes the chosen transaction and prints the result.
void PrintTransaction(enTransaction TransactionOperation, float& Balance) {

    switch (TransactionOperation) {
    case enTransaction::Balance:
        cout << "Your Balance account is : " << CheckBalance(Balance) << endl << endl;
        break;
    case enTransaction::DepositAmount:
        cout << "Your Balance account after your deposit operation is : " << Deposit(Balance) << endl << endl;
        break;
    case enTransaction::WithdrawAmount:
        cout << "Your Balance account after your withdraw operation is : " << Withdraw(Balance) << endl << endl;
        break;
    case enTransaction::Exit:
        cout << "Thank you for using our system.\n";
        break;
    default:
        cout << "Wrong Input\n";
        break;
    }
}

int main()
{
    float Balance = 7500;
    if (Login()) {
        system("color 2F");
        enTransaction UserChoice;
        do {
            TransactionMenu();
            UserChoice = ReadUserOperationChoice();
            PrintTransaction(UserChoice, Balance);
        } while (UserChoice != Exit);
    }
    else {
        cout << "\nYour card is blocked.\nCall the bank for help.\n";
    }

    return 0;
}