#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

int main() {

   
   // QUESTION 1 CAN BE SOLVED FROM THIS CODE:
   
   
   /*
    int x = 15;
    int y = 5;
    int z;
    
    z = x % y++; 
    
    cout << z;
    
    
    */


   // QUESTION 2

    int customer_id;
    double previous_balance;
    double finance_charge;
    double annual_finance_rate;
    double payment;
    double charges;
    double new_balance;
    double month_end_balance;
    double t = 0;
    char decesion;


    cout << "Please enter the customer's ID, previous balance, payment and charges respectively: ";
    
    cin >> customer_id;
    cin >> previous_balance;
    cin >> payment;
    cin >> charges;

    new_balance = ( previous_balance - payment ) + charges;
    finance_charge = new_balance * (annual_finance_rate / 12);
    month_end_balance = new_balance + finance_charge;


    cout << "  CustomerID balance at xx/yy/zzzz is: \n";
    cout  << "  CustomerID"  << "  Previous balance"  << "  Month-end Balance\n";
    cout  << "       " <<  customer_id << "            "  <<  previous_balance << "               "   <<  month_end_balance << endl;





    










    
    
    
    
    
    
    
    
    
    
    
    return 0;



}