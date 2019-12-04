#include "MaintenanceRecord.h"
#include <iostream>
#include <fstream>
#include <string> // Includes

MaintenanceRecord::MaintenanceRecord(std::string index, std::string vehicleName, std::string title, int odometer, double cost, std::string date, std::string location){ // Maintenance record constructor
    _vehicleName = vehicleName;
    _title = title;
    _odometer = odometer;
    _cost = cost;
    _date = date;
    _location = location;
    _index = index; // set the private variables
}

void MaintenanceRecord::writeRecordToFile(){ // Writes the record to the file in append mode
    std::ofstream recordsOutFile("../maint-records", std::ofstream::app);

    if(recordsOutFile.fail()){
        std::cerr << "Failed opening output file." << std::endl;
    }

    recordsOutFile << _index << "\t"
                   << _vehicleName << "\t"
                   << _title << "\t"
                   << _odometer << "\t"
                   << _cost << "\t"
                   << _date << "\t"
                   << _location << "\t" << "\n"; // outputs all attributes to the handy file
}

std::string MaintenanceRecord::getVehicleName(){
    return _vehicleName;
}

std::string MaintenanceRecord::getTitle(){
    return _title;
}

int MaintenanceRecord::getOdometer(){
    return _odometer;
}

double MaintenanceRecord::getCost(){
    return _cost;
}

std::string MaintenanceRecord::getDate(){
    return _date;
}

std::string MaintenanceRecord::getLocation(){
    return _location;
}

std::string MaintenanceRecord::getIndex(){
    return _index;
} // Standard getters, not much to see here

void MaintenanceRecord::setVehicleName(std::string vehicleName){
    _vehicleName = vehicleName;
}

void MaintenanceRecord::setTitle(std::string title){
    _title = title;
}

void MaintenanceRecord::setOdometer(int odometer){
    _odometer = odometer;
}

void MaintenanceRecord::setCost(double cost){
    _cost = cost;
}

void MaintenanceRecord::setDate(std::string date){
    _date = date;
}

void MaintenanceRecord::setLocation(std::string location){
    _location = location;
}

void MaintenanceRecord::setIndex(std::string index){
    _index = index;
} // And your standard setters, can let just anyone make changes to variables
