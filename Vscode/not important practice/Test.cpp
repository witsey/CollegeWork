#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {

    // Variables
    double my_age = 18.005;
    int x, y;

    // Doing stuff
    cout << "I'm Akram and I'm ";
    cout << fixed << setprecision(0) << my_age;
    cout << "\n2+2 = " << 2 + 2 << endl;
    cout << 14 % 4 << endl; 

    cout << "Enter x, y separated by space: ";
    cin >> x >> y;
    cout << x << " " << y << " ";




    return 0;
}
