#include <iostream>
using namespace std;

class Student
{
private:
    string Name;
    int ID;
    int Age;
    string Major;
public:
    Student( string name, int id, int age, string major ) 
    {
        Name = name;
        ID = id;
        Age = age;
        Major = major;
    }
 // setters
    void setName( string new_name ) 
    {
        Name = new_name;
    }

    void setID( int new_ID ) 
    {
        ID = new_ID;
    }

    void setAge( int new_age ) 
    {
        Age = new_age;
    }

    void setMajor( string new_major ) 
    {
        Major = new_major;
    }

 // getters
    string getName() 
    {
        return Name;
    }

    int getID() 
    {
        return ID;
    }

    int getAge() 
    {
        return Age;
    }

    string getMajor() 
    {
        return Major;
    }


    virtual void displayInfo() 
    {
        cout << "This is " << Name << " a student " << endl;

        cout << "\nID: " << ID << endl;
        cout << "\nAge: " << Age << endl;
        cout << "\nMajor: " << Major << endl;
    }
};


class UnGraduateStudent : public Student
{
private:
    string Program;
    int Current_year;
    int ExpectedGraduation;

public:
    UnGraduateStudent( string name, int id, int age, string major, string program, int expectedGraduation) 
        :Student(name, id, age, major )
    {
        Program = program;
        ExpectedGraduation = expectedGraduation;
    }

 // setters
    void setProgram( string new_program) 
    {
        Program = new_program;
    }

    void setCurrent_Year( int new_currentYear ) 
    {
        Current_year = new_currentYear;
    }

    void setExpectedGrad( int new_expectedGrad ) 
    {
        ExpectedGraduation = new_expectedGrad;
    }

 // getters
    string getProgram() 
    {
        return Program;
    }

    int getCurrentYear() 
    {
        return Current_year;
    }

    int getExpectedGrad() 
    {
        return ExpectedGraduation;
    }

    void displayInfo() override 
    {
        cout << "I'm " << getName() << " a student majoring in " << getMajor() << endl;

        cout << "\nCurrent Year: " << getCurrentYear() << endl;
        cout << "\nID: " << getID() << endl;
    }

};


class GraduateStudent : public Student 
{
private:
    string Degree;
    int GraduationYear;

public:
    GraduateStudent( string name, int id, int age, string major, string degree, int graduationYear ) 
        :Student(name, id, age, major)
    {
        Degree = degree;
        GraduationYear = graduationYear;
    }

 // setters
    void setDegree( string new_degree ) 
    {
        Degree = new_degree;
    }

    void setGradYear( int new_gradYear ) 
    {
        GraduationYear = new_gradYear;
    }

 // getters
    string getDegree() 
    {
        return Degree;
    }

    int getGradYear() 
    {
        return GraduationYear;
    }

    void displayInfo() override 
    { 
        cout << "I'm " << getName() << " a student graduated in " << getGradYear() << " with a " << getDegree() << " in " << getMajor() << endl;
    }
};  


int main() 
{


}