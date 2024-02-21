#include <iostream>

using namespace std;

int main() 
{

    for (int i = 0; i < 5; i++ ) 
    {
        for ( int k = 0; k < 5 - ( i + 1 ); k++) 
        {

            cout << " ";
        } 


        for ( int j = 0; j < i * 2 + 1; j++ ) 
        {

            cout << "*";
        }

        cout << endl;

    }

}

