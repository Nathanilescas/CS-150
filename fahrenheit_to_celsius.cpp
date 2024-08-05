/* -Title: Temperature Conversion 
* -Description: This program converts a fahrenheit temp. to a celsius temp.
* -Author: Nathan Ilescas
* -Module: 3
* -Project: Homework3
* -Problem Statement: I use the given temperature in fahrenheit and use the conversion formula (degreesCelsius = 5 (degreesFahrenheit  – 32) / 9)
to covert it into celsius
* -Algorithm: 
    1. Print a message to the user asking for a temperature for fahrenheit
    2. define an int variable to store the user's answer.
    3. Use a cin statement to capture the user's input 
    4. Define a double variable to store the conversion calculations
    5. Use the conversion formula (degreesCelsius = 5 (degreesFahrenheit  – 32) / 9) to convert 
    fahrenheit to celsius then save it to double variable you just defined
    6. Print the result to the console
*/

#include <iostream>

using namespace std;

int main() {
    // Collecting the user's temperature input
    cout << "Please enter a temperature...(fahrenheit): " ;
    int fahrenheit;
    cin >> fahrenheit;
    cout << endl;

    // Converting the user's answer (fahrenheit to celsius) then printing the results
    double conversion_result;
    conversion_result = (5 * (fahrenheit - 32)) / 9.0;
    cout << fahrenheit << " degrees Fahrenheit = " << conversion_result << " degrees Celsius." << endl;
}