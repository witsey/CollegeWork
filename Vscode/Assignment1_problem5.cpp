#include <iostream>
#include <iomanip>


using namespace std;

int main() {

    double num1, num2;
    double result;
    char operation;


    cout << "Please enter 2 numbers" << endl;
    
    cout << "\nNumber 1: ";
    cin >> num1;

    cout << "Number 2: ";
    cin >> num2;

    cout << "\n( + ) for addition, ";
    cout << "( - ) for subtraction " << endl;

    cout << "\n( * ) for multiplication, ";
    cout << "( / ) for division ";

    cout << "\nPlease choose the type of operation you want to peform with these 2 number: ";
    cin >> operation;

    switch (operation) {

        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': result = num1 / num2; break;

        default: cout << "Invalid operation choice";
    
    }

    cout << "\nresult: " << result;
    



}