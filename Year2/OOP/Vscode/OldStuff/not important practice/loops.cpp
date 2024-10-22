// Trying loops in general

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    
    
    /* Print's the square of numbers from 1 - 10
    
    
    for (int i = 0; i < 11; i++) {

        
        int square = ( i * i );
        cout << i << " Square is: " << square << endl;



    } 

    
    cout << "All Done!";
         */ 


    for ( int row = 1; row <= 20; row += 5) {

        cout  << "|" << left << setw(5);
        int colvalue = row;
        cout << row;

        for ( int col = 1; col <= 4; ++col) {

            colvalue += 1;
            cout << left << setw(7) << colvalue;
        }

        cout << left << setw(4) << "|" << endl;
    }

}