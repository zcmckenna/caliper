#include "Functions.h"
#include <vector>
using namespace std;

vector<Vehicle> getVehiclesFromFile() {
    Vehicle vehicle1("Lexus GX", "Lexus", "GX470", 2004, "Blizzard Pearl");
    Vehicle vehicle2("LC80", "Toyota", "Land Cruiser 80 Series", 1997, "Blue");
    vector<Vehicle> vehicleVector;
    vehicleVector.push_back(vehicle1);
    vehicleVector.push_back(vehicle2);
    return vehicleVector;
}
