// Title: Mathematic Function Calculator
// Description: This program calculates the result of the functions floor, ceil, and the absolute value of a number
// Author: Nathan Ilescas
// Module: 4
// Project: Homework 4 - Math functions
// Problem Statement: Given a number use the cmath library to calculate the results of the floor, ceil, and absolute functions
/*Algorithm: 
    1. Prompt the user for a number and save it in a double variable type
    2. Use the floor and ceil fucntion and apply it to the user's input, save both of them in a double variable type
    3. Type cast the user's input to an integer using the pre-standard method, save it in an int variable type
    4. Use the saved variable from the previous step and apply the abs function, save it in an int variable
    5. Display the results
*/
#include <cmath>
#include <iostream>

using namespace std;

int main() {

    // Prompting the user for a number
    double user_input;
    cout << "Input a number: ";
    cin >> user_input;

    // Using the floor and ceil function on the user's input 
    double floor_result = floor(user_input);
    double ceil_result = ceil(user_input);
    
    // Type cast the user's input using the pre-standard method to convet the double into an int value
    int type_cast_input = int(user_input);

    // Using abs function on the type_cast_input variable
    int absolute_value_result = abs(type_cast_input);

    // Displaying the results
    cout << "\nResults\n"
         << "Floor: " << floor_result
         << "\nCeil: " << ceil_result
         << "\nAbsolute Value: " << absolute_value_result << endl;

    return 0;
}