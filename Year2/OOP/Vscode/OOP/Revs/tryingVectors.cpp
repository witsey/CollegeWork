#include <iostream>
#include <vector>
#include <array>

using namespace std;

void changeVector(vector<int>&);
void printVector(vector<int>&);

int main() 
{
    vector<int> nums = {1, 2, 3 ,4 ,5};
    nums.push_back(6);
    nums.push_back(7);

     for ( auto num : nums ) {
        cout << num << endl;
    }

    cout << nums[0];

    cout << endl << endl;

    changeVector(nums);
}

void changeVector(vector<int>& nums /* Passed by Reference so the function changes the original values */) 
{
    nums = {10, 1, 2 ,3, 4};
    printVector(nums);
}

void printVector(vector<int>& nums) 
{
    for ( auto num : nums ) {
        cout << num << endl;
    }
}