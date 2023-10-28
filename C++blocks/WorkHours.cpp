#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {

    int work_hours;
    int regular_earning;
    int overtime_hours;
    int total_earning;
    int overtime_earning;

    overtime_earning = 050;

    cout << "Enter work hours: ";
    cin  >> work_hours;
    regular_earning = work_hours * 18.25;

    if ( work_hours > 40 ) {
        overtime_hours = work_hours - 40;
        overtime_earning = overtime_hours * 27.78;

    }

    total_earning = overtime_earning + regular_earning;
    cout << "The Following Employee Earning is: " << total_earning << "$";
    return 0;

}
