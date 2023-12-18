//ChatGPT problems #1

// 2 Reverse a string

#include <iostream>
using namespace std;


void TraverseString(string &str, int str_len) {

    for ( int letter = 0; letter < str_len / 2 ; letter++) {
        
        char temp = str[letter];
        str[letter] = str[str_len - 1 - letter];
        str[str_len - 1 - letter] = temp;
        
    }

    cout << str;
}



int main() {

    string input_string;
    string output_string;
    
    int input_string_len;
    
    cout << "Please input your string: ";
    getline(cin, input_string);

    input_string_len = input_string.length();
    TraverseString(input_string, input_string_len);
    
}