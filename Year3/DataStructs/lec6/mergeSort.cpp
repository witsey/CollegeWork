#include <iostream>
using namespace std;


template <typename t>
void merge(t x[], int left, int middle, int right) 
{
    int n1 = ( middle - left ) + 1;
    int n2 = right - middle;

    t l[n1], r[n2];

    for (int i = 0; i < n1; ++i) {l[i] = x[left + i];}
    for (int j = 0; j < n2; ++j) {r[j] = x[middle + 1 + j];}

    int k = left;

    int i = 0;
    int j = 0;

    while (i < n1 && j < n2) 
    {
        if (l[i] < r[j])
            x[k++] = l[i++];

        else
            x[k++] = r[j++];
    }

    while (i < n1)
        x[k++] = l[i++];
    
    while (j < n2)
        x[k++] = r[j++];
}

template <typename t>
void mergeSort(t x[], int left, int right) 
{
    if (left >= right )
        return;
    
    else 
    {
        int middle = (left + right) / 2;

        mergeSort(x, left, middle);
        mergeSort(x, middle + 1, right);
        merge<t>(x, left, middle, right);
    }
        

}



int main() 
{
    int x[7] = {7, 3, 4, 10, 11, 2, 5};

    mergeSort<int>(x, 0, 7);

    for (int i = 0; i < 7; ++i)
        cout << x[i] << endl;
}