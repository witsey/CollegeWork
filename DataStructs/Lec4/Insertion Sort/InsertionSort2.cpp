#include <iostream>
using namespace std;

template <class t>
void insSort(t x[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        t temp = x[i];
        int insertIndex = i;

        for (int j = i; j > 0 && x[j - 1] > temp; --j) 
        {
            x[j] = x[j - 1];
            insertIndex = j;
        }

        x[insertIndex] = temp;
    }

    for (int i = 0; i < 5; ++i) 
    { 
        cout << x[i] << endl;
    }
}

int main() 
{
    int x[5] = {7, 12, 9, 11, 3};
    insSort<int>(x, 5);
}
