/* -Title: Calorie Calculator
* -Description: 
* -Author: Nathan Ilescas
* -Module: 3
* -Project: Homework3
* -Problem Statement: Using the converted weight from lb to kg of the person, use the MET formula to calculate the 
total calories burned for all three of the activies
* -Algorithm: 
    1. Convert the person's weight from lb to kg using this formula (kg_weight = weight_lb divided by 2.2)
    2. Save the result from step 1 into a double variable 
    3. Define/initilize an int variables for the number of minutes each activity takes.
    4. Using the MET formula calculate the total calories burn and calories burn for each activity then save it in there own individual double variable 
    5. Print out a message with all the results of step 4
*/

#include <iostream>
using namespace std;

int main() {
    // Convert the person's weight from lb to kg
    double person_weight_lb = 250;
    double person_weight_kg = person_weight_lb / 2.2;

    // instantiate the number of minutes each activie take 
    int total_minutes_basketball = 30;
    int total_minutes_running = 30;
    int total_minutes_sleeping = (6 * 60);

    // Calculate the total calories burn using MET for all three activites
    double calories_burn_running = total_minutes_running * (0.0175 * 10 * person_weight_kg);
    double calories_burn_basketball = total_minutes_basketball * (0.0175 * 8 * person_weight_kg);
    double calories_burn_sleeping = total_minutes_sleeping * (0.0175 * 1 * person_weight_kg);
    double total_calories_burn = calories_burn_running + calories_burn_basketball + calories_burn_sleeping;

    // Display the calories burned from the three activites
    cout << "Person's weight in kg is: " << person_weight_kg << endl;
    cout << "Calories burn from running: " << calories_burn_running << endl;
    cout << "Calories burn from basketball: " << calories_burn_basketball << endl;
    cout << "Calories burn from sleeping: " << calories_burn_sleeping << endl;
    cout << "Total calories burn: " << total_calories_burn << endl;
}