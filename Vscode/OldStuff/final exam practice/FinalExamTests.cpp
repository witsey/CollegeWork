#include <iostream>
using namespace std;

int main() 
{
    int m = 2;
    for ( int i = 0; i < 10; i += 4) 
    {

        m += i;
    }

    cout << m;
}