#include <iostream>
#include <iomanip>


using namespace std;

int main() {

    float input_temperature;
    float converted_temperature;
    
    string temperature_unit;

    cout << "Please input temperature value: ";
    cin >> input_temperature;

    cout << "Please input the unit of temperature value ( Celsius or Fahrenheit ) and the program will convert it to the other unit: ";
    cin >> temperature_unit;

    if ( temperature_unit == "Fahrenheit" || temperature_unit == "fahrenheit" ) {

        converted_temperature = ( input_temperature - 32.0 ) * ( 5.0 / 9.0);
        cout << fixed << setprecision(1) << input_temperature << " Fahrenheit is equivalent to : "  << converted_temperature << " Celsius";

    }
    else if (temperature_unit == "Celsius" || temperature_unit == "celsius") {

        converted_temperature = ( input_temperature * 9/5 ) + 32;
        cout << fixed << setprecision(1) << input_temperature << " Celsius is equivalent to : "  << converted_temperature << " Fahrenheit";

    }
    else {

        cout << "Invalid temperature unit";

    }






    return 0;
    
}

