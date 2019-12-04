#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
    private:
        std::string _name;
        std::string _make;
        std::string _model;
        int _year;
        std::string _color;
    public:
        Vehicle(std::string name, std::string make, std::string model, int year, std::string color);
        
        std::string getName();
        std::string getMake();
        std::string getModel();
        int getYear();
        std::string getColor();

        void setName(std::string name);
        void setMake(std::string make);
        void setModel(std::string model);
        void setYear(int year);
        void setColor(std::string color);
};
#endif
