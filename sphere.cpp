// Title: Sphere Area/Volume Calculator
// Description: This program calculates the given radius of a sphere an outputs the surface area and the volume
// Author: Nathan Ilescas
// Module: 4
// Project: Homework 4 - Math functions
// Problem Statement: Given a inputted radius of a sphere, calculate the surface area and volume using the tool from <cmath>
/*Algorithm: 
    1. Prompt the user for a radius for a sphere
    2. Save the input into a double variable named sphere_radius
    3. Using the pow function convert the given surface area formula (4 π r^2) into code 
    3.a Multiply 4 by the variable M_PI and the pow function; parameter: (sphere_radius, 2) 
    4. Convert the given Volume formula (4⁄3 π r^3) into code
    4.a Within parentheses divided 4 by 3
    4.b Multiply the result from above by the variable M_PI and the pow function; parameter: (sphere_radius, 3)
    5. Save the result from step 3 and 4 into double variables
    6. Using the saved variables from above use cout to display them
*/

#include <iostream>
#include <cmath>

using namespace std;


int main() {

    // Prompt the user for the radius of the sphere 
    double sphere_radius;
    cout << "Input a radius for a sphere: ";
    cin >> sphere_radius;
    
    // Calulate the sphere's surface area and volume
    double surface_area = 4 * M_PI  * pow(sphere_radius, 2);
    double volume = (4.0 / 3.0) * M_PI * pow(sphere_radius, 3);

    // Display the results 
    cout << "Surface Area: " << surface_area
         << "\nVolume: " << volume << endl;

    return 0;
}