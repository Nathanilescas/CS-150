/* -Title: Letter Counterinator
* -Description: This program intakes multiple sentence and outputs the number of words and letters that sentence has
* -Author: Nathan Ilescas
* -Module: 15
* -Project: Homework 15 - Letter and Word Counter
* -Problem Statement: Create a program intakes sentences from the user and then searches through a vector and finds the number of letter and words there are in that sentence
* -Algorithms:
    Count Algorithm:
    1. Create two Vector objects - one for the letters of the alphabet and the other to keep track of the number of times each letter appears.
    2. Use a for loop to iterate through the input sentence Vector from the parameter.
    3. Use a nested loop to iterate through each character from the vector from the previous step.
    4. Use a final nested loop to iterate through the repeating letter vector from step one.
    5. Use the iterating values from the loops in steps 3 and 4 to access the correct character in the right sequence.
    6. Use the iterating value from the final nested loop to access the vector that holds the letters of the alphabet.
    7. Compare these values to see if they are equal.
    8. If so, increment the value of the vector that keeps track of the number of times the letter appears.
    9. Repeat until all the rows and characters in the argument vector have been iterated through.
    10. Finally, print the header and iterate through both vectors from step one, printing the values.
*/

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count(vector<string>, char);
vector<string> userInput();
bool isSentinel(string, char);

int main()
{
    vector<string> input = userInput();
    count(input, 'd');
}

int count(vector<string> input_sentence, char letter)
{

    vector<char> repeating_letters = {
        ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    };
    vector<int> count = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    int size = input_sentence.size();

    for (int i = 0; i < size; i++) { // Iterating through the rows
        int innerSize = input_sentence[i].size();

        for (int j = 0; j < innerSize; j++) { // Iterating through the individual letters

            int saveLettersSize = repeating_letters.size();

            for (int k = 0; k < saveLettersSize; k++) { // Iterating through the repeating letter vector

                // Saving the individual letters in both vector(easier to read)
                char sentence_Letter = tolower(input_sentence[i][j]);
                char recurringLetters = repeating_letters[k];

                if (sentence_Letter == recurringLetters) {
                    count[k]++;
                    break;
                }
            }
        }
        // Incrementing the space character to make sure I count the last word in the row
        count[0]++;
    }

    // Displaying the Header
    int number_of_letters = repeating_letters.size();
    cout << "\nThere are " << count[0] << " words in the text.\n"
         << endl;
    cout << "Here's the counts of characters for each letter: " << endl;

    // Setting the value for the number of time the function parameter appears
    int number_of_times = 0;
    // Iterating through the vector to display it
    for (int i = 1; i < number_of_letters - 1; i++) {

        if (count[i] != 0) {
            cout << repeating_letters[i] << ": " << count[i] << endl;
        }

        if (repeating_letters[i] == letter) { // Checking for the parameter letter
            number_of_times = count[i];
        }
    }
    return number_of_times;
}

vector<string> userInput()
{

    string input; // Holds user's input
    bool endSentence; // Determins whether or not to break the loop
    int counter = 0; // Keeps track of the index
    vector<string> userInputs; // Holds multiple strings of the user's input

    cout << "\nEnter several lines of text to analyze. When done, end a line with a period." << endl;
    while (true) {
        cout << ++counter << ": ";
        getline(cin, input); // Getting the user's input
        userInputs.push_back(input); // Adding it to the Vector

        endSentence = isSentinel(userInputs[counter - 1], '.'); // Checking if there is a period in the sentence
        if (endSentence) {
            break;
        }
    }
    return userInputs;
}

bool isSentinel(string sentence, char character)
{
    int size = sentence.size(); // Gets the size of the argument

    for (int i = 0; i < size; i++) { // Iterates through the argument
        char sentence_char = sentence[i]; // Accesses the index

        if (sentence_char == character) { // Compares to the char argument
            return true;
        }
    }
    return false;
}