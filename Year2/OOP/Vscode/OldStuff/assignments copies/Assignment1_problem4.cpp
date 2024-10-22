#include <iostream>
#include <iomanip>


using namespace std;

int main() {

    char course1_grade, course2_grade, course3_grade, course4_grade, course5_grade, course6_grade;
    double points = 0.00;
    double GPA;
    string general_grade;

    cout << "Please enter the grade for each of the 6 courses: ";
    
    cout << "\nCourse 1 grade: ";
    cin >> course1_grade;

    switch ( course1_grade ) {

        case 'A': points += 4.00; break;
        case 'B': points += 3.30; break;
        case 'C': points += 2.70; break;
        case 'D': points += 2.20; break;
        case 'F': points += 0.00; break;

        default: cout << "Invalid grade"; 
    }

    cout << "Course 2 grade: ";
    cin >> course2_grade;

    switch ( course2_grade ) {

        case 'A': points += 4.00; break;
        case 'B': points += 3.30; break;
        case 'C': points += 2.70; break;
        case 'D': points += 2.20; break;
        case 'F': points += 0.00; break;

        default: cout << "Invalid grade"; 
    }

    cout << "Course 3 grade: ";
    cin >> course3_grade;

    switch ( course3_grade ) {

        case 'A': points += 4.00; break;
        case 'B': points += 3.30; break;
        case 'C': points += 2.70; break;
        case 'D': points += 2.20; break;
        case 'F': points += 0.00; break;

        default: cout << "Invalid grade "; 
    }

    cout << "Course 4 grade: ";
    cin >> course4_grade;

    switch ( course4_grade ) {

        case 'A': points += 4.00; break;
        case 'B': points += 3.30; break;
        case 'C': points += 2.70; break;
        case 'D': points += 2.20; break;
        case 'F': points += 0.00; break;

        default: cout << "Invalid grade "; 
    }

    cout << "Course 5 grade: ";
    cin >> course5_grade;

    switch ( course5_grade ) {

        case 'A': points += 4.00; break;
        case 'B': points += 3.30; break;
        case 'C': points += 2.70; break;
        case 'D': points += 2.20; break;
        case 'F': points += 0.00; break;

        default: cout << "Invalid grade "; 
    }

    cout << "Course 6 grade: ";
    cin >> course6_grade;

    switch ( course6_grade ) {

        case 'A': points += 4.00; break;
        case 'B': points += 3.30; break;
        case 'C': points += 2.70; break;
        case 'D': points += 2.20; break;
        case 'F': points += 0.00; break;

        default: cout << "Invalid grade "; 
    }

    GPA = points / 6.0;

    if ( GPA >= 3.40 ) {
        general_grade = "Excellent";

    }
    else if ( 3.40 > GPA && GPA >= 2.80 ) {
        general_grade = "Very Good";

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

    cout << "\nThe GPA is: " << GPA;
    cout << "\nand the general grade is: " << general_grade;



    return 0;

}