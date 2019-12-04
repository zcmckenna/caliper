#ifndef MAINTENANCERECORD_H
#define MAINTENANCERECORD_H

#include <string> // Its all about those strings

class MaintenanceRecord { // Class definition
    private: //shhh
        std::string _vehicleName;
        std::string _title;
        int _odometer;
        double _cost;
        std::string _date;
        std::string _location;
        std::string _index; // cool private attributes!
    
    public: //Anyone can use these
        MaintenanceRecord(std::string index, std::string vehicleName, std::string title, int odometer, double cost, std::string date, std::string location); //Constructor definition
        
        std::string getVehicleName();
        std::string getTitle();
        int getOdometer();
        double getCost();
        std::string getDate();
        std::string getLocation();
        std::string getIndex(); // all those boring getters

        void setVehicleName(std::string vehicleName);
        void setTitle(std::string title);
        void setOdometer(int odometer);
        void setCost(double cost);
        void setDate(std::string date);
        void setLocation(std::string location);
        void setIndex(std::string index); //and the setters

        void writeRecordToFile(); // need to define this too
};
#endif
