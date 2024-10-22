#include <iostream>
using namespace std;

void function( int[], int);

int main() 
{
    int nums[3] = {1 , 2 , 3};
    int *numsP;
    numsP = &nums[1];

    function(nums, 1);


}

void function(int array[], int target) 
{
    cout << array[ target ];
}