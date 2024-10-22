#include <iostream>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

int arry1_rows;
int arry1_cols;

int arry2_rows;
int arry2_cols;

int** array1;
int** array2;
int** sumOfMatrices;
int** product_matrix;

// Prototypes

void initialize_arrays();
void sumMatrices();
void multiplyMatrices();
void transposeMatrices();
void clean_memory();
void transposeMatrices( int**, int , int );

// Program

void initialize_arrays() {

    array1 = new int* [ MAX_ROWS ];
    array2 = new int* [ MAX_ROWS ];


    for (int i = 0; i < MAX_ROWS; ++i) 
    {
        array1[i] = new int [ MAX_COLS ];
        array2[i] = new int [ MAX_COLS ];
    }
}


int main() {

    initialize_arrays();

    int choice;

    cout << "Please input your first array rows and colums";
    
    cout << "\nArray 1 Rows: ";
    cin >> arry1_rows;

    cout << "Array 1 Colums: ";
    cin >> arry1_cols;

    cout << "\nNow enter your second array rows and colums";
    
    cout << "\n\nArray 2 Rows: ";
    cin >> arry2_rows;

    cout << "Array 2 Colums: ";
    cin >> arry2_cols;

    cout << "\n\nInput you first array elements:" << endl;
    
    for (int i = 0; i < arry1_rows; ++i) 
    {
        
        for (int j = 0; j < arry1_cols; ++j) 
        {
            
            cout << "Value: (" << i + 1 << "," << j + 1 << "): ";
            cin >> array1[i][j];

        }
    }

    cout << "\n\nInput you second array elements:" << endl;
    
    for (int i = 0; i < arry2_rows; ++i) 
    {
        
        for (int j = 0; j < arry2_cols; ++j) 
        {
            
            cout << "Value: (" << i + 1 << "," << j + 1 << "): ";
            cin >> array2[i][j];

        }
    }

    cout << "\n\n<< Menu >>";

    cout << "\n\n1.Sum the 2 matricies\t2.Multiply the 2 matricies\n\n3.Transpose the 2 matricies";

    cout << "\n\nPlease choose one of the following options by inputing the option number: ";
    cin >> choice;

    switch ( choice ) {

        case 1: 
        {

           sumMatrices();

        } break;

        case 2: 
        {

            multiplyMatrices();

        } break;

        case 3: 
        {
            int matrix_num;

            cout << "\n\nPlease choose which matrix you want to transpose ( 1 or 2 ): " ;
            cin >> matrix_num;

            switch ( matrix_num ) {

                case 1: {
                    
                    transposeMatrices( array1, arry1_rows , arry1_cols );
                } break;

                case 2: {

                    transposeMatrices( array2, arry2_rows , arry2_cols );
                } break;

                default: {

                    cout << "\nInvalid Choice.";
                }
            }
            

        } break;

        default: 
        {
            cout << "Invalid choice";
            clean_memory();
        }


    }

}


void sumMatrices() {



    if (  arry1_rows != arry2_rows  ||  arry1_cols != arry2_cols  ) {

        cout << "Matrices must have the same number of rows and columns for addition.";
        return;
    }

    sumOfMatrices = new int*[arry1_rows];
    
    for (int i = 0; i < arry1_rows; ++i) {

        sumOfMatrices[i] = new int[ arry1_cols ];
    }

    for (int i = 0; i < arry1_rows; i++) 
    {
        
        for (int j = 0; j < arry1_cols; j++ ) 
        {
            
            sumOfMatrices[i][j] = array1[i][j] + array2[i][j];
        }
    }

    for ( int i = 0; i < arry1_rows; i++) {

        for ( int j = 0; j < arry1_cols; j++ ) {

            cout << sumOfMatrices[i][j] << " ";
        }

        cout << endl;
    }

    clean_memory();
    return;

}


void multiplyMatrices() {

    if (arry1_cols != arry2_rows) 
    
    {
        cout << "sorry, The number of columns in your first matrix must equal the number of rows in your matrix." << endl;
        return;
    }

    product_matrix = new int* [ MAX_ROWS ];

    for ( int i = 0; i < arry1_rows; i++) {

        product_matrix[i] = new int[arry2_cols];
    }


    for (int i = 0; i < arry1_rows; ++i) 
    {
        for (int j = 0; j < arry2_cols; ++j) 
        {
            product_matrix[i][j] = 0;
            for (int k = 0; k < arry1_cols; ++k) 
            {
                product_matrix[i][j] += ( array1[i][k] * array2[k][j] );

            }
        }
    }
    
    cout << "\n\nThe product of your matracies is: " << endl << endl;
    for (int i = 0; i < arry1_rows; ++i) 
    {
        for (int j = 0; j < arry2_cols; ++j) 
        {
            cout << product_matrix[i][j] << " ";

        }

        cout << endl;
    }

    for ( int i = 0; i < arry1_rows; i++ ) {

        delete[] product_matrix[i];
    }

    delete[] product_matrix;

    clean_memory();
}


void transposeMatrices( int** input_matrix , int rows, int cols ) {

    int** transposed_matrix = new int*[cols];
    
    for ( int i = 0; i < cols; i++ ) {

        transposed_matrix[i] = new int[rows];

    }

    for ( int i = 0; i < cols; i++ ) {

        for ( int j = 0; j < rows; j++ ) {

            transposed_matrix[i][j] = input_matrix[j][i];
        }
    }

    cout << "\n\nTranspose: " << endl;

    for ( int i = 0; i < cols; i++ ) {

        for ( int j = 0; j < rows; j++ ) {

            cout << transposed_matrix[i][j] << " ";
        }

        cout << endl;
    }

    for ( int i = 0; i < cols; i++ ) {
        
        delete[] transposed_matrix[i];
    }
    
    delete[] transposed_matrix;

    clean_memory();
}


void clean_memory() {
    
    for (int i = 0; i < MAX_ROWS; ++i) 
    {
        delete[] array1[i];
        delete[] array2[i];
        delete[] sumOfMatrices[i];
    }
    
    delete[] array1;
    delete[] array2;
    delete[] sumOfMatrices;
}

