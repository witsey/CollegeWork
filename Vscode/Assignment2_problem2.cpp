#include <iostream>
using namespace std;

int user_array[] {};
int array_size;

int main() {
    
    cout << "Please input the size of your array: ";
    cin >> array_size;
    
    cout << "\n\ninput your array values: " << endl;
    
    
    for ( int i = 0; i < array_size ; i++) {
        
       cout << "Value " << i + 1 << " : ";
       cin >> user_array[i];
       
    }

    cout << "\nMenu: " << endl << "\n1.Add contents of the array \n\n2.multiply the contents of the array \n\n3.get the factorial of each element in the array \n\n4.get the Fibonacci value for each element in the array \n\n5.exit the program." << endl << "\n\nPlease choose an option from the menu by entering its number: ";
    
        
}