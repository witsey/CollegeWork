// Classes in course

#include <iostream>
using namespace std;

class Human {
    public:
        string name;
        int age;
        int height;
};


int main() {

    Human human1;
    human1.name = "Mark";


    int input_age;

    cout << "input age : ";
    cin >> input_age;
    human1.age = input_age;


    cout << endl;

    cout << human1.name << "'s age is " << human1.age;
    
    return 0;

}