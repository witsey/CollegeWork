#include <iostream>
using namespace std;

void printPattern(char, int, int, int);

void printPattern(char character, int currentRow, int currentColumn, int totalRows) {
    // Base case: If we have printed all rows, return
    if (currentRow == totalRows) {
        return;
    }

    // Check if we need to move to the next line
    if (currentColumn > currentRow) {
        cout << endl;
        currentColumn = 0;
        // Recursive call for the next row
        printPattern(character, currentRow + 1, 0, totalRows);
    }
    else if (currentRow < totalRows && currentColumn <= currentRow) {
        // Print the character
        cout << character;
        // Recursive call for the next column
        printPattern(character, currentRow, currentColumn + 1, totalRows);
    }
}

int main() {
    // Example usage: print 'X' in a specific pattern for 5 rows
    char characterToPrint = 'X';
    int totalRows = 9;

    printPattern(characterToPrint, 0, 0, totalRows);

    return 0;
}
