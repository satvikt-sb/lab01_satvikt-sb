#include "car.hpp"
#include <iostream>

using namespace std;

int main() {
    // Test the default constructor
    Car car1;
    cout << "Default constructor: Manufacturer = " << (car1.getManufacturer() ? car1.getManufacturer() : "null") << endl;
    cout << "Default constructor: Model = " << (car1.getModel() ? car1.getModel() : "null") << endl;
    cout << "Default constructor: Seat count = " << unsigned(car1.getSeatCount()) << endl;

    // Test the parameterized constructor
    PerformanceStats perf = {500, 3000000000, 0.29};
    Car car2("Audi", "R8", perf, 2, GullWing);
    cout << "Parameterized constructor: Manufacturer = " << car2.getManufacturer() << endl;
    cout << "Parameterized constructor: Model = " << car2.getModel() << endl;
    cout << "Parameterized constructor: Horsepower = " << car2.getStats().horsepower << endl;

    return 0;
}