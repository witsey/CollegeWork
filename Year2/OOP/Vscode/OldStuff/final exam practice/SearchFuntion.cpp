#include <iostream>
using namespace std;

bool search(int[], int, int );

int main() 
{   
    int target;
    bool index;
    const int size = 10;
    int nums[size] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 };

    cout << "Input target: ";
    cin >> target;

    index = search(nums, size, target );
    cout << "target index is: " << boolalpha << index;
}

bool search(int list[], int size, int target ) 
{

    for ( int i = 0; i < size; i++ ) 
    {
        
        if ( list[i] == target ) 
            return true;

    }

    return false;

}