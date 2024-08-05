/* -Title: Name Finder
* -Description: This program searches through two list to find a name that the user inputted
* -Author: Nathan Ilescas 
* -Module: 9
* -Project: Homework 9 -  Popular Baby Names
* -Problem Statement: Given two list, findout if a given name is within those two list.
* -Algorithm: 
    1. Initialize the file path for both list
    2. Prompt the user for a name
    3. If user enters "Quit" exit the loop i.e the program
    4. Else use the ifsteam object to open up a file using the file paths from step 1
    5. Error check to see if file was found
    6. Using the ">>" operator loop through the open file
    6.a ompare the name within the file with the user's input
    7. Display the results of the search
    8. Repeat steps 4 -7 for the second list
    9. Start from step 2 again

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    // File path variables
    const string BOY_LIST = "BoyNames2023.txt", GIRL_LIST = "GirlNames2023.txt";

    // Prompting the user for a name
    string user_input;
    cout << "Enter the name to search for: ";
    cin >> user_input;


    while (user_input != "Quit") {

        // Creating an ifstream object to use the open method to access the txt file
        ifstream in_file;
        in_file.open(BOY_LIST.c_str());

        // Error checking
        if (!in_file) {
            cout << "ERROR: \"" << BOY_LIST << "\" not found...";
            exit(1);
        }

        // Defining/Initializing variables to use in searching for the name within the file
        string name, dummy;
        int registered_births;
        int count = 1;
        bool is_found = false;

        // Search for the name that the user inputted by using a loop
        while (in_file >> name)
        {
            if (name == user_input) {
                in_file >> registered_births;
                is_found = true;
                break;
            }
            else {
                in_file >> dummy;
            }

            count++;
        }

        // Deciding what to display depending if the name was found
        if (is_found) {
            cout << name << " is ranked " << count << " among boys with " << registered_births << " registered births." << endl;
        }
        else {
            cout << user_input << " is not ranked amoung the top 1000 boy names." << endl; 
        }

        // Closing and clear the file for the next search
        in_file.close();
        in_file.clear();


        // Repeating the process 
        in_file.open(GIRL_LIST.c_str());

        if (!in_file) {
            cout << "ERROR: \"" << GIRL_LIST << "\" not found...";
            exit(2);
        }

        // Resetting the variables
        is_found = false;
        count = 1;

        while (in_file >> name)
        {
            if (name == user_input) {
                in_file >> registered_births;
                is_found = true;
                break;
            }
            else {
                in_file >> dummy;
            }

            count++;
        }

        if (is_found) {
            cout << name << " is ranked " << count << " among girls with " << registered_births << " registered births." << endl;
        }
        else {
            cout << user_input << " is not ranked amoung the top 1000 girl names." << endl; 
        }

        in_file.close();
        in_file.clear();


        // Asking again for a name 
        cout << "Enter the name to search for: ";
        cin >> user_input;

    }

}