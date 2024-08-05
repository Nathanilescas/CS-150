/* -Title: Loan Calculator
* -Description: This program calculates the total interest paided and the duration 
* -Author: Nathan Ilescas 
* -Module: 8
* -Project: Homework 8 - Stereo System Loan Payoff
* -Problem Statement: Calculate the duration and the interest paid over the life of the loan.
* -Algorithm: 
    1. Set the constant variables for the loan (loan amount, interest, payments)
    2. Define the rest of the variables that will play apart of the calculations (monthly interest, principal, etc..)
    3. Create a while loop to use with the calculation of the loan
    4. Use the formula to calculate the loan payment 
    5. if balance is less then 0 then get out of the loop
    5.a Go back to step 4 and use the formula again 
    6. Display the results

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Instantiating the const variable for the loan 
    const double LOAN_AMOUNT = 1000, INTEREST= 0.015, MONTHLY_PAYMENT = 50.00;
    // Defining the variable that will hold the data while the program is running
    double monthly_interest_amount, principal_amount, current_balance = LOAN_AMOUNT;
    // Instantiating the variable that will hold the interest and number of payments
    double total_interest = 0, number_of_payments = 0;

    while (current_balance > 0) {
        // Using the loan formula to calculate the loan 
        monthly_interest_amount = current_balance * INTEREST; 
        total_interest += monthly_interest_amount;
        principal_amount = MONTHLY_PAYMENT - monthly_interest_amount;
        current_balance -= principal_amount;
        
        number_of_payments++;
    }
    // Displaying the results
    cout << "Loan Duration: " << number_of_payments << " months" << endl;
    cout << "Total Interest: $" << fixed << setprecision(2) << total_interest << endl;
}