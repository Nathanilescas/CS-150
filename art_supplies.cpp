/* -Title: Supplies Calculator
* -Description: This program calculates the total cost of pencils, skectch pad and erasers depending of the amount bought.
* -Author: Nathan Ilescas 
* -Module: 5
* -Project: Homework 5 - Art supplies report, strings
* -Problem Statement: This program need to calculate the total cost on an item depending of the cost of the item and the quantity.
* -Algorithm: 
    1. Set the constant values of the GRAPHITE_PENCIL, SKETCH_PAD and ERASER_PACKAGE
    2. Define the variables to hold the number of items being bought
    3. Prompt the user for the number of items being bought for each item and store it in the variables from step 2
    4. Calculate the total by multiplying the cost of the item and the number of item being bought
    5. Display the results
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Defining and initiating the cost of school supplies
    const double GRAPHITE_PENCIL = 15.10;
    const double SKETCH_PAD = 36.25;
    const double ERASER_PACKAGE = 6.97;

    // Defining int variables to hold the supply amount
    int number_of_graphite_pencil = 0;
    int number_of_sketch_pad = 0;
    int number_of_eraser_package = 0;

    //Prompt the user for the amount of supplies needed 
    cout << "How many graphite pencils do you need: " << ends;
    cin >> number_of_graphite_pencil;

    cout << "How many sketch pads do you need: " << ends;
    cin >> number_of_sketch_pad;

    cout << "How many eraser packages do you need: " << ends;
    cin >> number_of_eraser_package;
    cout << endl;
    
    // Calculate the total unit price for all items
    double total_price_graphite_pencil = number_of_graphite_pencil * GRAPHITE_PENCIL;
    double total_price_sketch_pad = number_of_sketch_pad * SKETCH_PAD;
    double total_price_eraser_package = number_of_eraser_package * ERASER_PACKAGE;
    double total_price_of_materials = total_price_graphite_pencil + total_price_sketch_pad + total_price_eraser_package;

    // Displaying the report in a formatted way

    // Title
    cout << right << setw(10) << "Item" 
         << setw(20) << "Quantity"  
         << setw(15) << "Unit Price"  
         << setw(10) << "Total" << endl;

    // Displaying Graphite Pencil Set
    cout << left << setw(20) << "Graphite Pencil Sets" 
         << right << setw(9) << number_of_graphite_pencil 
         << fixed << setprecision(2) << setw(15) << GRAPHITE_PENCIL 
         << fixed << setprecision(2) << setw(11) << total_price_graphite_pencil << endl;
    
    cout << left << setw(20) << "Sketch Pads" 
         << right << setw(9) << number_of_sketch_pad 
         << fixed << setprecision(2) << setw(15) << SKETCH_PAD 
         << fixed << setprecision(2) << setw(11) << total_price_sketch_pad << endl;
    
    cout << left << setw(20) << "Packs of Erasers" 
         << right << setw(9) << number_of_eraser_package 
         << fixed << setprecision(2) << setw(15) << ERASER_PACKAGE 
         << fixed << setprecision(2) << setw(11) << total_price_eraser_package << endl;

    string dashes = "";
    cout << setw(55) << dashes.assign(7,'=') << endl;
    cout << setw(10) << "Total: " << fixed << setprecision(2) << setw(45) << total_price_of_materials << endl;
    
    }