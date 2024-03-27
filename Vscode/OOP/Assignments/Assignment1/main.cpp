#include <iostream>
#include <cstring>
using namespace std;

class CharArray {
    private:
       int size;
    public: 
       char *array;
       inline static int maxSize = 0;
       CharArray() {
            array = new char[100];
            strcpy(array, "");
            size = 0;
       }

        CharArray( const char* given_array)  {
            size = strlen(given_array);
            array = new char[size + 1];
            strcpy(array, given_array);

            if ( size > maxSize )
                maxSize = size; 
        }

        int getSize() const {
            return size;
        }

        void changeCharacter(int index, char newChar) {
        if ( index >= 0 && index < size ) 
            array[index] = newChar;
        else 
            cout << "Invalid index." << endl;
        }   

        char operator[] ( int index ) {
            return array[index];
        }

        void operator++ () {
            for ( int i = 0; i < size; i++ ) {
                array[i]++;
            }
        }

        void operator-- (int) {
            for ( int i = 0; i < size; i++ ) {
                array[i]--;
            }
        }

        CharArray operator+ ( CharArray other ) {
            char *new_array;

            int new_size = ( strlen(array) + strlen(other.array) + 1 );
            new_array = new char[new_size];
            strcpy(new_array, array);

            strcat(new_array, " ");
            strcat(new_array, other.array);
            return new_array;
        }

        void operator|= ( CharArray other ) {
            strcpy(array, other.array);
        }

        string operator* ( int factor ) {
            
            string multipliedStrings = "";
            for ( int i = 0; i < factor; i++) {
                multipliedStrings = multipliedStrings + array;
            }

            return multipliedStrings;
        }

        char first() {
            return array[0];
        }

        char last() {
            return array[size - 1];
        }

        char* reverse() {
            char* reversedString;

            reversedString = new char[size + 1];

            for (int i = 0; i < size; i++ ) {
                reversedString[i] = array[ size - i - 1];
            }

            reversedString[size] = '\0';

            return reversedString;
        }

        int length() {
            return size;
        }



};

CharArray strings[100];
CharArray another;
int indx = -1;

// Functions Prototypes

void menu();
CharArray readString();
void addString();
void checkIfHasString();
void copyString();
void concatenateStrings();
void reverseString();
void findLength();
void getLargestString();
void getCharacter();
void changeCharacter();
void getFirstAndLastChars();
void repeatString();
void addOne();
void subtractOne();
void askExit();
void exit();

//

int main () {
    menu();    
    return 0;
}


void menu() {
    int choice;
 // Interface:

    cout << "\nMENU: " << endl << endl;

    cout << "1.  Add a new String\n2.  Copy a string to another\n3.  Concatenate 2 strings\n4.  Reverse a string\n"
         << "5.  Find Length of the string\n6.  Get the largest string\n"
         << "7.  Get a character in string by index\n8.  Change a character in string by index\n"
         << "9.  Get first and last character in string\n10. Repeat the string for number of times n\n"
         << "11. Add 1 to string characters\n12. Subtract 1 from string characters\n"
         << "13. Exit" << endl << endl;

    cout << "Choose one of the following options: ";
    cin >> choice;

    switch (choice)
    {
    case 1: {
        addString();
        askExit();
        break;
    }

    case 2: {
        copyString();
        askExit();
        break;
    }

    case 3: {
        concatenateStrings();
        askExit();
        break;
    }

    case 4: {
        reverseString();
        askExit();
        break;
    }

    case 5: {
        findLength();
        askExit();
        break;
    }
    
    case 6: {
        getLargestString();
        askExit();
        break;
    }

    case 7: {
        getCharacter();
        askExit();
        break;
    }

    case 8: {
        changeCharacter();
        askExit();
        break;
    }

    case 9: {
        getFirstAndLastChars();
        askExit();
        break;
    }

    case 10: {
        repeatString();
        askExit();
        break;
    }

    case 11: {
        addOne();
        askExit();
        break;
    }

    case 12: {
        subtractOne();
        askExit();
        break;
    }

    case 13: {
        exit();
        break;
    }
    
    default:
        cout << "Invalid choice." << endl;
        break;
    }
}


