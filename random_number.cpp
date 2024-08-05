/* -Title: Random Numberinator
* -Description: This program generates random numbers based on the parameter that you set to the function
* -Author: Nathan Ilescas 
* -Module: 10
* -Project: Homework 10 - Random numbers
* -Problem Statement: Create a function that generates a number bases on the parameter: minimum, maximum and the count 
* -Algorithm: 
    1. Call the function 
    2. Error check for the following parameters
        - min number has to be over 0
        - min has to be less than max 
        - count has to be greater than 0
    3. if no errors then 
        - display a header
        - use a for loop to generate multiple random numbers base on the count parameter
        - display the random number
*/

#include <iostream>

using namespace std;

void printRandom(int, int, int);

int main() {

    printRandom(100, 200, 25);
    printRandom(1, 6, 40 );


    printRandom(-6, 6, 10);
    printRandom(10, 10, 10);
    printRandom(20, 30, -2);
}

void printRandom(int minimum, int maximum, int count) {
    //Error check the parameter
    if (minimum < 0) {
        cout << "The minimun " << minimum << " is too low." << endl;
    }
    else if (minimum >= maximum) {
        cout << "The minimum " << minimum << " is greater than or equal to the maximum " << maximum << endl;
    }
    else if (count < 0) {
        cout << "The count can not be zero." << endl;
    }
    else {
        // Display the header
        cout << "Here are " << count << " numbers between " << minimum << " and " << maximum << endl;

        // Iterate a random number as many time a the variable count
        for (int i = 0; i < count; i++) {
            unsigned random_number = minimum + rand() % (maximum - minimum + 1);
            cout << random_number << " ";
        }
        cout << endl;
    }

}