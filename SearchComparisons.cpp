/* SearchComparisons.cpp - Compare linear vs. binary search algorithm performance
 * Author:     Nathan Ilescas
 * Module:     16
 * Project:    Homework 1
 * Problem statement: Determine the number of comparisons made looking for
 *     an element in an array using a linear search and using a binary search.
 *
 * Algorithm:
 *   1. Create a vector of 1000 double values stored in ascending order.
 *      1a. Call the two functions described below looking for the element
 *          at position 271.
 *      1b. Call both functions looking for the element at the midpoint
 *      1c. Call both functions looking for the element at the 3/4 point
 *      1d. Call both functions looking for the element at the end of the array
 *      1e. call both functions looking for an element not in the array (one more
 *          than the largest element).
 *   2. The first function uses a linear search algorithm to locate a specified
 *      value in the vector array that matches a "key" and returns a
 *      count of the number of comparisons it makes until it finds the specified value.
 *      2a. Use a loop to check each element in the array
 *      2b. After each iteration of the loop, increment the number of comparisons.
 *      2c. Return when the element when the key is found or after every element
 *          has been checked.
 *   3. Call another function that uses a binary search algorithm to locate
 *      the same value in the array and return a count of the number of comparisons
 *      it makes.
 *      3a. Set the low to the first element in the array and the high to the
 *          last number in the array
 *      3b. Calculate the element half way between low and high (the "midpoint").
 *      3c. Increment the number of comparisons by 1.
 *      3d. If the element at that index is equal to the search key return.
 *      3c. If the element is less than the one at the midpoint, then set high
 *          to the midpoint and loop back to step 3b
 *      3d. Otherwise set low to the midpoint and loop back to step 3b
 *      3e. Stop looping when high is less than low.
 *   4. Display the counts returned from both functions on the screen.
 *
 * Discussion:
 *    Run the program using 1,000 elements, then run again using 100,000 elements.
 *    Notice that the numbers for linear search go up 100 times, but the numbers
 *    for the binary search go up by less than two times!
 */

#include <ctime>
#include <iostream>
using namespace std;

// Prototypes for two functions, one does a linear search, the other a binary search
int linearSearch(const double[], int, double);
int binarySearch(const double[], int, double);

// constants
const int ARRAY_SIZE = 10000; // elements in the array

int main()
{
    // Create a vector of 1000 double values in ascending order
    double array_to_search[ARRAY_SIZE];
    array_to_search[0] = 0.0;

    srand(time(0));
    double divisor = static_cast<double>(RAND_MAX);
    for (int i = 1; i < ARRAY_SIZE; i++) {
        array_to_search[i] = array_to_search[i - 1] + (static_cast<double>(rand()) / divisor);
    }

    // Run test cases for elements 271, 499, 749, and at 999.  Also run a test case
    // for one more than the last element in the array.
    // The element 499 will be the midpoint, the element 749 will be at 3/4 of
    // the array size, and the element 999 will be the last element in the array
    int max = ARRAY_SIZE - 1; // last index in array
    for (int test = 1; test <= 5; test++) {
        double key = 0.0; // the target number
        string description = "";
        switch (test) {
        // A random value in the first half of the array
        case 1:
            key = array_to_search[271];
            description = "Element #271";
            break;
        // The midpoint
        case 2:
            key = array_to_search[max / 2];
            description = "Element #" + to_string(max / 2) + " - midpoint";
            break;
        // A random element in the second half (at position which 3/4 of the array size)
        case 3:
            key = array_to_search[max * 3 / 4];
            description = "Element #" + to_string(max * 3 / 4) + " - 3/4 point";
            break;
        // The last element in the array
        case 4:
            key = array_to_search[max];
            description = "Element #" + to_string(max) + " - last element";
            break;
        // An value that isn't in the array
        default:
            key = array_to_search[max] + 1.0;
            description = "not present";
            break;
        }

        cout << "Looking for " << key << " (" << description << ")" << endl
             << "   Linear search comparisons: "
             << linearSearch(array_to_search, ARRAY_SIZE, key) << endl
             << "   Binary search comparisons: "
             << binarySearch(array_to_search, ARRAY_SIZE, key) << endl
             << endl;
    }
}

/* linearSearch performs a linear search on an array of doubles (sorted or not)
 *   looking for a specific target or key.  Return the total number of comparisons
 *   made, whether or not the key is found.
 */
int linearSearch(const double search_array[], int size, double key)
{
    int comparisons = 0;
    int index = 0;
    bool isFound = false;

    while (index < size && !isFound) {
        if (search_array[index] == key) {
            isFound = true;
        } else {
            comparisons++;
            index++;
        }
    }

    return comparisons;
}

/* Perform a binary search for a specific key, returning the number
 *    of comparisons made whether the target is found
 */
int binarySearch(const double search_array[], int size, double key)
{

    int comparisons = 0;
    int low = 0;
    int high = size - 1;
    int midpoint = 0;
    bool isFound = false;

    while (low < high && !isFound) {
        midpoint = (low + high) / 2;

        if (search_array[midpoint] == key) {
            isFound = true;
        } else if (search_array[midpoint] > key) {
            high = midpoint - 1;
        } else {
            low = midpoint + 1;
        }
        comparisons++;
    }

    return comparisons;
}
