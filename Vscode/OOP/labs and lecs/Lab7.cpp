// Lab7

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

    //4. 

    /*
    char grades[] {'A', 'B', 'C', 'D', 'E'};
    float points[] {4.00, 3.30, 2.70, 2.20, 0.0};

    char target;

    cout << "Enter the grade that you want to know how many points it worth: ";
    cin >> target;

    for ( int i = 0; i < ( end(grades) - begin(grades) ); i++) {

        if ( target == grades[i] ) {

            cout << grades[i] << " is worth " << fixed << setprecision(2) << points[i] << " points";
            break;
        }
    }
    */


   //6.

   int matrix [4][4];

   // Taking Input:


   for ( int i = 0; i < 4; i++) {

    cout << "\nPlease input the 4 elements for the " << i + 1 << " row in the matrix: ";

    for ( int j = 0; j < 4; j++) {

        cin >> matrix [i][j];
    }
   }

   for ( int i = 0; i < 4; i++) {

    for ( int j = 0; j < 4; j++) {

        cout << setw(5) << matrix [i][j];
    }

    cout << endl;
   }

   calc_matrix(matrix);
}