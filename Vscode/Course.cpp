#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    auto num = 3;
    auto num2 = 3;
    bool result = (num == num2);
    bool result2 = (num * num2 == 0);
 
    cout << boolalpha;
    cout << "This is: " << (result) << endl;
    cout << "This is: " << (result2) << endl;

    cout << "This is: " << (result != result2); 

    int d{45};
	int e{20};
	int f{11};
	
	cout << endl;
	cout << "Relational and logic operations on integers" << endl;
	cout << "d : " << d << endl;
	cout << "e : " << e << endl;
	cout << "f : " << f << endl;
	
	cout << endl;
	
	cout << "(d > e) && (d > f) : " << ((d > e) && (d > f)) << endl; // true
	cout << "(d==e) || (e <= f ) : " << ((d==e) || (e <= f ) ) << endl;
	cout << "(d < e) || (d > f) : " << ((d < e) || (d > f)) << endl;
	cout << "(f > e) || (d < f) : " << ((f > e) || (d < f)) << endl;
	cout << "(d > f) && (f <= d) : " << ((d > f) && (f <= d)) << endl;
	cout << "(d > e) && (d <= f) : " << ((d > e) && (d <= f)) << endl;
   

    return 0;
}