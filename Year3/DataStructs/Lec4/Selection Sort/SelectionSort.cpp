#include <iostream>
using namespace std;

template <class t>
void selSort(t x[], int n) 
{
    for (int i = 0; i < n; ++i) 
    {
        int smallest_index = i;
        for (int j = i + 1; j < n; ++j) 
        {
            if (x[j] < x[smallest_index]) 
            {
                smallest_index = j;
            }             
        }

        if (i != smallest_index)
            swap(x[i], x[smallest_index]);
    }
}

int main() 
{
    int x[5] = {7, 12, 9, 11, 3};
    selSort<int>(x, 5);

    for (int i = 0; i < 5; ++i) { cout << x[i] << endl;}
}