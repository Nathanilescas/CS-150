/* -Title: De-deplicationinator
* -Description: This program removes duplict numbers from a text file 
* -Author: Nathan Ilescas 
* -Module: 9
* -Project: Homework 9 - Deduplication
* -Problem Statement: The program must be able to keep track of outputted, duplicated and
 inputted numbers but also output a new list that hold the non-duplicated numbers from the original list
* -Algorithm: 
    1. Define variables that will hold a count
    2. Prompt the user for an input and input file name.
    3. Open the files 
    4. Error check if the files open 
    5. Extract the data from the input file
        - Extract an integer from the input file 
        - Using the while loop, extract another integer from the output file until the input file is empty
        - compare the first int with the second to see if they're duplicates
            - if not equal: then add the first int to the output file
        - assign the second int to the first int so you can test the second number
        - return to the second step 
    6. Output the results
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Defining variables to hold data about the list
    int in_file_number = 0, out_file_number = 0, duplicate_number = 0;
    string in_file_path, out_file_path;

    // Prompting the user for the file path of the input and output file
    cout << "Enter input file name: ";
    cin >> in_file_path;

    cout << "Enter output file name: ";
    cin >> out_file_path;

    // Creating the stream object
    ifstream in_file;
    ofstream out_file;
    // Opening the both files
    in_file.open(in_file_path.c_str());
    out_file.open(out_file_path.c_str());

    // Error checking
    if (!(in_file && out_file)) {
        cout << "Error: File was not found...";
        exit(1);
    }
    
    // Defining variables that hold the extracted numbers from the output file
    int extracted_num_one, extracted_num_two;

    // Outputting only the non-duplicate numbers and keeping track of (outputted, duplicated and inputted numbers)
    in_file >> extracted_num_one;
    while (in_file >> extracted_num_two) {

        if (extracted_num_one != extracted_num_two) {
            out_file << extracted_num_one << endl;
            out_file_number++;
        }
        else {
            duplicate_number++;
        }
        in_file_number++;
        extracted_num_one = extracted_num_two;
    }
    out_file << extracted_num_one;
    out_file_number++;
    in_file_number++;

    in_file.close();
    in_file.clear();
    out_file.close();
    out_file.clear();
    

    // Displaying the results
    cout << "There were " << in_file_number << " numbers input, " << out_file_number << " output, and " << duplicate_number << " duplicates."; 
}