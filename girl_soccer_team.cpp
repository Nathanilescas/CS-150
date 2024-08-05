/* -Title: Team Stats Report
* -Description: This program imports data from a text file and creates a formal report
* -Author: Nathan Ilescas
* -Module: 14
* -Project: Homework 14 - Girls Soccer Team
* -Problem Statement: Extract stat data from a txt file and display the results
* -Algorithm:
    1. Instantiate 3 array: Player's name, goals and assist
    2 Call the extract function using the file path and the 3 array from the previous step as arguments
        2.a Use a ifstream object to open a file
        2.b error check to see if the file was found
        2.c Create variables to hold the file data with a counter variable to keep track of the iteration
        2.d Iterate through the file, filling in the arrays as needed
        2.e Once complete close and clear the file, then return the counter variable
    3. Once the arrays are filled with data display the results
        3.a Use highestRank() to find the most goals and assist from a player
            3.a.a Store the first index value in a variable
            3.a.b Iterate through the array comparing the value above with each iteration
            3.a.c if the iterative value is larger then swap the values for the variable else continue through the array
            3.a.d return the variable from step one
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const string SOCCER_TEAM = "Players.txt";
int extractStats(string, string[], int[], int[]);
void displayStats(string[], int[], int[], int);
int highestRanked(int[], int);
int calculatePerformance(int[], int[], int);

int main()
{
    int counter;
    string player_name[20] = {};
    int player_goal[20] = {};
    int player_assist[20] = {};

    counter = extractStats(SOCCER_TEAM, player_name, player_goal, player_assist);
    displayStats(player_name, player_goal, player_assist, counter);
}

void displayStats(string playerName[], int playerGoals[], int playerAssist[], int size)
{

    // Finding the player's index for the highest goals and assist
    int highestGoals = highestRanked(playerGoals, size);
    int highestAssist = highestRanked(playerAssist, size);
    // Finding the index for the highest performing player
    int hightPerformance = calculatePerformance(playerGoals, playerAssist, size);
    // Use hightPerformance variable to calculate the player's performance
    int calculateHighestPerformance = playerAssist[hightPerformance] + 3 * playerGoals[hightPerformance];

    // Printing the header
    cout << setw(20) << "Full Name"
         << setw(10) << "Goals"
         << setw(10) << "Assists"
         << setw(15) << "Performance" << endl;
    cout << "-----------------------------------------------------------" << endl;

    // Iterating through the array displaying the play's stats
    for (int i = 0; i < size; ++i) {
        int performance = playerAssist[i] + 3 * playerGoals[i];
        cout << setw(20) << playerName[i]
             << setw(10) << playerGoals[i]
             << setw(10) << playerAssist[i]
             << setw(15) << performance << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
    cout << "Most Goals: " << playerName[highestGoals] << " ~ total: " << playerGoals[highestGoals] << endl;
    cout << "Most Assist: " << playerName[highestAssist] << " ~ total: " << playerAssist[highestAssist] << endl;
    cout << "Best Performance: " << playerName[hightPerformance] << " ~ total: " << calculateHighestPerformance << endl;
}

int highestRanked(int player_stats[], int length)
{
    int max, player_index;
    // Starting value to compare to the rest of the array
    max = player_stats[0];
    // Storing the index of the value that is in the max variable
    player_index = 0;

    // Iterating through the array comparing the max variable
    for (int i = 1; i < length; i++) {
        // Swapping values and index if the iteration is larger
        if (max < player_stats[i]) {
            max = player_stats[i];
            player_index = i;
        }
    }
    // return the player index with the hight value
    return player_index;
}
int calculatePerformance(int goals[], int assist[], int counter)
{
    int best_performance = assist[0] + 3 * goals[0];
    int player_index = 0;
    int challenging_performance;

    for (int i = 1; i < counter; i++) {
        challenging_performance = assist[i] + 3 * goals[i];

        if (best_performance < challenging_performance) {
            best_performance = challenging_performance;
            player_index = i;
        }
    }
    return player_index;
}

int extractStats(string fileName, string playerName[], int playergoals[], int playerAssist[])
{
    // Creating an ifstream object
    ifstream in_file;

    // Opening the file
    in_file.open(fileName.c_str());

    // Error checking that the file was founded
    if (!(in_file)) {
        cout << "Error: File was not found...";
        exit(1);
    }

    // Creating the variables that will hold the extracted file data
    string firstName, lastName, extracted_three, extracted_four, full_name;
    int goals, assist;
    // creating the counter variable to keep track of how many players there are
    int count = 0;

    // Iterating through the file,while extracting the data
    while (in_file >> firstName) {
        in_file >> lastName;
        // Combining the first and last name from two separate file data
        full_name = firstName + " " + lastName;

        in_file >> extracted_three;
        in_file >> extracted_four;
        // Converting the file string data to an integer data type
        goals = stoi(extracted_three);
        assist = stoi(extracted_four);
        // Storing the extracted data from the file in the array index
        playerName[count] = full_name;
        playergoals[count] = goals;
        playerAssist[count] = assist;
        // Keeping track of the number of iterations
        count++;
    }
    in_file.close();
    in_file.clear();

    return count;
}
