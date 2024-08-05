/* -Title: Budget Calculator
* -Description: This program calculates your budget
* -Author: Nathan Ilescas
* -Module: 13
* -Project: Homework 13 - Monthly Expenses
* -Problem Statement: Create a struct and functions that can budget your finances
* -Algorithm:
    1. Create a stuct that will contain 5 catagories of expenses (rent, transport, book & supplies, food, and miscellaneous)
    2. Encode the stuct from step one with values
    3. Repeat step one and two but use the getSpent() function to encode the values for that struct
    4. Uses the printTotal() to calculate/print the total difference of the values
*/

#include <iomanip>
#include <iostream>

using namespace std;

struct MonthlyExpense {
public:
    double rent_and_household;
    double transportation;
    double books_and_supplies;
    double food_and_supplies;
    double miscellaneous;
};

double getSpent(string);
void printLine(string, double, double);
void printHeader();
void printTotal(MonthlyExpense, MonthlyExpense);

int main()
{
    // First Struct Object and inputting the values
    MonthlyExpense budget;
    budget.rent_and_household = 1125.00;
    budget.transportation = 280.00;
    budget.books_and_supplies = 95.00;
    budget.miscellaneous = 390.00;

    // Second Struct Object
    MonthlyExpense spent;

    // Prompting the user for the struct object values
    cout << "Enter your actual monthly spending values: " << endl;
    spent.rent_and_household = getSpent("Rent & Household");
    spent.transportation = getSpent("Transportation");
    spent.books_and_supplies = getSpent("Books and Supplies");
    spent.miscellaneous = getSpent("Miscellaneous");

    printHeader();

    // Using the function to print the budget and spending overall
    printLine("Rent & Household", budget.rent_and_household, spent.rent_and_household);
    printLine("Transportation", budget.transportation, spent.transportation);
    printLine("Books and Supplies", budget.books_and_supplies, spent.books_and_supplies);
    printLine("Miscellaneous", budget.miscellaneous, spent.miscellaneous);

    printTotal(budget, spent);
}

double getSpent(string expense)
{
    double spent_value;

    do {
        cout << "Enter " << expense << " value: ";
        cin >> spent_value;

        if (!(spent_value > 0 && spent_value <= 10000)) {
            cout << "Value must be between 0 and 10,000" << endl;
        }
    } while (!(spent_value > 0 && spent_value <= 10000));

    return spent_value;
}
void printLine(string expenseName, double budget, double spent)
{
    double difference = budget - spent;
    cout << left << setw(20) << expenseName
         << "$" << right << fixed << setprecision(2) << setw(8) << budget << "    "
         << "$" << right << fixed << setprecision(2) << setw(8) << spent << "    "
         << "$" << right << fixed << setprecision(2) << setw(8) << difference << endl;
}
void printHeader()
{
    string dash;
    cout << right << setw(28) << "Budget"
         << setw(13) << "Actual" << endl;
    cout << left << setw(22) << "Category" << "Amount"
         << right << setw(12) << "Spent"
         << setw(15) << "Difference" << endl;
    cout << dash.assign(55, '-') << endl;
}
void printTotal(MonthlyExpense budget, MonthlyExpense spent)
{
    double budget_total = budget.rent_and_household + budget.transportation + budget.books_and_supplies + budget.miscellaneous;
    double spent_total = spent.rent_and_household + spent.transportation + spent.books_and_supplies + spent.miscellaneous;
    double difference_total = budget_total - spent_total;
    cout << left << setw(21) << "\nTotal"
         << "$" << right << fixed << setprecision(2) << setw(8) << budget_total << "    "
         << "$" << right << fixed << setprecision(2) << setw(8) << spent_total << "    "
         << "$" << right << fixed << setprecision(2) << setw(8) << difference_total << endl;
}