/* -Title: Updating a Message
* -Description: This program contain functions that let you update, remove and display an array
* -Author: Nathan Ilescas
* -Module: 14
* -Project: Homework 14 - Remove Elements from a Message
* -Problem Statement: Create functions that can preform actions on an array by removing, updating and showing the elements within it
* -Algorithm:
    1. Initialize the array with char data types
    2. Determine the size of the array using the sizeof() function
    3. Display the initial array using the custom function
        3.a Use the heading argument to print a heading statement
        3.b Iterate through the array printing the array element from the array
        3.c Once complete exit the function
    4. Remove an element of the array using the remove() function
        4.a Error check the length and remove_index argument
        4.b Iterate through the array swapping positions starting from the remove_index argument
        4.c Once complete assign the last index the character 'X'
        4.d Return the length - 1
    5. Use the update() function to update the character using the parameters provided by the function
        5.a Create a variable to hold the char value
        5.b Update ASCII value of the char variable from the step previous
        5.c Insert the update value back into the same spot that you retrieved it from
    6. Use the remove() function on spot 0 and 2
    7. Use the update() function of on spot 1 and remove -55
    8. Use the remove() function on the last spot
    9. Finally display the elements of the array using the showArray() function
*/

#include <iostream>

using namespace std;

int remove(char[], int, int);
void update(char[], char, int);
void showArray(string, char[], int);

int main()
{
    char message[7] = { 't', 'Q', 'b', ')', 'f', '+', '5' };
    int count = sizeof(message) / sizeof(char);
    showArray("First Instance of the array: ", message, count);
    count = remove(message, 7, 3);
    update(message, -14, 1);
    count = remove(message, count, 0);
    count = remove(message, count, 2);
    update(message, -55, 1);
    count = remove(message, count, count - 1);
    showArray("Final Instance of the array: ", message, count);
}

int remove(char array[], int length, int remove_index)
{
    // Error checking the length argument
    if ((length != 0 || remove_index < length)) {
        // Removing a char starting from remove_index and incrementing it using the 'i' variable
        for (int i = 0; i < length; i++) {
            array[remove_index + i] = array[remove_index + (i + 1)];
        }
    }
    // Replacing the last index with an 'X' character
    array[length - 1] = 'X';
    // Returning the length minus one to reduce the size of the array for future use
    return length - 1;
}

void update(char array[], char amount, int index)
{
    // Saving the character within a variable
    char update_char = array[index];
    // Adding the argument amount to the character
    update_char += amount;
    // Inserting the updated character back into the array, at the same spot
    array[index] = update_char;
}

void showArray(string heading, char array[], int count)
{
    // Displaying the header
    cout << heading << endl;

    // Displaying the array using a for loop
    for (int i = 0; i < count; i++) {
        cout << array[i] << " ";
    }

    cout << endl;
}