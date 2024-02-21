#include <iostream>

using namespace std;

const int COLSS = 10;
void add_matricies(double [][COLSS], double [][COLSS], int, int);


int main() 
{

    double mat1[10][COLSS] = { {1, 2 ,3}, 
                               {4, 5, 6}, 
                               {7 ,8 ,9} };

    double mat2[10][COLSS] = { {1, 2 ,3}, 
                               {4, 5, 6}, 
                               {7 ,8 ,9} };

    add_matricies(mat1, mat2, 2, 3);

    
}

void add_matricies(double matrix1[][COLSS], double matrix2[][COLSS], int rows, int cols) 
{
    double sum[rows][cols];

    for ( int i = 0; i < rows; i++ ) 
    {

        for ( int j = 0; j < cols; j++ ) 
        {

            sum[i][j] = matrix1[i][j] + matrix2[i][j];
            
        }
    }

     for ( int i = 0; i < rows; i++ ) 
    {

        for ( int j = 0; j < cols; j++ ) 
        {

            cout << sum[i][j] << "  ";
            
        }

        cout << endl;
    }

}