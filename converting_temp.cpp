/* -Title: Temperature Conversion
* -Description: This program converts Fahrenheit to Celsius and vice versa.
* -Author: Nathan Ilescas 
* -Module: 10
* -Project: Homework 10 - Converting converted_Temperatures
* -Problem Statement: Create a function that can convert fahrenheit to celsius or vice versa
* -Algorithm: 
    1. Create a function that take int two parameter: int for degrees, char for scale 
    2. if scale is either 'F' or 'f' : then convert fahrenheit to celsius using => degreesCelsius = (5 / 9) * (degreesFahrenheit – 32)
    3. if else scale is either 'C' or 'c': then convert celsius to fahrenheit  using => degreesFahrenheit = (9 / 5)  * degreesCelsius  + 32
    4. else let the user know that the input is invalid and exit the function
    5. Display the result of the conversion
*/

#include <iostream> 
#include <iomanip>

using namespace std;

void convert(double, char);

int main() {
    convert(100.0, 'C');
    convert(32.0, 'F');
    convert(-40, 'C');
    convert(50, 'f');
    convert(50, 'c');
    convert(80, 'f');
    convert(0, 'X');
}

void convert(double degrees, char scale) {
    // Defining variables to hold data for the function
    const string DEGREE = "\u00b0";
    string current_degree, convert_degree;
    double converted_temperature;

    // Determining what conversion formula to execute based of the user's scale parameter input 
    if (scale == 'F' || scale == 'f') {
        converted_temperature = (5 / 9.0) * (degrees - 32);
        current_degree = " Fahrenheit ";
        convert_degree = " Celsius ";
    }
    else if (scale == 'C' || scale == 'c') {
        converted_temperature = (9 / 5.0) * degrees + 32;
        current_degree = " Celsius ";
        convert_degree = " Fahrenheit ";
    }
    else {
        cout << "Error: Scale is invalid" << endl;
        return;
    }

    // Displaying the results
    cout << fixed << setprecision(1) << degrees << DEGREE << current_degree << "is " << fixed << setprecision(1) << converted_temperature << DEGREE  << convert_degree << endl;
}