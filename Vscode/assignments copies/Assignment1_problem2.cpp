#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int number;
    
    
    cout << "Please enter a number ( integer ) and the program will detect if it's Even or Odd: ";
    cin >> number;

    if ( number % 2 == 0) {

        cout << "Number " << number << " is Even.";
    }
    else {

        cout << "Number " << number << " is Odd.";
    }

     return 0;
}