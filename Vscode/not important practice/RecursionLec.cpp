// testing recursions

#include <iostream>

using namespace std;

int randomizer(int min, int max) {

    int num = ( rand() % (max - min + 1) ) + min; 
    return num;
}


int main() {

    int mynum = randomizer(20, 30);
    cout << mynum;
    
}