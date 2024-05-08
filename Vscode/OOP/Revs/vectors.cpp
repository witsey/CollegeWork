#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums = {1, 2, 3, 4, 5};

    nums.pop_back();
    for ( auto num : nums ) {
        cout << num << endl;
    }

    int newValue;

    cin >> newValue;

    nums.push_back(newValue);

    for ( auto num : nums ) {
        cout << num << endl;
    }


    return 0;
}