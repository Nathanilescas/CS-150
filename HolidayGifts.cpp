// Description: This program calculates the total number of items (toolSet/drawingSet) you can buy with 100$ and it also tells you the left over change.
// Author: Nathan Ilescas

#include <iostream>

using namespace std;

int main() {
    double budget = 100;

    int number_of_toolSets = budget / 8.92;
    double total_amount_toolSet = number_of_toolSets * 8.92;
    double change_left_toolSet = budget - total_amount_toolSet;
    cout << "Cost of tool set is $8.92, you can buy " << number_of_toolSets << " sets with $" << change_left_toolSet << " change left over." << endl;

    int number_of_drawingSets = budget / 16.55;
    double total_amount_drawingSet = number_of_drawingSets * 16.55;
    double change_left_drawingSet = budget - total_amount_drawingSet;
    cout << "Cost of the drawing set is $16.55, you can buy " << number_of_drawingSets << " sets with $" << change_left_drawingSet << " change left over." << endl;

    return 0;
}