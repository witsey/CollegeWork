#include <iostream>
using namespace std;

class Employee 
{
private:
 // Encapsulated Data
    string Name;
    int Age;
    string Company;

public:
 // Accessing encapsulated data through class methods
    Employee( string name, int age, string company ) 
    {
        Name = name;
        Age = age;
        Company = company;
    
    }
    
    void PrintData() 
    {
        cout << "\nName: " << Name << endl;
        cout << "Age: " << Age << endl;
        cout << "Company: " << Company << endl;
    }

    void changeName( string new_name ) 
    {
        Name = new_name;
        cout << "\nName changed to: " << Name;
    }

    string getName() 
    {
        return Name;
    }
};

class Developer: Employee
{
private:
    string programmingLang;
    int experienceYears;

public:
    Developer( string name, int age, string company, string ProgrammingLang, int ExperienceYears)
        :Employee(name, age, company)
    {
        programmingLang = ProgrammingLang;
        experienceYears = ExperienceYears;
    }

    void ShowHate() 
    {
        cout << getName() << " Hates " << programmingLang << endl;
    }
};

int main() 
{
    Developer Akram = Developer("Akram", 18, "Student", "C++", 1);
    Akram.ShowHate();
    
}