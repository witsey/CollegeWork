#include <iostream>
#include <cstring>
using namespace std;

int main() {

    char *array;
    array = new char[10];

    array = "Hello";

    cout << array[4];
}