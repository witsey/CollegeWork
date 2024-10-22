#include <iostream>
using namespace std;

struct Student
{
    string name;
    int ID;
    double GPA;

};

int main() 
{

    Student Akram {"Akram", 20220802, 3.0};
    Student Mark {"Mark", 20220504, 2.20};

    cout << Akram.ID;

    cout << (( Mark.GPA > Akram.GPA) ? " yes " : " no "); 


}