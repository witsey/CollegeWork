#include <iostream>
using namespace std;


int space[3][3] = {{ 49 , 50 , 51 },
                    { 52 , 53 , 54 },
                    { 55 , 56 , 57 } };

int current_player = 1;
string player1;
string player2;

void printSpace( bool );
void PrintSymbol();
bool checkWinner();


int main() 
{

    cout << "Enter the name of Player 1 : \n";
    getline(cin, player1);

    cout << "\nEnter the name of Player 2 : \n";
    getline(cin, player2);

    printSpace(1);

    system("pause");

    return 0;
}

void printSpace( bool first_print  ) 
{
    bool game_end = false;

    cout << endl;
    cout << "         |         |         \n";
    cout << "    " << (char)space[0][0] <<   "    |    " << (char)space[0][1] << "    |   " << (char)space[0][2] << "     \n";
    cout << "_________|_________|_________\n";
    cout << "         |         |         \n";
    cout << "    " << (char)space[1][0] <<   "    |    " << (char)space[1][1] << "    |   " << (char)space[1][2] << "     \n";
    cout << "_________|_________|_________\n";
    cout << "         |         |         \n";
    cout << "    " << (char)space[2][0] <<   "    |    " << (char)space[2][1] << "    |   " << (char)space[2][2] << "     \n";
    cout << "         |         |         \n";

    if (!first_print) 
    {

        game_end = checkWinner();

        if (game_end) 
        {
            if ( current_player == 1) 
            {
                cout << player1 << " is the winner!!" << endl;
                return;
                
            }
            else 
            {
                cout << player2 << " is the winner!!" << endl;
                return;
            }

        }
        else 
        {
            if ( current_player == 1)
                current_player++;
            else
                current_player--;
            PrintSymbol();

        }
    }
    else
        PrintSymbol();
            
    return;
}

void PrintSymbol() 
{
    char spot;
    cout << "Player " << current_player << " enter your spot: ";
    cin >> spot;

    for ( int i = 0; i < 3; i++ ) 
    {
        for ( int j = 0; j < 3; j++ ) 
        {
            if ( space[i][j] == spot ) 
            {
                if ( space[i][j] != 'x' && space[i][j] != '0' ) 
                {
                    if ( current_player == 1) 
                        space[i][j] = 'X';
                    else
                        space[i][j] = 'O';
                }
            }
        }
    }

    printSpace(0);

}

bool checkWinner() 
{
    if ( (space[0][0] == space[1][1] && space[1][1] == space[2][2] ) || ( space[0][2] == space[1][1] && space[1][1] == space[2][0] ) )
        return true;
        

    for (int i = 0; i < 3; i++) 
    {
        for ( int j = 0; j < 3; j++ ) 
        {
            if ( (space[i][j] == space[i + 1][j] && space[i + 1][j] == space[i + 2][j] ) || (space[i][j] == space[i][j + 1] && space[i][j + 1] == space[i][j + 2] )  )
                return true;
            
        }
    }

    return false;
}