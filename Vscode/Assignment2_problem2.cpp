#include <iostream>
using namespace std;

int user_array[] {};
int array_size;

int main() {
    
    cout << "choose the array_size of your array: ";
    cin >> array_size;
    
    cout << "\n\ninput your array values: ";
    
    
    for ( int i = 0; i < array_size ; i++) {
        
       cin >> user_array[i];
       
    }
    
    cout << "Menu: " << endl << "\n 1.Add contents of the array \t2.multiply the contents of the array \n 3.get the factorial of each element in the array \t4.get the Fibonacci value for each element in the array \n 5.exit the program." << endl << "\n\nPlease choose an option from the menu by entering its number: ";
    
        
}