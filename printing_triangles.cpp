/* -Title: Printing Triangle Function
* -Description: This program prints a triangle using the user's input by calling a function.
* -Author: Nathan Ilescas 
* -Module: 10
* -Project: Homework 10 - Printing Triangles
* -Problem Statement: Print a triangle using the an int which a user's provides.
* -Algorithm: 
    1. Prompt the user for an int 
    2. if the input is not within the allowed range go back to step 1
    3. else if the input is zero then end the program 
    4. else call the printTriangle function
*/

#include <iostream>

using namespace std;

void printTriangle(int);

int main() {
    int user_input;

    do {
        // Prompt the user for a int
        cout << "Enter the size of a triangle to print (an integer from 1 to 20): ";
        cin >> user_input;

        // Validating the input
        if ( !(user_input > 0 && user_input < 21) ) {
            if (user_input != 0) {
                cout << "Invalid input, please try again..." << endl;
            }
            continue;
        }
        else {
            printTriangle(user_input);
        }

    } while (user_input != 0); 
    cout << "Have a great day..";

}


// Defining the function
void printTriangle(int width) {
    int count1, count2;

    // Creating the first half of the triangle
    count1 = 1;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < count1; j++) {
            cout << "*";
        }
        cout << endl;
        count1++;
    }

    // Creating the second half of the triangle
    count2 = width - 1;
    for (int i = 0; i < width; i++) {
        for (int j = 0; count2 > j; j++) {
            cout << "*";
        }
        cout << endl;
        count2--;
    }

}