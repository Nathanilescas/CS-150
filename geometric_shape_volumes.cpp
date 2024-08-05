/* -Title: Area and Volume Calculator
* -Description: This program calculates the area and the volume of a certain amount of shapes
* -Author: Nathan Ilescas 
* -Module: 11
* -Project: Homework 11 - Geometric shape areas and volumes using
* -Problem Statement: Given a shape calculate the area and volume of a shape
* -Algorithm: 
    1. Call the function that displaysa a menu of shapes, have it return the response 
    2. Use a switch statement to determine the course of action
    3. Based on the results of step two, call the correct function to calculate the area and volume of the shape based on the return value of step one
    4. if 'Q' is entered exit the program, else return to step one
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

char menu();
void sphere();
void cube();
void pyramid();


int main() {

    while (true) {
        char menu_response = menu();

        switch (menu_response) {
            case 'S' : sphere();
                break;
            case 'C' : cube();
                break;
            case 'P' : pyramid();
                break;
            case 'Q' : 
                cout << "See you next time...";
                exit(EXIT_SUCCESS);
            default : 
                cout << "Error: Menu response is invalid...." << endl;
        }
    }
    
}

char menu() {
    char user_response;

    // Displaying the menu 
    cout << "****** Geometric Figure Calculator ******\n" << endl;
    cout << "   S - Calculate the area and volume of a sphere" << endl;
    cout << "   C - Calculate the area and volume of a cube" << endl;
    cout << "   P - Calculate the area and volume of a pyramid" << endl;
    cout << "   Q - Quit\n" << endl;
    cout << "Enter your choice: ";
    cin >> user_response;
    // Converting the response to upper case
    user_response = toupper(user_response);

    return user_response;
}

void sphere() {
    // Defining varibles that will hold data
    double radius, sphere_area, sphere_volume;

    // Prompting the user
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    // Error checking
    while (radius < 0) {
        cout << "Error: Radius is too low, please try again..." << endl;
        
        cout << "Enter the radius of the circle: ";
        cin >> radius;
    }

    // Calculating the area and volume of a sphere
    sphere_area = 4 * M_PI * pow(radius, 2);
    sphere_volume = (4 / 3.0) * M_PI * pow(radius, 3);

    // Displaying the results of the calculation above
    cout << "The area of the sphere is " << fixed << setprecision(2) << sphere_area << endl;
    cout << "The volume of the sphere is " << fixed << setprecision(2) << sphere_volume << endl;
}

void cube() {
    // Defining vaiable that will hold important infromation
    double sides, cube_area, cube_volume;

    // Prompt the user
    cout << "Enter the side of the cube: ";
    cin >> sides;

    //Error checking
    while (sides < 0) {
        cout << "Error: Radius is too low, please try again..." << endl;
        
        cout << "Enter the radius of the circle: ";
        cin >> sides;
    }

    // Calculation the area and the volume of the cube
    cube_area = 6 * pow(sides, 2);
    cube_volume = pow(sides, 3);

    // Displaying the results from the calculations above
    cout << "The area of the cube is " << fixed << setprecision(2) << cube_area << endl;
    cout << "The volume of the cube is " << fixed << setprecision(2) << cube_volume << endl;
}

void pyramid() {
    // Defining variables that will hold the infromation about the shape
    double pyramid_height, pyramid_base, pyramid_area, pyramid_volume;

    // Error checking
    do {
        if (pyramid_height < 0) {
            cout << "Error: Height of pyramid is too low..." << endl;
        }

        cout << "Enter the height of the pyramid: ";
        cin >> pyramid_height;
    } while (pyramid_height < 0);
    
    // Error checking
    do {
        if (pyramid_base < 0) {
            cout << "Error: Base of pyramid is too low..." << endl;
        }

        cout << "Enter the base of the pyramid: ";
        cin >> pyramid_base;
    } while (pyramid_base < 0);

    // Calculating the area and the volume of the pyramid using the user's input
    pyramid_area = pow(pyramid_base, 2) + 2 * pyramid_base * sqrt( (pow(pyramid_base, 2) / 4.0) ) + pow(pyramid_height, 2);
    pyramid_volume = pow(pyramid_base, 2) * pyramid_height / 3.0;

    // Displaying the results of the calculations above
    cout << "The area of the pyramid is " << fixed << setprecision(2) << pyramid_area << endl;
    cout << "The volume of the pyramid is " << fixed << setprecision(2) << pyramid_volume << endl;
}




