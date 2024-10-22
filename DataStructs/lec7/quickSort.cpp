#include <iostream>
using namespace std;

template <typename t>
int partition(t array[], int left, int right) 
{
    t pivot = array[left];
    int i = left;
    int j = right;

    while(i < j) 
    {
        do 
        {
            ++i;
        } while (array[i] < pivot);

        do 
        {
            --j;
        } while (array[j] > pivot);
        
        if (i < j) 
        {
            swap(array[i], array[j]);
        }
    }

    swap(array[left], array[j]);
    return j;
}

template <typename t>
void quickSort(int array[], int left = 0, int right = 8)
{
    if (left < right) 
    {
        int j = partition<t>(array, left, right);
        quickSort<t>(array, left, j);
        quickSort<t>(array, j + 1, right);
    }
}

int main() 
{
    int nums[6] = {8, 10, 6, 5, 9, 11};
    quickSort<int>(nums);
    
    for (int i = 0; i < 6; ++i) 
    {
        cout << nums[i] << endl;
    }  
}