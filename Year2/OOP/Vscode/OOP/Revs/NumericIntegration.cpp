#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

double integral(function<double(double)> f, double x, double dx) {

    double integral;
    for(x; x <= 1.5; x += dx) {
        integral += f(x)*dx;
    }

    return integral;
}


int main() {

    double dx = 0.00001;
    double x = 1;

    auto f = [](double x) { return log(x); };
    cout << integral(f, x, dx);
}
