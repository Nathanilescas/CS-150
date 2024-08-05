// Title: Sin,Cos,Tan Degree Calculator
// Description: This program calculates the sin, cos and tan of a radian from a degree
// Author: Nathan Ilescas
// Module: 4
// Project: Homework 4 - Math functions
// Problem Statement: Using the pre-made function from cmath calculate the sin, cos and tan of a radian
/*Algorithm: 
    1. Prompt the user for an input (in degrees).
    2. Convert the user's input to radian using the formula (pi * degree / 180)
    3. Calculate the Sin, Cos, and Tan using the function from cmath library
    4. Use the result from step 3 and display it to the console
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Prompting the user for a input (in degrees)
    int degree; 
    cout << "Input a number for the angle size (in degrees): ";
    cin >> degree;

    // Converting input to radian using (pi * degree / 180)
    long double radian = M_PI * degree / 180;

    // calculate Sin, Con, Tan using the pre-made function from cmath
    long double sin_result = sin(radian);
    long double cos_result = cos(radian);
    long double tan_result = tan(radian);

    // Displaying the results from above
     
    cout << "\nSin of " << degree << " is: " << sin_result
         << "\nCos of " << degree << " is: " << cos_result
         << "\nTan of " << degree << " is: " << tan_result 
         << "\n(" << degree << " degrees is " << radian << " radians." << ")"<< endl;

    return 0;
}