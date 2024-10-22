//ChatGPT problems #1

// 1 Reverse a string

#include <iostream>
using namespace std;


void traversestring(string &str, int str_len) {

    for ( int letter = 0; letter < str_len; letter++) {

        str[letter] = str[str_len - letter];
    }

    cout << str;

}



int main() {

    string input_string;
    int input_string_len ;
    
    cout << "Please input your string: ";
    cin >> input_string;

    input_string_len = input_string.length();

    traversestring(input_string, input_string_len);

    


}