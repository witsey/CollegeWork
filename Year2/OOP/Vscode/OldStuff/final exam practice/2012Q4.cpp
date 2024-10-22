#include <iostream>
using namespace std;


int main(){

    int num;
    int factorial = 1;

    cout << "Input a number to get its factorial: ";
    cin >> num;

    for ( int i = 1; i <= num; i++ ) {

        factorial *= i;

    }

    cout << "\n" << factorial;
    

}
