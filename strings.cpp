/* -Title: Name Capitalizer 
* -Description: This program capitalizes the first letter of your first, middle, and last names
* -Author: Nathan Ilescas 
* -Module: 5
* -Project: Homework 5 - Art supplies report, strings
* -Problem Statement: Create a program that capitalizes the first letter of your first, middle and last name.
* -Algorithm: 
    1. Create a full name string by combining multiple strings
    1.a Define and initialize your full name in separate variables. 
    1.b Combine your middle and last name with your first name variable 
    1.c Display the results.

    2. Capitalize the first letter of each name
    2.a Locate the positions using the at() function and save them to a variable.
    2.b Use the toupper() function to capitalize the variables from the previous step.
    2.c Convert them back to a string type due to step 3.a.
    2.d Using the replace() function, insert the capitalized letter back into the first_name variable.
    2.e Display the results.

    3. Locate the first and last positions of occurring spaces within the first_name variable:
    3.a Locate the position of the first space using the find() function and save it to a size_t variable.
    3.b Locate the last position using the rfind() method.
    3.c Display the results for both.

    4. Extract the middle name using the substr() function with the variables from step 3 as the arguments.
    4.a Display the results.
    
    5. Remove the middle name using the erase() function with the variables from step 4 as the arguments.
    5.a Display the results.
*/

#include <iostream>
#include <string>



using namespace std;
 
int main() {
    // Defining names
    string first_name = "nathan";
    string middle_name = "christopher";
    string last_name = "ilescas";

    // adding middle_name and last_name to first_name variable
    first_name += " ";
    first_name += middle_name;
    first_name.append(" ");
    first_name.append(last_name);
    // Displaying results
    cout << "My name in lower case: " << first_name << endl;


    // Extracting the first letter of each name (first, middle, last)
    char extracting_first_name_letter = first_name.at(0);
    char extracting_middle_name_letter = first_name.at(7);
    char extracting_last_name_letter = first_name.at(19);

    // Converting them into capital letters
    extracting_first_name_letter = toupper(extracting_first_name_letter);
    extracting_middle_name_letter = toupper(extracting_middle_name_letter);
    extracting_last_name_letter = toupper(extracting_last_name_letter);

    // Coverting the letters from char to string data types
    string convert_letter_first_name = string(1, extracting_first_name_letter);
    string convert_letter_middle_name = string(1, extracting_middle_name_letter);
    string convert_letter_last_name = string(1, extracting_last_name_letter);

    // Inserting back the letters back in their original place
    first_name.replace(0, 1, convert_letter_first_name);
    first_name.replace(7, 1 , convert_letter_middle_name);
    first_name.replace(19, 1, convert_letter_last_name);

    // Display sting to show capital letters 
    cout << "My name capitalized: " << first_name << endl;
    
    // Locating spaces within the text
    size_t first_space_location = first_name.find(" ");
    cout << "The first space is at position: "<< first_space_location << endl;
    size_t last_space_location = first_name.rfind(" ");
    cout << "The last space is at position: " << last_space_location << endl;


    // Modifiyng the space loctions
    first_space_location += 1;
    size_t middle_name_length = last_space_location - first_space_location;
    // Extracting middle name using substr function with the above variables
    string extracted_middle_name = first_name.substr(first_space_location , middle_name_length);
    cout << "My middle name is: " << "\"" << extracted_middle_name << "\"" <<endl;

    // Removing middle name from name string 
    string first_and_last_name = first_name.erase(first_space_location, middle_name_length);
    cout << "My shortened name is: " << "\"" << first_and_last_name << "\"" << endl;

}