#include <iostream>
using namespace std;

const int MAX_COLS = 100;
const int MAX_ROWS = 100;

int arry_rows;
int arry_cols;

int** arry;

void initialize_arrays() {

    arry = new int* [ MAX_ROWS ];


    for (int i = 0; i < MAX_ROWS; ++i) 
    {
        arry[i] = new int [ MAX_COLS ];

    }
}