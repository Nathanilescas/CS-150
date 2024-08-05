/* -Title: Grades Calculator
* -Description: This program takes in multiple entries of grades and outputs the percentage of the overall number of letter grades
* -Author: Nathan Ilescas 
* -Module: 8
* -Project: Homework 8 - Grading Summary
* -Problem Statement: Given multiple grade entries, calculate the percentage of each grade that was entered.
* -Algorithm: 
    1. Define/Instantiate an int variable for the letters a, b, c, d, and f, as well as the user input and the counter. 
    2. Create a loop: 
    2.a Prompt the user to enter a int number for a letter grade
    2.b Valid it by making sure it within 100 to 0
    2.c if it is: Depending on the int range, increment the letter grade variable
    2.d if number is negative: break from loop
    2.e else tell user that the input was invalid and return to the top of the loop
    3. check if user entered any grades:
    3.a if they did: calculate the grades percentage of the overall number of letter grades entered
    3.b let the user know that there were no grades entered 
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Defining/Initializing (userInput, letterGrades and counter)
    int user_input,grade_a, grade_b, grade_c, grade_d, grade_f, count;
    count = grade_a = grade_b = grade_c = grade_d = grade_f = 0;

    // Top of menu
    cout << "********** Grade Counter **********" << endl;
    cout << " (A negative grade will end entry)" << endl;

    while (true)
    {
        // Prompting user for int for letter grade
        cout << "Enter grade #" << count + 1 << ": ";
        cin >> user_input;
        
        // Validating input
        if (user_input <= 100 && user_input > 0) {

            // Incrementing depending on the input of the user
            if (user_input <= 100 && user_input > 89) {
                grade_a++;
            }
            else if (user_input <= 89 && user_input > 79) {
                grade_b++;
            }
            else if (user_input <= 79 && user_input > 69) {
                grade_c++;
            }
            else if (user_input <= 69 && user_input > 59) {
                grade_d++;
            }
            else {
                grade_f++;
            }
            count++;

        }
        else if (user_input < 0) {
            break;
        }
        else {
            cout << "ERROR: Invalid input, please try again..." << endl;
        }
    }
    
    // Checking if any grades were entered
    if (count > 0) {

        // Calculating the results of all the grades 
        double a_percent, b_percent, c_percent, d_percent, f_percent;
        // Getting the percentage
        a_percent = (grade_a / (double)count) * 100;
        b_percent = (grade_b / (double)count) * 100;
        c_percent = (grade_c / (double)count) * 100;
        d_percent = (grade_d / (double)count) * 100;
        f_percent = (grade_f / (double)count) * 100;
        // Displaying the results
        cout << "Total number of grades is: " << count << endl;
        cout << "Number of A\'s = " << grade_a << " which is: " << fixed << setprecision(1) << a_percent << "%" << endl;
        cout << "Number of B\'s = " << grade_b << " which is: " << fixed << setprecision(1) << b_percent << "%" << endl;
        cout << "Number of C\'s = " << grade_c << " which is: " << fixed << setprecision(1) << c_percent << "%" << endl;
        cout << "Number of D\'s = " << grade_d << " which is: " << fixed << setprecision(1) << d_percent << "%" << endl;
        cout << "Number of F\'s = " << grade_f << " which is: " << fixed << setprecision(1) << f_percent << "%" << endl;

    }
    else {
        cout << "No grades inputted.. ";
    }

}