#include <iostream>
using namespace std;

class BankAccount {

private:
    double balance;
    int accountNumber;
    inline static int HighestBalance = 0;
    inline static int index = 0;

public:
    BankAccount() : balance(0), accountNumber( index + 1 ) { index++; } // Default

    BankAccount( double balance , int accountNumber ) {
        this->balance = balance;
        this->accountNumber = accountNumber;

        if ( balance > HighestBalance )
            HighestBalance = balance; 
    }

    void setBalance( double givenBalance ) {
        balance = givenBalance;

        if ( givenBalance > HighestBalance )
            HighestBalance = givenBalance; 
    }

    void setAccountNumber( int givenAccountNumber ) {
        accountNumber = givenAccountNumber;
    }

    double getBalance() const {
        return balance;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    void operator+=( double additionValue ) {
        balance += additionValue;

        if ( this->balance > HighestBalance )
            HighestBalance = this->balance;
    }

    BankAccount operator+( int additionNumber ) {
        BankAccount newBankAccount;

        newBankAccount.accountNumber = this->accountNumber + additionNumber; 
        return newBankAccount;
    }

    bool operator>( BankAccount other ) {
        
        if (this-> balance > other.balance )
            return true;
        else
            return false;
    }

    bool operator<( BankAccount other ) {
        
        if (this-> balance < other.balance )
            return true;
        else
            return false;
    }

    bool operator=( BankAccount other ) {
        
        if (this-> accountNumber == other.balance )
            return true;
        else
            return false;
    }

    friend ostream& operator<< ( ostream& output, const BankAccount Account ) {
        output << "Account Number: " << Account.accountNumber << " Balance: " << Account.balance;
        return output;
    }

    friend istream& operator>> ( istream& input, BankAccount Account ) {
        input >> Account.accountNumber >> Account.balance;

        if ( Account.balance > HighestBalance )
            HighestBalance = Account.balance;

        return input;
    }

};



int main() {
    BankAccount accounts[5];
    BankAccount *account;

    BankAccount a1(100, 5);

    account = &a1;

    cout << account->getAccountNumber() << endl;

}

void deposit() {
    
    int depositValue;
    
    cout << "Enter deposit value : ";
    cin >> depositValue;

}