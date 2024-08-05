/* -Title: Change Machine
* -Description: This program calculates the change of the given amout up to a dollar (100).
* -Author: Nathan Ilescas 
* -Module: 3
* -Project: Homework3
* -Problem Statement: Using the values of a quarter, dime and nickle I am going to use the modulus operator to 
determine the number of different  coins being dispensed
* -Algorithm: 
    1. Define/initiate two int variables; One being the money inputted, Second being the item price(both must be divisible by 5).
    2. Print a message to the console with the information from steps 1.
    3. Define then initiate the total change by subtracting the item price from the money inputted.
    4. Print a message stating the result from step 3.
    5. Define an int variable to hold the number of possible quarters and initiate it with the results of step 3 divided by the monetary value for a quarter.
    6. Multiply the initiatized variable from step 5 by the monetary value of a quarter and subtract it from the total change variable that was initiated in step 3.
    7. Repeat steps 5-6 twice, switching out the monetary value with a dime first then again with a nickel.
    8. Print the numbers of quarter, dimes and nickels used for the change.
*/

#include <iostream>

using namespace std;

int main() {
    // Gather the information of the item price and the money used to pay for it.
    int money_inputted = 100;
    int item_price = 05;
    cout << "The price of your item is " << item_price << " cents and you gave me $1.00" << endl;

    // Calculate the change
    int total_change = money_inputted - item_price;
    cout << "Your change is: " << total_change << " cents." << endl;

    // Calculate the number of quarters, dimes and nickels there will be in the change
    int number_of_quarters = total_change / 25;
    total_change -= number_of_quarters * 25;

    int number_of_dimes = total_change / 10;
    total_change -= number_of_dimes * 10;

    int number_of_nickels = total_change / 5;
    total_change -= number_of_nickels * 5;

    // Print the number of quarters, dimes and nickels there will be in the change.
    cout << "Quarters: " << number_of_quarters << endl;
    cout << "Dimes: " << number_of_dimes << endl;
    cout << "Nickels: " << number_of_nickels << endl;

}