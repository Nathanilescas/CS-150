/* -Title: Train Fare Optimal Calculator
* -Description: This program display all the possible cost for tickets and recommends the best option(cheapest)
* -Author: Nathan Ilescas 
* -Module: 7
* -Project: Homework 7 - Take the Train
* -Problem Statement: The program needs to calculate the cost from all the ticket options and display the best one.
* -Algorithm: 
    1. Define/Initiate const variables for : single, pack and monthly ticket prices
    2. Prompt the user for the number of ticket from 1 - 20; Make sure to validate that answer
    3. Calculate the price for each ticket rate from the user's input from step 2
    4. Using an if statement and the number of tickets the user inputted determine the best option
    4.a if tickets require under 7
    4.b if tckets require under 16
    4.c Monthly pass is the best option
*/

#include <iostream>
#include <iomanip>


using namespace std;

int main() {
    string dashes = "";

    const double SINGLE_TICKET = 5.40,
                 PACK_TICKET = 36.50, /*Subtract 10 from the number of tickets*/ 
                 MONTHLY_PASS = 61.85;
                  
    // Prompting the user for number of tickets
    int number_of_tickets;
    cout << "How many tickets do you need(from 1 to 20): ";
    cin >> number_of_tickets;

    // Validate the answer
    if (number_of_tickets < 0 || number_of_tickets > 21) {
        cout << "Sorry too many tickets, only 1 to 20...";
        exit(1);
    }

    double single_ticket_option, pack_ticket_option;
    single_ticket_option = SINGLE_TICKET * number_of_tickets;

    double pack_tickets = (number_of_tickets > 10) ? ((number_of_tickets - 10) * 4.25) : 0;
    pack_ticket_option = 36.50 + pack_tickets;

    cout << "Ticket Price Options:" << endl;
    cout << dashes.assign(22,'=') << endl;
    cout << "Single Ticket: " << fixed << setprecision(2) << single_ticket_option << endl;
    cout << "Pack Ticket : " << fixed << setprecision(2) << pack_ticket_option << endl;
    cout << "Monthly Ticket: " << fixed << setprecision(2) << MONTHLY_PASS << endl;

    // Calculating the best option bases of number of tickets
    if (number_of_tickets < 7) {
        cout << "\nBest Option: Single Tickets $" << fixed << setprecision(2) << single_ticket_option;
    }
    else if (number_of_tickets < 16) {
        cout << "\nBest Option: Pack Tickets $" << fixed << setprecision(2) << pack_ticket_option;
    }
    else {
        cout << "\nBest Option: Monthly Pass $" << fixed << setprecision(2) << MONTHLY_PASS; 
    }
 
}

