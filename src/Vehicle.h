#ifndef VEHICLE_H
#define ROCK_H
class Vehicle {
    private:
        string _name;
        string _make;
        string _model;
        int _year;
        string _color;
    public:
        Vehicle(string name, string make, string model, int year, string color);
        
        string getName();
        string getMake();
        string getModel();
        int getYear();
        string getColor();

        void setName(string name);
        void setMake(string make);
        void setModel(string model);
        void setYear(int year);
        void setColor(string color);
};
#endif
