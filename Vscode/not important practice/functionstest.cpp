#include <iostream> 
using namespace std;

int num = 0;

string printer(string &txt) {

	txt = "Hello World";
	return txt;
}

void starprinter(int rows, int cols) {

	for ( cols; cols < 5; cols++) {

		for ( rows; rows < cols + 1; rows++) {

			cout << "*";
		}

		cout << endl;
	}
}

int main() {

	
	starprinter(num, num);
	return 0;
}

