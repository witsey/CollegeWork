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

<<<<<<< Updated upstream

};


class RatePlan : public Plan
{
protected:
    double callRate;
    int minutesConsumed;

public:
    protected:
    double callRate;
    int minutesConsumed;

public:
    RatePlan(string customerName, long int phoneNumber, int billMonth, double callRate)
        : Plan(customerName, phoneNumber, billMonth), callRate(callRate)
    {
        minutesConsumed = 0;
    }

    double calculateBill() override
    {
        double billAmount = callRate * minutesConsumed;
        cout << "Bill Details:" << endl;
        cout << "Minutes consumed: " << minutesConsumed << endl;
        cout << "Call Rate: " << callRate << " per minute" << endl;
        cout << "Total Bill: $" << billAmount << endl;
        return billAmount;
    }

    int inputCalls(int hours, int minutes, int seconds) override
    {
        minutesConsumed = Plan::inputCalls(hours, minutes, seconds);
        return minutesConsumed;
    }

    void printAccountDetails() override
    {
        Plan::printAccountDetails();
        cout << "Call Rate: " << callRate << " per minute" << endl;
        cout << "Minutes consumed: " << minutesConsumed << endl;
    }
};
=======
class PackagePlan : public Plan {
    
}
>>>>>>> Stashed changes
