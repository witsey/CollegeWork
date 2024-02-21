#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    char grade;

    char grades[5]  { 'A' , 'B' , 'C' , 'D' , 'F' };
    double points[5] { 4.00 , 3.30 , 2.70 , 2.20 , 0.0 };

    cout << "Enter grade for course to know how many points it worth (A, B, C, D, or F): ";
    cin >> grade;

    for ( int i = 0; i < 5; i++ ) {

        if ( grades[i] == grade ) {

            cout << fixed << setprecision(2);
            cout << "\n\n" << grade << " Worths " << points[i] << " Points.";
                
        }
    }
        
    return 0;
}