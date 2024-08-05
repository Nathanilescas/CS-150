/* -Title: Height Estimator
* -Description: 
* -Author: Nathan Ilescas 
* -Module: 6
* -Project: Homework 6 - Child's height estimator, calorie counter
* -Problem Statement: Using a parent height formula, calculate the potential height of a child.
* -Algorithm: 
    1. Define all the necessary variables 
    2. Prompt the user for the their gender
    3. Using an if statement, validate the user's input 
    3.a if input is valid then assign the boolean value to the is_male variable depending on the user's input
    4. Gather the user's father and mother height information and do input validation checks on the inputs
    4.a If information is valid, convert the parents height into inches. Else nodify the user of the invalid input
    5. Use an if statement to determine what formula to use based on the is_male variable
    6. Display the results from step 5
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    // Variables that hold the user's information
    bool is_male;
    char gender;
    int father_height_feet;
    int father_height_inch;
    int mother_height_feet;
    int mother_height_inch;
    int father_total_height;
    int mother_total_height;
    double child_height;

    // Prompting the user for their gender
    cout << "What is your gender? (Type M/F): ";
    cin >> gender;

    if (gender == 'M' || gender == 'F') {
        is_male = (gender == 'M');
    }
    else {
        cout << "Wrong letter, please try again..." << endl;
    }
    
    // Promting the user for father's height
    cout << "How tall is your father in feet:";
    cin >> father_height_feet;
    cout << "inch: ";
    cin >> father_height_inch;

    if (father_height_inch >= 0 && father_height_inch < 12) {

        // Prompting the user for mother's height
        cout << "How tall is your mother in feet: ";
        cin >> mother_height_feet;
        cout << "inch: ";
        cin >> mother_height_inch;
        cout << endl;

        if (mother_height_inch >= 0 && mother_height_inch < 12) {

            // Converting parents height(feet) to inches
            father_total_height = (father_height_feet * 12) + father_height_inch;
            mother_total_height = (mother_height_feet * 12) + mother_height_inch;

            // Evaluating the is_male variable to determine which formula to use
            if (is_male) {
                child_height = round(((mother_total_height * 13 / 12) + father_total_height) / 2.0);
            }
            else {
                child_height = round(((father_total_height * 12 / 13) + mother_total_height) / 2.0);
            }

            // Calculate childs Height
            int child_height_feet = child_height / 12;
            int child_hight_inches = (int)child_height % 12;

            // Displaying the results 
            cout << father_height_feet << "\'" << father_height_inch << "\" Dad, and " 
                 << mother_height_feet << "\'" << mother_height_inch << "\" Mother >>";

            if (is_male) {
                cout << " Male " << child_height_feet << "\'" << child_hight_inches << "\"" << endl;
            }
            else {
                cout << " Female " << child_height_feet << "\'" << child_hight_inches << "\"" << endl;
            }

        }
        else {
            cout << "Your mother height in inches is not valid...";
        }

    }
    else {
        cout << "Your father height in inches is not valid...";
    }

    return 0;
}