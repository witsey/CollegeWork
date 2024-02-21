#include <iostream>
using namespace std;

int main() 
{
    int i = 15, j = 25, *pi, *pj;
    pj = &j;
    *pj = j * 3;
    i = *pj + 25;
    pi = pj;
    *pi = i + 4 * j;

    cout << *pj;
}