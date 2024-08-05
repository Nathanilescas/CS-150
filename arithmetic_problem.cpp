/* -Title: Arithmetic Problem Generator
* -Description: This program randomly generates four random numbers and uses them in an addition problem
* -Author: Nathan Ilescas 
* -Module: 5
* -Project: Homework 5 - Art supplies report, strings
* -Problem Statement: I need a program that generates four random numbers to use in an addition problem
* -Algorithm: 
    1. Generate a 2-3 digit number using the time() method
    2. Use the number from step one and seed it into srand()
    3. Call the rand() method and save the result into a variable 
    4. Using the variable from the previous step use the modulus operater to obtain a 2-3 digit number
    5. Use the number from the previous step and seed it into srand(), call rand() and save the result
    6. repeat step 4-5 until you have your desired amount of random numbers
    7. add all the random generated numbers into a single variable 
    8. Using formatting create a vertical addition problem
    9. Prompt the user to solve the addition problem
    10. Display the answer
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

int main() {
    
    // Initiate a number using the time method
    unsigned random_number = (time(0) % 100);
    
    // seeding the variable above into the srand() method to generate a random number with the rand() method
    srand(random_number);
    unsigned number_one = rand();
    
    // Using the variable from above and using the 2-3 digit remainder for the seeding
    random_number = number_one % 100;
    //srand(random_number);
    unsigned number_two = rand();
    
    random_number = number_two % 10;
    //srand(random_number);
    unsigned number_three = rand();

    random_number = number_three % 100;
    //srand(random_number);
    unsigned number_four = rand();

    // summing the four randomly generated number 
    int total = number_one + number_two + number_three + number_four;
    string dashes = "";

    // Formatting the display of the results
    cout << right << setw(7) << number_one << endl;
    cout << setw(7) << number_two << endl;
    cout << setw(7) << number_three << endl;
    cout << "+ "<< setw(5) << number_four << endl;
    cout << setw(5) << dashes.assign(8, '-') << endl;
    cout << setw(7) << "???" << endl; 
    cout << endl;

    // Prompting the user for the answer to the problem
    int answer;
    cout << "What is the answer: ";
    cin >> answer;
    
    // Showing the correct answer
    cout << "Correct answer: "<< setw(7) << total << endl;

    return 0;
}
