// Lab7 Task 6

#include <iostream>
#include <iomanip>
using namespace std;


void calc_matrix(int input_matrix[][4]) {

    int i, j, sum = 0;
    
    for ( i = 0; i < 4; i++, j++) {


        sum += input_matrix[i][j];
    }

    cout << endl;
    cout << sum;
}

int main() {
   //6.

   int matrix [4][4];

   // Taking Input:


   for ( int i = 0; i < 4; i++) {

    cout << "\nPlease input the 4 elements for the " << i + 1 << " row in the matrix" << endl;

    for ( int j = 0; j < 4; j++) {

        cout << "Element " << j + 1 << " : ";
        cin >> matrix [i][j];
    }
   }

    // displaying the matrix

    for ( int i = 0; i < 4; i++) 
    {

        for ( int j = 0; j < 4; j++) 
        {

            cout << setw(5) << matrix [i][j];
        }

        cout << endl;
    }

    cout << "\nThe sum is: ";
    calc_matrix(matrix);
}