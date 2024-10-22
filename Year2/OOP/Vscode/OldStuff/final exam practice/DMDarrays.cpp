#include <iostream>
#include <iomanip>

using namespace std;

int rows, cols;
int const MAX_ROWS = 100, MAX_COLS = 100;
int **matrix2d;
int **transposed_matrix;


void init_arrays() 
{

    matrix2d = new int *[MAX_ROWS];
    transposed_matrix = new int *[MAX_ROWS];

    for ( int i = 0; i < MAX_ROWS; ++i ) 
    {

        matrix2d[i] = new int [MAX_COLS];
        transposed_matrix[i] = new int[MAX_COLS];

    }

}


int main()
{

    init_arrays();
 
    cout << "rows: ";
    cin >> rows;

    cout << "cols: ";
    cin >> cols;

    cout << endl;

    for ( int i = 0; i < rows; i++ ) 
    {
        
        for ( int j = 0; j < cols; j++ ) 
        {

            cout << "[" << i + 1 << "  " << j + 1 << "]: ";
            cin >> matrix2d[i][j];            
        }

        cout << endl;
        
    }

    cout << "\nMatrix:" << endl;

    for ( int i = 0; i < rows; i++ ) 
    {
        for ( int j = 0; j < cols; j++ ) 
        {

            cout << matrix2d[i][j] << "  ";            
        }

        cout << endl;
        
    }


    for ( int i = 0; i < cols; i++ ) 
    {

        for ( int j = 0; j < rows; j++ ) 
        {
            {
                transposed_matrix[i][j] = matrix2d[j][i];

            }
            
        }
    }
    
    cout << "\nTranspose Matrix:" << endl;

    for ( int i = 0; i < cols; i++ ) 
    {
        
        for ( int j = 0; j < rows; j++ ) 
        {

            cout << transposed_matrix[i][j] << "  ";            
        }

        cout << endl;
        
    }

    for (int i = 0; i < rows; ++i) 
    {
        delete[] matrix2d[i];

    }

    delete[] matrix2d;

    for (int i = 0; i < cols; ++i) 
    {

        delete[] transposed_matrix[i];
    }

    delete[] transposed_matrix;

    return 0;
}