#include <iostream>
using namespace std;

// Array Declaring

int const MAX_ARRAY_SIZE = 100;
int user_array[ MAX_ARRAY_SIZE ]  {};
int array_size;

bool first_time = true;


// Functions Prototypes

void summation();
void multiplication();

int factorial( int f );
void factorial_output();

int fibonacci( int n );
void fibonacci_output();

void back_to_main();


// Program


int main() {

    if ( first_time ) {

        // Creating the array

        cout << "Input the size of your array: ";
        cin >> array_size;

        cout << "\n\ninput your array values: " << endl;


        for (int i = 0; i < array_size; i++) {

        cout << "Value " << i + 1 << " : ";  
        cin >> user_array[i];

        }

        first_time = false;
    }

    // Menu

    cout << "Menu: " << endl << "\n1.Add contents of the array \n2.multiply the contents of the array \n3.get the factorial of each element in the array \n4.get the Fibonacci value for each element in the array \n5.exit the program." << endl << "\n\nPlease choose an option from the menu by entering its number: ";
    
    int option;
    cin >> option;

    switch ( option ) {
    
        case 1: {

            summation();
        }
        break;


        
        case 2: {
            
            multiplication();
        }
        break;

        case 3: {

            factorial_output();
        }
        break;

        case 4: {

            fibonacci_output();
        }
        break;

        case 5: {

            cout << "\n\nThank you for using the program!";
            return 0;
        }
    }

}


void summation() {

    int sum;

    for (int i = 0; i < array_size; i++) {
        
        sum += user_array[i];

    }
    
    cout << "The summation of all elements in the array is : " << sum << endl;

    back_to_main();
}


void multiplication() {

    int product = 1;
    
    for (int i = 0; i < array_size; i++) {
            
        product *= user_array[i];

    }

    cout << "\nThe product of all values in your array is: " << product << endl;
    
    back_to_main();

}


int factorial( int f ) {

    if ( f == 1 || f == 0) {

        return 1;
    }
    
    else if ( f > 1) { 

        return f * factorial( ( f - 1 ) );
    }

    else {

        cout << "negative numbers don't have factorials. ";
        return 0;
    }
}


void factorial_output() {

    int factor;

    for ( int i = 0; i < array_size; i++) {

        factor = factorial( user_array[i] );
        
        cout << "\nFactorial of " << user_array[i] << " is " << factor;

    }

    cout <<"\n\n";

    back_to_main();
}


int fibonacci( int n ) {

    if ( n == 0 || n == 1 ) {

        return 1;
    }

    return ( fibonacci( n - 1 ) + fibonacci ( n - 2) );
}


void fibonacci_output() {

    int fibo;

    for ( int i = 0; i < array_size; i++) {

        fibo = fibonacci( user_array[i] );
        cout << "\nthe fibonacci of " << user_array[i] << " is " << fibo;

    }

}


void back_to_main() {

    char back;

    cout << "\nWould you like to return back to the main menu? ( y for yes, n for no)";

    do {
    
    cout << ": ";
    cin >> back;
    
    if ( back == 'y' ) {

        main();
    }

    else if ( back == 'n') {

        cout << "\nThank you for using the program." << endl;
        break;
    }

    else {

        cout << "\nInvalid choice Please choose 'y' for yes or 'n' for no " << endl;
    }


    } while ( back != 'y' || back != 'n');
}

