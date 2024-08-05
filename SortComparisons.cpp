/* SortComparisons.cpp - Compare selection and bubble sorting algorithm performance
 * Author:    Nathan Ilescas
 * Module:     16
 * Project:    Homework 2
 * Problem statement:  Create two identical vectors of 500 int values stored in
 *    random order.  Use a selection sort function and determine the number of
 *    comparisons and the number of swaps required.  Do the same thing using a
 *    bubble sort.  Then use each of the (now sorted) vectors to determine the same
 *    thing.
 *
 * Algorithm:
 *   1. Create four functions:
 *      1a. First takes a vector and two ints, then swaps the items at the
 *          positions specified by the two indexes.
 *      1b. Second takes a vector, performs a selection sort on that vector,
 *          and updates the number of comparisons, passes, and updates (passed
 *          as parameters).
 *      1c. Third takes a vector, performs a bubble sort on that vector, and
 *          updates the number of comparisons, passes, and swaps (passed as
 *          parameters).
 *      1d. Fourth prints a formatted line showing a description of what's being
 *          shown, the number of comparisons, the number of swaps, and the number
 *          of passes returned from steps 1b and 1c.
 *   2. In main, create two identical vectors of 500 random ints.
 *   3. Call the function that performs a selection sort and displays the results
 *      (number of comparisons, passes, and swaps).
 *   4. Call the function that performs a bubble sort and displays the results.
 *   5. Using the sorted vector from step 3, repeat step 3.
 *   6. Using the sorted vector from step 4, repeat step 4.
 *   7. Increase the number of items in the vectors by 10 and repeat steps 2 - 6.
 *      Notice the increase in the number of comparisons, passes, and swaps.
 *   8. Change the vector in step 2 to contain 500 doubles (instead of ints)
 *      and redo steps 2 - 7.
 *
 * Notes:
 *    * Passing vectors by reference (default is by value)
 *    * Subtracting number of passes from inner loop of bubble sort
 *    * Increase number of passes by 10 -> increases results by 100 in both sorting
 *      algorithms
 *    * Selection sort does same work whether or not the vector is sorted
 *    * On unsorted vector, number of swaps for bubble sort is horrible
 *    * Bubble sort goes from worse performer to best performer when
 *      vector is already sorted.
 *    * Use of typedef to change vector from ints to doubles
 *      -- Don't forget to change initialization of vector when changing
 *         from ints to doubles.
 */

#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

typedef double base_type;

// Prototypes for functions (vectors must be passed by reference)
void swap(vector<base_type>&, int, int);
void selectionSort(vector<base_type>&, int&, int&, int&);
void bubbleSort(vector<base_type>&, int&, int&, int&);
void showResults(string, int, int, int);

// constants
const int VECTOR_SIZE = 5000; // elements in the array

int main()
{
    // Create two vector of 500 double values in random order
    // First will be used by selection sort, the second by bubble sort
    vector<base_type> vector1(VECTOR_SIZE);
    vector<base_type> vector2(VECTOR_SIZE);

    srand(time(0));
    for (int i = 0; i < VECTOR_SIZE; i++) {
        vector1[i] = vector2[i] = rand();

        // When using doubles, use a number between 0 and 999
        // vector1[i] = vector2[i] = 1000.0 * rand() / RAND_MAX ;
    }

    int comparisons = 0,
        swaps = 0,
        passes = 0;

    cout << setw(40) << " " << "Compares   Swaps   Passes" << endl;

    // Use the selection sort on vector 1 and print the results
    selectionSort(vector1, comparisons, swaps, passes);
    showResults("Selection sort on unsorted array", comparisons, swaps, passes);

    comparisons = 0,
    swaps = 0,
    passes = 0;

    // Use the bubble sort on vector2 and print the results
    bubbleSort(vector2, comparisons, swaps, passes);
    showResults("Bubble sort on unsorted array", comparisons, swaps, passes);

    comparisons = 0,
    swaps = 0,
    passes = 0;

    // Use the sorted vectors to compare the unsorted/sorted numbers
    selectionSort(vector1, comparisons, swaps, passes);
    showResults("Selection sort on sorted array", comparisons, swaps, passes);

    comparisons = 0,
    swaps = 0,
    passes = 0;

    // Use the bubble sort on vector2 and print the results
    bubbleSort(vector2, comparisons, swaps, passes);
    showResults("Bubble sort on sorted array", comparisons, swaps, passes);

    // Print the first few values of each vector
    cout << "\nThe first 50 values of vector1" << endl;
    for (int i = 0; i < 50; i++) {
        cout << vector1[i] << " ";
    }

    cout << "\n\nThe first 50 values of vector2" << endl;
    for (int i = 0; i < 50; i++) {
        cout << vector2[i] << " ";
    }
    cout << endl
         << endl;

    exit(0);
}

/* Swap two elements in a vector */
void swap(vector<base_type>& vector_to_sort, int x, int y)
{
    base_type temp = vector_to_sort[x];
    vector_to_sort[x] = vector_to_sort[y];
    vector_to_sort[y] = temp;
}

/* Selection sort makes continuous passes, putting the smallest element in the
 * first element in element 0, then the next smallest in element 2, etc.
 */
void selectionSort(vector<base_type>& vector_to_sort, int& comparisons, int& swaps, int& passes)
{
    for (int start = 0; start < VECTOR_SIZE - 1; start++) {
        passes++;
        int minValue = vector_to_sort[start],
            minIndex = start;

        for (int index = start + 1; index < VECTOR_SIZE; index++) {
            comparisons++;
            if (minValue > vector_to_sort[index]) {
                minValue = vector_to_sort[index];
                minIndex = index;
            }
        }
        swaps++;
        swap(vector_to_sort, start, minIndex);
    }
}

/* Bubble sort makes continuous passes, swapping neighboring elements to
 * put them in order.  Continue passes until there are no more swaps.
 */
void bubbleSort(vector<base_type>& vector_to_sort, int& comparisons, int& swaps, int& passes)
{
    for (int end = VECTOR_SIZE - 1; end > 0; end--) {
        passes++;
        for (int index = 0; index < end; index++) {
            comparisons++;
            if (vector_to_sort[index] > vector_to_sort[index + 1]) {
                swap(vector_to_sort, index, index + 1);
                swaps++;
            }
        }
    }
}

// Display the results of running a sorting algorithm
void showResults(string description, int comparisons, int swaps, int passes)
{
    cout << setw(40) << left << description
         << setw(8) << right << comparisons
         << setw(8) << swaps
         << setw(8) << passes
         << endl;
}
