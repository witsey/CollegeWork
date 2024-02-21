#include <iostream>
using namespace std;

const int MaxRows = 10;
const int MaxCols = 10;

int main() 
{

    int rows1;
    int cols1;

    int rows2;
    int cols2;
    
    int **matrix1 = new int *[MaxRows];
    int **matrix2 = new int *[MaxRows];
    int **ProductMatrix = new int *[MaxRows];

    for ( int i = 0; i < MaxRows; i++ ) 
    {

        matrix1[i] = new int [MaxCols];
        matrix2[i] = new int [MaxCols];
        ProductMatrix[i] = new int [MaxCols];
    }

    cout << "Rows 1: ";
    cin >> rows1;

    cout << "Cols 1: ";
    cin >> cols1;

    cout << "\nRows 2: ";
    cin >> rows2;

    cout << "Cols 2: ";
    cin >> cols2;

    if ( cols1 != rows2 ) {

        cout << "\nError!";
        return 0;
    }


    cout << "\nEnter martix 1 elements: " << endl << endl;

    for ( int i = 0; i < rows1; i++) 
    {

        for ( int j = 0; j < cols1; j++) 
        {
            cout << "[ " << i << "  " << j << " ]: ";
            cin >> matrix1[i][j];
            
        }

        cout << endl;
    }

    cout << "\nEnter martix 2 elements: " << endl << endl;

    for ( int i = 0; i < rows2; i++) 
    {

        for ( int j = 0; j < cols2; j++) 
        {
            cout << "[ " << i << "  " << j << " ]: ";
            cin >> matrix2[i][j];
            
        }

        cout << endl;
    }

    for ( int i = 0; i < rows1; i++ ) 
    {
        for ( int j = 0; j < cols2; j++) {

            ProductMatrix[i][j] = 0;
            
            for ( int k = 0; k < cols1; k++) 
            {
                ProductMatrix[i][j] += ( matrix1[i][k] * matrix2[k][j] );
            
            }

        }

    }

    cout << endl << endl;;

    for ( int i = 0; i < rows1; i++) 
    {

        for ( int j = 0; j < cols2; j++) 
        {
            cout << ProductMatrix[i][j] << "  ";
            
        }

        cout << endl;
    }

    for (int i = 0; i < MaxRows; i++) 
    {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] ProductMatrix[i];
    }

    delete[] matrix1;
    delete[] matrix2;
    delete[] ProductMatrix;

    return 0;
}