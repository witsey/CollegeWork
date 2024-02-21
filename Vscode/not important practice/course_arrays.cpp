#include <iostream>
#include <iomanip>
using namespace std;



int main() {

    int n;
    int group[10];
    int sum;

    cout << "size of array: ";
    cin >> n;

    /* 

    for ( int i = 1; i <= 10; i++) {

        cout << "\ninput index " << i << " : ";
        cin >> group[i];

    }

    cout << "\nyour array: " << endl;

    for ( int i = 1; i <= 10; i++) {

        cout << "\nindex " << i << " : " << group[i] << endl;
    } 

    */

    for ( int i : group) {

        i = 0;
        i += 1;
        cout << i;
    }

    return 0;

}
