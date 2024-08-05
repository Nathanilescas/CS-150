// Description: This program calculates the charges and fees for an service ride
// Author: Nathan Ilescas

#include <iostream>

using namespace std;

int main() {
    double airportFee = 2.51;
    cout << "The airport Fee is $" << airportFee << endl;
    double upFrontCharge = 3.72;
    cout << "The up-front charge is $" << upFrontCharge << endl;
    double totalDistanceCharge = 19.46;
    cout << "The total charge for distance is $" << totalDistanceCharge << endl;
    double driverTip = (upFrontCharge + totalDistanceCharge) * .08;
    cout << "The tip for the driver is $" << driverTip << endl;
    double totalCharge = airportFee + upFrontCharge + totalDistanceCharge + driverTip;
    cout << "The grand total is $" << totalCharge << endl;
    return 0;
}