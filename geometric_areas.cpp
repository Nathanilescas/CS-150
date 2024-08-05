/* -Title: Geometric Figure Calculator
* -Description: This program calculates the area of a triangle, rectangle and a circle.
* -Author: Nathan Ilescas 
* -Module: 7
* -Project: Homework 7 - Geometric areas
* -Problem Statement: The program needs to be able to calculate the area of multiple shapes.
* -Algorithm: 
    1. Define all the variables needed for the calculation (radius, lenght..etc)
    2. Display the menu for the calculations you are going to perform
    3. Save the user's input from the response above in a variable
    4. Use the variable from step 3 to find the correct formula to use by using the switch statement
    5. Dynamically display the result, or just display them regularly
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main() {

    // Defining variable for the shapes calculations 
    double radius, length, width, base, height, calculation_total;

    char user_response;

    // Displaying the menu 
    cout << "****** Geometric Figure Calculator ******\n" << endl;
    cout << "   C - Calculate the area of a Circle" << endl;
    cout << "   R - Calculate the area of a Rectangle" << endl;
    cout << "   T - Calculate the area of a Triangle" << endl;
    cout << "   Q - Quit\n" << endl;
    cout << "Enter your choice: ";
    cin >> user_response;
    user_response = toupper(user_response);
    
    // Validation and responding with the correct fomula to the user's response to the menu above
    switch (user_response)
    {
    case 'C':
        cout << "Enter the radius of the circle: ";
        cin >> radius;
        calculation_total = M_PI * pow(radius, 2);
        break;
    case 'R': 
        cout << "Enter the length of the rectangle: ";
        cin >> length;
        cout << "Enter the width of the rectangle: ";
        cin >> width;
        calculation_total = length * width;
        break;
    case 'T':
        cout << "Enter the base of the triangle: ";
        cin >> base;
        cout << "Enter the height of the triangle: ";
        cin >> height;
        calculation_total = height * base / 2;
        break;
    case 'Q':
        cout << "See you next time...";
        exit(1);
        break;
    default:
        cout << "Invalid input, try again...";
        exit(2);
    }


    // Displaying the results dynamically
    cout << "The area of a ";

    if (user_response == 'C') {
        cout << "circle with a radius " << fixed << setprecision(2) << radius; 
    }
    else if (user_response == 'R') {
        cout << "rectangle with a length " << fixed << setprecision(2) << length << " and width " << setprecision(2) << width;
    }
    else {
        cout << "triangle with a base " << fixed << setprecision(2) << base << " and height " << setprecision(2) << height;
    }
    
    cout << " is "<< fixed << setprecision(6) << calculation_total; 

   
}