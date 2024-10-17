// Satvik Talchuru A0P9K47
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>
// #include .......
using namespace std;

Car::Car() {
    manufacturer = nullptr;
    model = nullptr;
    zeroToSixtyNs = 0;
    headonDragCoeff = 0.0;
    horsepower = 0;
    seatCount = 0;
    backseatDoors = None;
}

Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign) {
    manufacturer = new char[strlen(manufacturerName) + 1];
    strcpy(manufacturer, manufacturerName);
    
    model = new char[strlen(modelName) + 1];
    strcpy(model, modelName);
    
    zeroToSixtyNs = perf.zeroToSixtyNs;
    headonDragCoeff = perf.headonDragCoeff;
    horsepower = perf.horsepower;
    seatCount = numSeats;
    backseatDoors = backseatDoorDesign;
}

Car::Car(Car const& o) {
    manufacturer = new char[strlen(o.manufacturer) + 1];
    strcpy(manufacturer, o.manufacturer);
    
    model = new char[strlen(o.model) + 1];
    strcpy(model, o.model);
    
    zeroToSixtyNs = o.zeroToSixtyNs;
    headonDragCoeff = o.headonDragCoeff;
    horsepower = o.horsepower;
    seatCount = o.seatCount;
    backseatDoors = o.backseatDoors;
}

Car::~Car() {
    delete[] manufacturer;
    delete[] model;
}

Car& Car::operator=(Car const& o) {
    if (this != &o) {
        delete[] manufacturer;
        manufacturer = new char[strlen(o.manufacturer) + 1];
        strcpy(manufacturer, o.manufacturer);

        delete[] model;
        model = new char[strlen(o.model) + 1];
        strcpy(model, o.model);

        zeroToSixtyNs = o.zeroToSixtyNs;
        headonDragCoeff = o.headonDragCoeff;
        horsepower = o.horsepower;
        seatCount = o.seatCount;
        backseatDoors = o.backseatDoors;
    }
    
    return *this;
}

char const* Car::getManufacturer() const {
    return manufacturer;
}

char const* Car::getModel() const {
    return model;
}

///
PerformanceStats Car::getStats() const {
    PerformanceStats stats;
    stats.horsepower = horsepower;
    stats.zeroToSixtyNs = zeroToSixtyNs;
    stats.headonDragCoeff = headonDragCoeff;
    return stats;
}

uint8_t Car::getSeatCount() const {
    return seatCount;
}

DoorKind Car::getBackseatDoors() const {
    return backseatDoors;
}

void Car::manufacturerChange(char const* const newManufacturer) {
    delete[] manufacturer;  
    manufacturer = new char[strlen(newManufacturer) + 1];
    strcpy(manufacturer, newManufacturer);
}

void Car::modelNameChange(char const* const newModelName) {
    delete[] model; 
    model = new char[strlen(newModelName) + 1];
    strcpy(model, newModelName);
}

void Car::reevaluateStats(PerformanceStats newStats) {
    zeroToSixtyNs = newStats.zeroToSixtyNs;
    headonDragCoeff = newStats.headonDragCoeff;
    horsepower = newStats.horsepower;
}

void Car::recountSeats(uint8_t newSeatCount) {
    seatCount = newSeatCount;
}

void Car::reexamineDoors(DoorKind newDoorKind) {
    backseatDoors = newDoorKind;
}