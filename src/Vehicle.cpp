#include "Vehicle.h"
#include <string>

void Vehicle::setName(std::string name){
    _name = name;
}

void Vehicle::setMake(std::string make){
    _make = make;
}

void Vehicle::setModel(std::string model){
    _model = model;
}

void Vehicle::setYear(int year){
    _year = year;
}

void Vehicle::setColor(std::string color){
    _color = color;
}

std::string Vehicle::getName(){
    return _name;
}

std::string Vehicle::getMake(){
    return _make;
}

std::string Vehicle::getModel(){
    return _model;
}

int Vehicle::getYear(){
    return _year;
}

std::string Vehicle::getColor(){
    return _color;
}

Vehicle::Vehicle(std::string name, std::string make, std::string model, int year, std::string color){
    _name = name;
    _make = make;
    _model = model;
    _year = year;
    _color = color;
}
