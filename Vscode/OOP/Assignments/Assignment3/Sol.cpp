#include <iostream>
#include <cmath>
using namespace std;

    string months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

class Plan
{
    protected:
        string customerName;
        long int phoneNumber;
        int billMonth;
    public:
        Plan(string customerName, long int phoneNumber, int billMonth) {
            this->customerName = customerName;
            this->phoneNumber = phoneNumber;
            this->billMonth = billMonth;
        }

        virtual double calculateBill() = 0;


        virtual int inputCalls(int hours, int minutes, int seconds) 
        {
            int totalMinutes = 0;

            totalMinutes += minutes;
            totalMinutes += 60 * hours;
            totalMinutes += seconds / 60;

            return round(totalMinutes);
        }

        
        virtual void printAccountDetails() 
        {
            cout << "Customer Name: " << customerName << endl;
            cout << "Phone Number " << phoneNumber << endl;
            cout << "Customer Name: " << customerName << endl;
            cout << "Month: " << months[billMonth - 1] << endl;
        }
};

class PackagePlan : public Plan {
    private:
        int allowedMins;
        double monthlyCost;
        int outRate;
};




