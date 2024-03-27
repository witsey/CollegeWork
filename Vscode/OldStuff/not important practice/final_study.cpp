#include <iostream>

using namespace std;

int fun(int*& p, int* q) {
    *p = 12;
    p = p + 3;
    q = p - 1;
    *q = *(p + 1) + *q;
    *p += 2;

    cout << "p=" << *p << " q=" << *q << "\n";

    return (*q) % (*p);
}

int main() {
    int y[5] = {1, 2, 3, 4, 5};
    int* p = y;
    int* q = new int;  // Assuming there was a typo and "= new int;" was meant to be "int* q = new int;"

    *q = fun(p, q);

    for (int i = 0; i < 5; i++) {
        cout << y[i] << " ";
    }

    cout << "\np= " << *p << " p = " << *q;

    delete q;  // Free the memory allocated for q
    return 0;
}
