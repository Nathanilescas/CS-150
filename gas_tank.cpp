/* -Title: Gas Tank Calculator
* -Description: This program calculates and displays the amount of gas you have depending on the level and capacity the user sets.
* -Author: Nathan Ilescas 
* -Module: 12
* -Project: Homework 12 - Gas Tank
* -Problem Statement: Create a program that hold values for gas level and capacity, plus have it calculate the current levels
* -Algorithm: 
    1. Create a class named GasTank
    2. Create variables named capacity and level
    3. Create a constructor for that class using default values and future setter methods (will define later)
    4. Create getter for the variables in step 2
    5. Create setter with the name certain restrictions
    6. Create a function that calculates the percentage of fuel in the tank
*/


#include <iostream>
#include <iomanip>

using namespace std;

// Defining Global Constants
double const DEFAULT_CAPACITY = 30.0;
double const MINIMUM_CAPACITY = 4.0;

class GasTank {

    private: 
        double _capacity;
        double _level;

    public:
        GasTank(double level = 0.0, double capacity = DEFAULT_CAPACITY) {
            this->setCapacity(capacity);
            this->setLevel(level);
            cout << "Level: " << this->_level << endl;
            cout << "Capacity: " <<  this->_capacity << endl;
        }

    // Getter
        double getLevel() const;
        double getCapacity() const;

    // Setter
        void setLevel(double);
        void setCapacity(double);

    // Function
    double calcFill() const;
    void showInfo() const;

        
};

int main() {

    // Creating working GasTank objects
    cout << "Gas Tank 1: " << endl;
    GasTank gasTank1;
    gasTank1.showInfo();
    cout << endl;

    cout << "Gas Tank 2: " << endl;
    GasTank gasTank2(13.5, 58.0);
    gasTank2.showInfo();
    cout << endl;

    cout << "Gas Tank 3: " << endl;
    GasTank gasTank3(0.0, 58.0);
    gasTank3.showInfo();
    cout << endl;

    cout << "Gas Tank 4: " << endl;
    GasTank gasTank4(18.6, 45.2);
    gasTank4.showInfo();

    cout << "\n************* ERROR CHECKING*************" << endl;

    // Error Checking GasTank objects
    cout << "Gas Tank 5: " << endl;
    GasTank gasTank5(-15.5, -25.5);
    gasTank5.showInfo();
    cout << endl;

    cout << "Gas Tank 6: " << endl;
    GasTank gasTank6(40, 30);
    gasTank6.showInfo();

}


// DEFINING GETTERS
double GasTank::getLevel() const {
    return this->_level;
}
double GasTank::getCapacity() const {
    return this->_capacity;
}

// DEFINING SETTERS
void GasTank::setLevel(double level) {
    if (level <= 0) {
        this->_level = 0;
    }
    else if (level >= this->_capacity) {
        this->_level = this->_capacity;
    }
    else {
        this->_level = level;
    }
}
void GasTank::setCapacity(double capacity) {
    if (capacity < MINIMUM_CAPACITY) {
        this->_capacity = MINIMUM_CAPACITY;
    }
    else {
        this->_capacity = capacity;
    }
}
double GasTank::calcFill() const {
    return this->_level / this->_capacity;
}
void GasTank::showInfo() const {
    cout << "Current Level: " << fixed << setprecision(1) << this->_level << endl;
    cout << "Current Capacity: " << fixed << setprecision(1) << this->_capacity << endl;
    cout << "Current Fill: " << fixed << setprecision(2) << this->calcFill() * 100 << "%" << endl;
}