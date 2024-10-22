#include <iostream>
using namespace std;

template <typename t>
void shellSort(t x[], int n) 
{
    for ( int gap = n / 2; gap > 0; gap /= 2) 
    {
        for (int i = gap; i < n; ++i) 
        {
            t tmp = x[i];
            int j = i;

            for ( ; j >= gap && tmp < x[j - gap]; j -= gap)
                x[j] = x[j - gap];

            x[j] = tmp;
        }
    }

    for (int i = 0; i < 7; ++i)
        cout << x[i] << endl;
}


int main() 
{
    int x[7] = {7, 3, 4, 10, 11, 2, 5};

    shellSort<int>(x, 7);
}