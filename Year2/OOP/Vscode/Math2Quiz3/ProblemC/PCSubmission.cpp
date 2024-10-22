#include <iostream>

using namespace std;

int n;

double integral(int n) {
    if (n == 1)
        return -2.0 / 3;
    else
        return (-2.0 * n / (2 * n + 1)) * integral(n - 1);
}

int main() {
    cin >> n;
    double result = integral(n);
    cout << result << endl;
    return 0;
}
