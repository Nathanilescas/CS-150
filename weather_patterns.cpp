/* -Title: Wether Temperature App
* -Description: This application shows you the temperature for 4 cities with the average temp. for the city and the 4 months
* -Author: Nathan Ilescas
* -Module: 15
* -Project: Homework 15 - Print a report using the temperature
* -Problem Statement: Calculate the average temp for a city and the month for those cities
* -Algorithm:
    1. Instantiate a matrix array with int values (4x12).
   2. Define a function to display the weather.
      2.a Define variables for city_name, cityAverageTemp, and monthlyAverageTemp.
      2.b Display a header.
      2.c Define a for loop to iterate through the array rows.
      2.d Use a switch statement to assign a value to the city_name variable.
      2.e Display the city name from the variable above.
      2.f Define a for loop to iterate through the columns.
      2.g Access each column value using the loop variables from the first and second loops.
      2.h Use each accessed value as needed.
      2.i Finally, display the monthlyAverageTemp using the value from above.
   3. Call the function from the previous step.
*/

#include <iomanip>
#include <iostream>

using namespace std;

const int COLUMNS = 12;

void displayWether(int[][COLUMNS], int);

int main()
{

    int city_weather[4][12] = {
        { 68, 69, 70, 73, 75, 79, 83, 84, 83, 79, 73, 68 }, // Los Angeles
        { 39, 42, 50, 62, 72, 80, 85, 84, 76, 65, 54, 44 }, // New York
        { 73, 74, 75, 78, 81, 84, 85, 86, 85, 82, 78, 76 }, // Miami
        { 47, 51, 55, 59, 65, 70, 75, 75, 69, 60, 51, 46 } // Seattle
    };

    displayWether(city_weather, 4);
}

void displayWether(int wether[][COLUMNS], int rows)
{
    // Define variables to hold important data
    string city_name;
    double city_average_temperature;
    double monthly_average_temperature[12] = {};
    // Display the header
    cout << right << setw(50) << "Average Temperatures by Month\n"
         << endl;
    // Iterating through each row
    for (int i = 0; i < rows; i++) {

        // Assigning the name for the city
        switch (i) {
        case 0:
            city_name = "Los Angeles: ";
            break;
        case 1:
            city_name = "New York: ";
            break;
        case 2:
            city_name = "Miami: ";
            break;
        case 3:
            city_name = "Seattle: ";
            break;
        default:
            cout << "ERROR: Invalid city name..." << endl;
            exit(1);
        }
        // Displaying the city's name
        cout << left << setw(14) << city_name;

        // Iterating through the each column of the row
        for (int j = 0; j < COLUMNS; j++) {
            // adding the month temp. for each city
            city_average_temperature += wether[i][j];
            // displaying the monthly temp. for each city
            cout << right << setw(5) << wether[i][j];
            // adding the monthly temp for all four of the cities
            monthly_average_temperature[j] += wether[i][j];
        }
        // Calculating the average for each city
        city_average_temperature /= 12.0;
        // Displaying the average for each city
        cout << " || Average Temp: " << fixed << setprecision(1) << city_average_temperature << endl;
        cout << endl;
        // Reseting the variable
        city_average_temperature = 0;
    }
    // Displaying the cities average header
    cout << left << setw(15) << "Month Avg: ";
    for (int i = 0; i < 12; i++) {
        // calculating the average for all four cities
        double monthly_avg = monthly_average_temperature[i] / 4.0;
        // displaying the results from above
        cout << right << fixed << setprecision(1) << setw(6) << monthly_avg;
    }
}