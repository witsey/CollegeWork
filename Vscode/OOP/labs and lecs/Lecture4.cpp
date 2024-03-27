#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // decrement and increment stuff

    /* 
    int i = 1;

    while ( i <= 1) {

        if ( ++i > 1)
            cout << i;
        else
            cout << "Nothing";
    }  
    */

    
    // testing switch
    
    int numb = 5;
    int x = 0;
    cout << "Please enter a number ";
    cin >> x;

    switch (numb) {

        case (5): cout << "You've entered number 5 \n"; break;
        case (4): cout << "You've entered a number greater than 5 \n"; break;
        case (3): cout << "You've entered a number smaller than 5 \n"; break;

    }


    

    return 0;
}