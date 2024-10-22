// Assignment 4 Problem 2

#include <iostream>
using namespace std;

const int MAXIMUM_ARRAY_SIZE = 100;
int current_size;
int user_array[ MAXIMUM_ARRAY_SIZE ];

void reverse_array( int*, int );


int main() {

    cout << "Input your array size: ";
    cin >> current_size;

    if ( current_size <= 0 || current_size > MAXIMUM_ARRAY_SIZE ) 
    {

        cout << "\nInvalid array size.\n";
        return 1; 
    }


    cout << "\n\nInput your array values: " << endl;

    for ( int i = 0; i < current_size; i++ ) {

        cout << "Value " << i + 1 << " : ";
        cin >> user_array[i];

        cout << "";
    }

    reverse_array( user_array , current_size );

}


void reverse_array( int* input_array, int input_size  ) {

    int *first = input_array;
    int *last = input_array + input_size - 1;

    int temp;
    input_array[ input_size ];

    for ( int i = 0; i < (input_size / 2 ); i++) {

        temp = *first;
        *first = *last;
        *last = temp;

        first++;
        last--;
    }

    cout << "\n\nReverse: ";
    for ( int i = 0; i < input_size; i++ ) {

        cout << input_array[i] << " ";

    }



}
