#include <iostream>
#include <fstream>
using namespace std;

int main() {
 // creating and writing to a file:
    ofstream MyFile("D:\\Repositories\\College\\CollegeWork\\Vscode\\OOP\\Files\\Myfile.txt");
    MyFile << "Files can be tricky, but it is fun enough!";
    MyFile.close();

 // reading from a file:
    string strtxt;
    ifstream MyReadFile("D:\\Repositories\\College\\CollegeWork\\Vscode\\OOP\\Files\\Myfile.txt");

    while ( getline(MyReadFile, strtxt)) {
        cout << strtxt << endl;
    }

    MyReadFile.close();
}