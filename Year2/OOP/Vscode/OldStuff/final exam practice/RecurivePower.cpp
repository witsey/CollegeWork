#include <iostream>

using namespace std;

int f1(int inp_num, int power ) 
{

    if ( power == 1 )
        return inp_num;

    return inp_num * f1( inp_num, power - 1);

} 


int main() 
{
    int num;
    int result;
    int power;

    cout << "Enter a number: ";
    cin >> num;
    
    cout << "\nEnter power: ";
    cin >> power;

    result = f1(num, power);
    cout << "\n" << result;

}   