CharArray readString() {
    string tempString;
    char* newString = new char[100];
    cout << "\nInput your string: ";
    cin.ignore();
    getline(cin, tempString);

    for (int i = 0; i < tempString.length(); i++ ) {
        newString[i] = tempString[i];
    }
    return CharArray(newString);
}


void checkIfHasString() {
    if ( indx < 0 ) {
        cout << "There is no string to do this operation. Please try adding one then try again" << endl;
        askExit();
    }
}


void addString() {
    
    ++indx;
    strings[indx] = readString();
}


void copyString() {
    
    checkIfHasString();

    another = strings[indx];
    cout << "\nString " << "'" << strings[indx].array << "'" << " copied to another.";
}


void concatenateStrings() {
    
    checkIfHasString();

    cout << "\nWhat string to concatenate?: ";

    CharArray StringToConcatenate = readString();
    CharArray concatenatedString = strings[indx] + StringToConcatenate;

    cout << "\nStrings concatenated to a new string: " << concatenatedString.array << endl;
}


void reverseString() {

    checkIfHasString();
    cout << "\nString reversed: " << strings[indx].reverse() << endl;
}


void findLength() {

    checkIfHasString();
    cout << "The length of the string is: " << strings[indx].length() << endl;
}


void getLargestString() {

    checkIfHasString();
    string largest = strings[indx].array;
    for ( int i = 0; i < 100; i++ ) {
        if ( largest.length() < strings[i].getSize() ) {
            string largest = strings[i].array;
        }
    }

    cout << "\nThe largest string is: " << "'" << largest << "'" <<  endl;
}


void getCharacter() {
    
    checkIfHasString();

    int targetIndex;

    cout << "\nInput the index to get the character: ";
    cin >> targetIndex;

    if ( targetIndex >= 0 && targetIndex < strings[indx].getSize() )
        cout << "The character of this index in the string is '" << strings[indx][targetIndex] << "'" << endl;
    else
        cout << "Invalid index" << endl;
}


void changeCharacter() {

    checkIfHasString();

    int targetIndex;
    char temp;
    char newChar;


    cout << "\nInput the index to change the character: ";
    cin >> targetIndex;
    
    temp = strings[indx][targetIndex];

    cout << "Input the new character: ";
    cin >> newChar;

    strings[indx].changeCharacter(targetIndex, newChar);

    cout << "the character '" << temp << "' has been changed to '" 
         << strings[indx][targetIndex]  << "'. now the string is: '" << strings[indx].array << "'" << endl;
}


void getFirstAndLastChars() {
    
    checkIfHasString();

    int size = strings[indx].getSize();

    cout << "\nThe first letter in the string is: '" << strings[indx][0] << "'" << endl; 
    cout << "The last letter in the string is: '" << strings[indx][ size - 1 ] << "'" << endl;
}


void repeatString() {

    checkIfHasString();
    int factor;

    cout << "\nInput the number of repeats: ";
    cin >> factor;

    cout << strings[indx] * factor;
}


void addOne() {

    checkIfHasString();
    ++strings[indx];
    cout << "\nAdded one. now the string is " << strings[indx].array; 
}


void subtractOne() {

    checkIfHasString();
    strings[indx]--;
    cout << "\nSubtracted one. now the string is " << strings[indx].array;
}


void askExit() {
    bool Continue;

    cout << "\nDo you wish to continue and return to the menu? (1 for yes, 0 for no ): ";
    cin >> Continue;

    if (Continue)
        menu();
    else 
        exit();
}


void exit() {
    cout << "\nGoodBye" << endl;
    return;
}

