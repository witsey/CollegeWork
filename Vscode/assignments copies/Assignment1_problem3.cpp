#include <iostream>
#include <iomanip>


using namespace std;

int main() {

    int choice;
    double area;
    double perimeter;


    
    cout << "Menu of Shapes: " << endl;
    cout << "\n1.Square  ";
    cout << "2.Rectangle  " << endl;
    cout << "3.Circle  ";
    cout << "4.Triangle  " << endl;
    cout << "\nPlease enter a number from the menu of shapes: ";
    cin >> choice;

    if ( choice == 1) {

        // square
        
        double side_length;

        cout << "\nPlease enter the length of your square side (centimeters): ";
        cin >> side_length;

        area = side_length * side_length;
        perimeter = 4 * side_length;

        cout << "\nYour square area is: " << area << " square cm" << endl;
        cout << "Your square perimeter is: " << perimeter << "cm" << endl;



    }
    else if ( choice == 2) {

        // rectangle
        
        double length;
        double width;

        cout << "\nPlease enter the length of your rectangle (centimeters): ";
        cin >> length;

        cout << "Please enter the length of your rectangle (centimeters): ";
        cin >> width;

        area = length * width;
        perimeter = ( 2 * length) + ( 2 * width);

        cout << "\nYour rectangle area is: " << area << " square cm" << endl;
        cout << "Your rectangle perimeter is: " << perimeter << "cm" << endl;






    }
    else if ( choice == 3) {

        // triangle
        
        double base;
        double height;

        double side1, side2, side3;

        cout << "\nPlease enter the base of your triangle (centimeters): ";
        cin >> base;

        cout << "Please enter the height of your triangle (centimeters): ";
        cin >> height;

        cout << "\nPlease enter the lengths of the three sides of your triangle (centimeters)" << endl;
        
        cout << "Side 1: ";
        cin  >> side1;
        
        cout << "Side 2: ";
        cin >> side2;
        
        cout << "Side 3: ";
        cin >> side3;

        area = ( 0.5 ) * base * height;
        perimeter = side1 + side2 + side3;

        cout << "\nYour triangle area is: " << area << " square cm" << endl;
        cout << "Your triangle perimeter is: " << perimeter << "cm" << endl;


        


    }
    else if ( choice == 4) {
        
        // circle
        
        const double PI = 3.141549;
        double radius;
        double circumference;

        cout << "\nPlease enter the radius of your circle: ";
        cin >> radius;

        area = PI  * ( radius * radius );
        circumference = 2 * PI * radius;

        cout << "\nYour circle area is: " << area << " square cm" << endl;
        cout << "Your circle circumference is: " << circumference << "cm" << endl;

        






    }
    else {
        cout << "Invalid choice";
    }

}