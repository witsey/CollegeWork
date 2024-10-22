// poniters

#include <iostream>
using namespace std;

int main() {

    int array[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int *p_array = array;
    
    char *p_message { "Hello World!" };
    int* p_num;

    int x = 32;
    p_num = &x;
    
    
    cout << "Output 1: " << (p_message);
    cout << "\nOutput 2: " << *(p_array + 1);
    cout << "\nOutput 3: " << *p_num;

    cout << "\nOutput 4: ";

    for (int i = 0; i < 10; i++) {

        cout << p_message[i] << "----";
    }
}