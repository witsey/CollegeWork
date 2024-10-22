// First Practice Project
#include <iostream>
using namespace std;


class Vehicle 
{
protected:
    string Name;
    string Color;
    string Model;
    int Price;
    int MaxSpeed;

public:
 // Constructor
    Vehicle( string name, string color, string model, int price, int maxSpeed )
    {
        Name = name;
        Color = color;
        Model = model;
        Price = price;
        MaxSpeed = maxSpeed;
    }
 
 // General functions
    void DisplayInfo() 
    {
        cout << Name << ":" << endl << endl;

        cout << "Color: " << Color << endl;
        cout << "Model: " << Model << endl;
        cout << "Price: " << Price << endl;
        cout << "Max Speed: " << MaxSpeed << endl;
    }

    void PushGas() 
    {
        cout << "Gas pushed" << endl;
    }
    
 // Setters
    void set_name( string new_name ) 
    {
        Name = new_name;
    }

    void set_color( string new_color ) 
    {
        Color = new_color;
    }

    void set_model( string new_model ) 
    {
        Model = new_model;
    }

    void set_price( int new_price ) 
    {
        Price = new_price;
    }

    void set_maxSpeed( int new_speed ) 
    {
        MaxSpeed = new_speed;
    }
    
 // Getters
    string getName() 
    {
        return Name;
    }

    string getColor()
    {
        return Color;
    }

    string getModel() 
    {
        return Model;
    }

    int getPrice() 
    {
        return Price;
    }

    int getMaxSpeed() 
    {
        return MaxSpeed;
    } 
};

class Car : Vehicle 
{
private:
    string Transmission;
    int DoorsNum;
    bool IsConvertible;

public:
 // Default Constructor 
    Car() : Vehicle("", "", "", 0, 0), Transmission(""), DoorsNum(0), IsConvertible(false) {}

 // Car Constructor
    Car( string name, string color, string model, int price, int maxSpeed,  string transmission, int doorsNum, bool isConvertible )
        :Vehicle( name, color, model, price, maxSpeed)
    {
        Transmission = transmission;
        DoorsNum = doorsNum;
        IsConvertible = isConvertible;
    }

    void DisplayCarInfo() 
    {
        DisplayInfo();
        cout << "Transmission: " << Transmission << endl;
        cout << "Number of Doors: " << DoorsNum << endl;
        if (IsConvertible) 
            cout << Name << " is convertible " << endl;

        else
            cout << Name << " is not convertible " << endl;
    }

    void toggleConvertible() 
    {
        if (IsConvertible) 
        {
            cout << "Toggled the convertible status" << endl;
        }
    }

    void openDoor() 
    {
        cout << "Door has been Opened" << endl;
    }
};

class Motorcycle : Vehicle 
{
private:
    bool HasFairing;

public:
 // Default Constructor
    Motorcycle() : Vehicle("", "", "", 0, 0), HasFairing(false) {}

 // Motorcycle Constructor
    Motorcycle( string name, string color, string model, int price, int maxSpeed, bool hasFairing )
        :Vehicle( name, color, model, price, maxSpeed)
    {
        HasFairing = hasFairing;
    }

    void DisplayMotorcycleInfo() 
    {
        DisplayInfo();
        if (HasFairing) 
            cout << "This Motorcycle has fairing." << endl;
        else
            cout << "This Motorcycle doesn't have fairing." << endl;
    }

    void addFairing() 
    {
        HasFairing = true;
        cout << "Fairing has been added." << endl;
    }

};

class Truck : Vehicle 
{
private:
    double CargoCapacity;
    bool HasTrailer;

public:
 // Default Constructor
    Truck() : Vehicle("", "", "", 0, 0), CargoCapacity(0.0), HasTrailer(false) {}

 // Motorcycle Constructor
    Truck( string name, string color, string model, int price, int maxSpeed, double cargoCapacity, bool hastrailer )
        :Vehicle( name, color, model, price, maxSpeed)
    {
        CargoCapacity = cargoCapacity;
        HasTrailer = hastrailer;
    }

    void DisplayMotorcycleInfo() 
    {
        DisplayInfo();
        cout << "Cargo capacity: " << CargoCapacity << endl;

        if ( HasTrailer )
            cout << "This truck has a trailer." << endl;
        else
            cout << "This truck doesn't have a trailer." << endl;
    }

    void attachTrailer() 
    {
        HasTrailer = true;
        cout << "Trailer has been attached." << endl;
    }
};

const int MAX_CARS = 100;
const int MAX_MOTORCYCLES = 100;
const int MAX_TRUCKS = 100;

Car createCar() 
{
    string name, color, model, transmission;
    int price, maxSpeed, doorsNum;
    bool isConvertible;

    cout << "Enter car details: " << endl;
    
    cout << "\nName: ";
    cin >> name;

    cout << "Color: ";
    cin >> name;

    cout << "Model: ";
    cin >> name;

    cout << "Price: ";
    cin >> price;

    cout << "Max Speed: ";
    cin >> maxSpeed;

    cout << "Transmission: ";
    cin >> name;

    cout << "Number of Doors: ";
    cin >> doorsNum;

    cout << "Is the car convertible? (1 for yes, 0 for no): ";
    cin >> isConvertible;

    return Car(name, color, model, price, maxSpeed, transmission, doorsNum, isConvertible);
}

Motorcycle createMotorCycle() 
{
    
    string name, color, model;
    int price, maxSpeed;
    bool hasFairing;

    cout << "\nEnter motorcycle details:\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Color: ";
    getline(cin, color);

    cout << "Model: ";
    getline(cin, model);

    cout << "Price: ";
    cin >> price;

    cout << "Max Speed: ";
    cin >> maxSpeed;

    cout << "Does the motorcycle have fairing? (1 for yes, 0 for no): ";
    cin >> hasFairing;

    return Motorcycle(name, color, model, price, maxSpeed, hasFairing);
}

Truck createTruck() 
{
    string name, color, model;
    int price, maxSpeed;
    double CargoCapacity;
    bool HasTrailer;

    cout << "\nEnter Truck details:\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Color: ";
    getline(cin, color);

    cout << "Model: ";
    getline(cin, model);

    cout << "Price: ";
    cin >> price;

    cout << "Max Speed: ";
    cin >> maxSpeed;

    cout << "Cargo Capacity: ";
    cin >> CargoCapacity;

    cout << "Does the truck have a trailer? (1 for yes, 0 for no):";
    cin >> HasTrailer;


    return Truck(name, color, model, price, maxSpeed, CargoCapacity, HasTrailer);


}


int main() 
{
    Car cars[ MAX_CARS ];
    Motorcycle motorCycles[ MAX_CARS ];
    Truck trucks[ MAX_CARS ];

    char choice;
    int cars_index = 0;
    int motorCycles_index = 0;
    int trucks_index = 0;

    // Interface
    cout << "Input c to create a car.\nInput m to create a motorcycle.\nInput t to create a truck." << endl;
    cout << "\nINPUT: ";
    cin >> choice;

    switch (choice) 
    {
        case 'c': 
        {
            cars[ cars_index ] = createCar();
            cars_index++;
        }
        break;

        case 'm':
        {
            motorCycles[ motorCycles_index ] = createMotorCycle();
            motorCycles_index++;

        }
        break;

        case 't':
        {
            trucks[ trucks_index ] = createTruck();
            trucks_index++;

        }
        break;

    }


}