/*
 * Caliper
 *
 * Author: Zach McKenna
 *
 */

#include "Functions.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> // string streams are my favorite
#include <iomanip>
#include <algorithm> // All the necessary includes for Functions.cpp

using namespace std; // makes it easier and quicker

vector<MaintenanceRecord> getRecordsFromFile() { // This function reads the maint-records file from the project root and returns a vector of MaintenanceRecord objects, makes iterating real smooth
    ifstream recordsInFile("../maint-records"); // Open input file stream
    
    if(recordsInFile.fail()){
        cerr << "Record file has been deleted, moved, or hasn't been initialized... Please add a new record to initialize" << endl;
    } // If cant find file, probably moved or deleted
    
    string index;
    string vehicleName;
    string title;
    string odoString;
    string costString;
    string date;
    string location;
    
    vector<MaintenanceRecord> recordVector;
    string line; // All the variables for a record

    while(getline(recordsInFile, line, '\n')){ // Go through every line in the file
        stringstream lineStream(line);
        getline(lineStream, index, '\t');
        getline(lineStream, vehicleName, '\t');
        getline(lineStream, title, '\t');
        getline(lineStream, odoString, '\t');
        int odometer = stoi(odoString);
        getline(lineStream, costString, '\t');
        double cost = stod(costString);
        getline(lineStream, date, '\t');
        getline(lineStream, location, '\t'); // Gets each value from the file (they are tab deimited)
    
        MaintenanceRecord recordRead(index, vehicleName, title, odometer, cost, date, location); // New maintenance record
        recordVector.push_back(recordRead); // Put the record in the vector
    }
    return recordVector; // Send the vector back to the user
}

bool deleteRecord(string indexToDelete){ // Deletes record from file of specified index
    vector<MaintenanceRecord> allRecords = getRecordsFromFile();
    for(int i = 0; i < allRecords.size(); i++){ // Iterates over the vector and removes specified record and rewrites file without the removed vector
        if(allRecords.at(i).getIndex() == indexToDelete){
            allRecords.erase(allRecords.begin() + i);
            overwriteRecords(allRecords);
            return true; // If record was successfully deleted
        }
    }
    return false; // If it couldnt find index, probably user typo
}

void overwriteRecords(vector<MaintenanceRecord> overwriteRecords){ // Opens file in non appending mode so that old records arent kept, kinda dangerous, but it works
    std::ofstream recordsOutFile("../maint-records");

    if(recordsOutFile.fail()){
        std::cerr << "Failed opening output file." << std::endl;
    }
    for(int i = 0; i < overwriteRecords.size(); i++){
        recordsOutFile << overwriteRecords.at(i).getIndex() << "\t"
                       << overwriteRecords.at(i).getVehicleName() << "\t"
                       << overwriteRecords.at(i).getTitle() << "\t"
                       << overwriteRecords.at(i).getOdometer() << "\t"
                       << overwriteRecords.at(i).getCost() << "\t"
                       << overwriteRecords.at(i).getDate() << "\t"
                       << overwriteRecords.at(i).getLocation() << "\t" << "\n";
    } // Puts all maintenance records in the file, overwriting the old files
}

void printAllRecords(){ // Gets all the records from the file and print them.
    vector<MaintenanceRecord> allRecords;
    allRecords = getRecordsFromFile();
    if(allRecords.size() > 0){
        cout << "| "
             << setw(6) << left << "Index:" << " | "
             << setw(25) << left << "Vehicle Name:" << " | "
             << setw(30) << left << "Title:" << " | "
             << setw(9) << left << "Odometer:" << " | "
             << setw(10) << left << "Cost:" << " | "
             << setw(30) << left << "Date:" << " | "
             << setw(25) << left << "Location:" << "|" << endl;
        cout << "____________________________________________________________________________________________________________________________________________________________" << endl; //The title row
        for(int i = 0; i < allRecords.size(); i++){
            stringstream costStream;
            costStream << "$" << fixed << setprecision(2) << allRecords.at(i).getCost();
            string cost = costStream.str();
            cout << "| "
                << setw(6) << left << allRecords.at(i).getIndex() << " | "
                << setw(25) << left << allRecords.at(i).getVehicleName() << " | "
                << setw(30) << left << allRecords.at(i).getTitle() << " | "
                << setw(9) << left << allRecords.at(i).getOdometer() << " | "
                << setw(10) << right << cost << " | "
                << setw(30) << left << allRecords.at(i).getDate() << " | "
                << setw(25) << left << allRecords.at(i).getLocation() << "|" << endl; // All the data from the file
        }
    }else{
        cout << "No records to display" << endl; // If file is empty (different output if file doesnt exist)
    }
}

string generateIndex( size_t length ) //Epic little function that generates a random alphanumeric code of specified length
{
    auto randchar = []() -> char
    {
        const char CHARSET[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"; // Array of possible values
        const size_t max_index = (sizeof(CHARSET) - 1);
        return CHARSET[ rand() % max_index ]; // returns the random char or num
    };
    string str(length,0);
    generate_n( str.begin(), length, randchar );
    return str; // return the final alphanumeric string
}
