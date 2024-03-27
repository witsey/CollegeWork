

#include <iostream>
using namespace std;

struct Book {
    string name;
};

Book death { "death" };
Book night { "night" };
Book table { "Table" };

Book books[3] { death, night, table };

int main() {
    for (int i = 0; i < 3; i++) { // Initialize i and use i < 3
        cout << books[i].name << endl;
    }
    return 0; // Add a return statement at the end of main
}