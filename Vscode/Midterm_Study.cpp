#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
    
    
    // STARS PROBLEM
    
    /* int size = 4, row, space, star;
    
     for ( row = 1; row <= size; row++) {
        
        for ( space = 1; space <= size - row; space++) {

            cout << "";
        }
        for ( star = 1; star <= 2 * row - 1; star++) {
            cout << "*";
        }
        cout << endl;
    } */

    // EXAM PROBLEM
    
    
    /*  int x = 1;
    do {

        if ( x % 3 != 0) {
            x += 2;
        }
        else {
            x--;
        }
        cout << x << "+";
    } while ( x < 7 && x >= 2); 

    */

   
   
    // logical operators practice
    
    /* int x = 5, y = 4, z = 2, w = 8;  
   bool a = w + 9 != 6 - 1  || 10 % z != x + 0;
   
   cout <<  ( bool )(w + 9 != 6 - 1  || 10 % z != x + 0); */

   // IF, SWITCH AND LOOP PRACTICE


    
    
    
    // GPA CALC USING IF, SWTICH AND FOR LOOP: 
    
   /* char course_grade;
   double GPA;
   double points;
   string general_grade;

   cout << "Please enter the grade of the student in the 6 different courses" << endl;
   for ( int i = 1; i < 7; i++) {

    cout << "course " <<  i << " : ";
    
    cin >> course_grade;
    switch(course_grade) {

        case 'A': points += 4.00; break;
        case 'B': points += 3.30; break;
        case 'C': points += 2.70; break;
        case 'D': points += 2.20; break;
        case 'F': points += 0.00; break;

        default: cout << "Invalid grade " << endl; 
    }
   }

   GPA = points / 6.0;

    if ( GPA >= 3.40 ) {
        general_grade = "Excellent !!";

    }
    else if ( 3.40 > GPA && GPA >= 2.80 ) {
        general_grade = "Very Good AA!";

    }
    else if ( 2.80 > GPA && GPA >= 2.40 ) {
        general_grade = "Good";

    }
    else if ( 2.40 > GPA && GPA >= 2.00) {
        general_grade = "Pass";

    }
    else if ( 2.00 > GPA && GPA >= 1.40) {
        general_grade = "Poor";
    }
    else if ( GPA < 1.40) {
        general_grade = "Very Poor";

    }

    cout << "GPA: " << GPA << endl;
    cout << "General Grade: " << general_grade; */


    // STARS PROBLEM AGAIN LOL:


         int size, rows, space, stars;

         cout << "Please input size: ";
         cin >> size;

        for ( rows = 1; rows <= size; rows++) {

            for ( space = 1; space <= size - rows; space++) {

                cout << "";
            }
            
            for ( stars = 1; stars <= 2 * rows - 1; stars++) {

                cout << "*";
            }
            cout << endl;

            
        } 


    // MATRIX PROBLEM:

        /* int row, coloum;

        for ( coloum = 0; coloum <= 3; coloum++) {

            for ( row = 1; row <= 5; row++) {

                cout << " " << row + ( coloum * 5 ) ;
            }
            cout << endl;
        } */


    // SMALLEST : 

           /*  double smallest;
            double input;

            cout << "Please input ten numbers" << endl;
            cout << "Number 1: ";
            cin >> input;
            smallest = input;

            for ( int i = 2; i <= 10; i++) {
                
                cout << "\nNumber " << i << " : ";
                cin >> input;
                if ( input < smallest) {

                    smallest = input;
                }



            }

            cout << "\nThe smallest number is: " << smallest; */


        // TEST:

 /* 
    int m = 3;

    

    switch (m/3) {

        case 1: m = 5;
        case 2: m + 1; break;

        default: m += 99;
    }

    cout << m; */

    return 0;
}
