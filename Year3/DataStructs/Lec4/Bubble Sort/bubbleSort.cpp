#include <iostream>
using namespace std;

template <class t>
void bblSort(t x[], int n) 
{
    for (int i = n - 1; i > 0; --i) 
    {
        for (int j = 0; j < i; ++j) 
        {
            if (x[j] > x[j + 1])
                swap(x[j], x[j + 1]);
        }
    }
}

int main() 
{
    int x[5] = {7, 12, 9, 11, 3};
    bblSort<int>(x, 5);

    for (int i = 0; i < 5; ++i) { cout << x[i] << endl;}
}