/* -Title: Calorie 
* -Description: 
* -Author: Nathan Ilescas 
* -Module: 6
* -Project: Homework 6 - Child's height estimator, calorie counter
* -Problem Statement: 
* -Algorithm: 
    1. Initialize Constants and variables that will hold user's input
    2. Get user input of life style
    3. Determine calorie modifier using branching statements
    4. Convert LB to KG
    5. Set activity duration
    6. Calculate Calories Burned for Each Activity
    7. Calculate total calories burned
    8. Modify total calories based on Lifestyle choice
    9. Display results
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    const string STATEMENT = "\nCalories burn from ", 
                 RUNNING = "Running: ", 
                 BASKETBALL = "Basketball: ", 
                 SLEEPING = "Sleeping: ";

    const double CONVERSION_FACTOR = 0.0175, 
                 RUNNING_6MPH = (CONVERSION_FACTOR * 10),
                 PLAYING_BASKETBALL = (CONVERSION_FACTOR * 8),
                 SLEEPING_MET = (CONVERSION_FACTOR * 1),
                 KG_1 = 2.2;

    // Variables that hold user's inputs
    double person_weight_lb;
    int life_style_choice;
    double calorie_modifier;
    bool is_increasing_calories = true;

    cout << "1 - Sedentary\n"
         << "2 - Somewhat active (exercises occasionally\n"
         << "3 - Active (exercises 3-4 times a week)\n"
         << "4 - Highly Active (exercises every day)" << endl;
    // Prompting the user for life style choice
    cout << "What is your current life style(1-4): ";
    cin >> life_style_choice;

    // Assigning a value to variable based on user's input
    if (life_style_choice == 1) {
        calorie_modifier = 0.20;
        is_increasing_calories = false;
    }
    else if (life_style_choice == 2) {
        calorie_modifier = 0.0;
    }
    else if (life_style_choice == 3) {
        calorie_modifier = 0.20;
    }
    else if (life_style_choice == 4) {
        calorie_modifier = 0.35;
    }
    else {
        cout << "Input is invalid, please try again...";
        exit(1);
    }

    // Prompting the user for weight
    cout << "What is your current weight(lb): ";
    cin >> person_weight_lb;

    // Convert LB to KG
    double person_weight_kg = person_weight_lb / KG_1;

    // instantiate the number of minutes each activie take 
    int total_minutes_basketball = 30;
    int total_minutes_running = 30;
    int total_minutes_sleeping = (6 * 60);

    // Calculate the total calories burn using MET for all three activites
    double calories_burn_running = total_minutes_running * RUNNING_6MPH * person_weight_kg;
    double calories_burn_basketball = total_minutes_basketball * PLAYING_BASKETBALL * person_weight_kg;
    double calories_burn_sleeping = total_minutes_sleeping * SLEEPING_MET * person_weight_kg;
    double total_calories_burn = calories_burn_running + calories_burn_basketball + calories_burn_sleeping;

    // Modifying the total calories burn depending on the life style choice
    if (is_increasing_calories) {
        total_calories_burn += total_calories_burn * calorie_modifier;
    }
    else {
        total_calories_burn -= total_calories_burn * calorie_modifier;
    }

    // Display the calories burned from the three activites
    cout << "\nPerson's weight in kg is: " << person_weight_kg 
    << STATEMENT << RUNNING << calories_burn_running 
    << STATEMENT << BASKETBALL << calories_burn_basketball 
    << STATEMENT << SLEEPING << calories_burn_sleeping 
    << "\nTotal calories burn: " << total_calories_burn << endl;
}