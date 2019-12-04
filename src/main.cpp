/* Caliper
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream> // For cin and cout
#include <fstream> // For reading and writing to and from files
#include <limits> // For INT_MAX
#include <ctime> // For seeding random
#include "Functions.h" // Include file for seperate functions
using namespace std;

// Must have a function named "main", which is the starting point of a C++ program.
int main() {
    srand(time(0)); // Seed random for generating indices
    ifstream welcomeInput("../welcome-text"); // Get the ascii art from the welcom-text file
    
    if(welcomeInput.fail()){ // If cant open welcome file
        cerr << "Failed opening welcome text file, you are missing out on some great ascii art...";
    } // Error message if can't find welcome text file
    cout << endl; // Spacing
    for(string welcomeLine; getline(welcomeInput, welcomeLine);){
        cout << welcomeLine << endl;
    } // Open welcome-text file from the root directory and output the parse the text 
    int mainMenuInput; // For storing the users main menu choice
    cout << endl << "Maintenance History:" << endl;
            printAllRecords(); // Print all the records from the file
            cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << endl;
            cout << "Please choose an option:" << endl;
    while(mainMenuInput != 3){ // Run main menu until user exits
        MAINMENU:while(true){
            mainMenuInput = 0;
            cout << endl
                << "-Main Menu-"
                << endl
                << "(1) List maintenance history"
                << endl
                << "(2) Manage maintenance records"
                << endl
                << "(3) Exit Caliper"
                << endl
                << ":"; // Menu options
        
            if(!(cin >> mainMenuInput)){
                cout << endl << "Please enter an integer..." << endl;
                cin.clear();
		        cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }else if(mainMenuInput != 1 && mainMenuInput != 2 && mainMenuInput != 3){
                cout << endl << "Please enter either 1, 2, or 3..." << endl;
            }else{
                break;
            } // Make sure user only inputs the correct menu options
        }
        if(mainMenuInput == 1){ // If chooses to list maintenance hostory
            cout << endl << "Maintenance History:" << endl;
            printAllRecords(); // Print records from fi;e
            cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << endl;
        }else if(mainMenuInput == 2){ // If decides to manage records
            int recordMenuInput;
            while(true){ // Loops record menu until exited by user
                recordMenuInput = 0;
                cout << endl
                     << "-Maintenace Records Menu-"
                     << endl
                     << "(1) Add new maintenance record"
                     << endl
                     << "(2) Remove maintenance record"
                     << endl
                     << "(3) Back to main menu"
                     << endl
                     << ":"; // Output menu options
                if(!(cin >> recordMenuInput)){
                    cout << endl << "Please enter an integer..." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }else if(recordMenuInput != 1 && recordMenuInput != 2 && recordMenuInput != 3){
                    cout << endl << "Please enter 1, 2, or 3..." << endl;
                }else{
                    break;
                } // Make sure user is using all the right inputs
            }
                if(recordMenuInput == 1){ // If the user decides to create new record
                    string index = generateIndex(6); // Generate random alphanumeric index for deleting if needed
                    string trash;
                    string vehicleName;
                    string title;
                    int odometer;
                    string odoString;
                    double cost;
                    string costString;
                    string date;
                    string location; // All the vars the user will input
                    cin.clear(); // Clear previous inputs
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Please enter the name of the vehicle the record belongs to: ";
                    getline(cin, vehicleName);
                    cout << "Title of the maintenance record: ";
                    getline(cin, title);
                    cout << "Vehicle's mileage during maintenance(without commas): ";
                    getline(cin, odoString);
                    odometer = stoi(odoString);
                    cout << "Cost of the maintenance (For example: 12.96): ";
                    getline(cin, costString);
                    cost = stod(costString);
                    cout << "Date of maintenance: ";
                    getline(cin, date);
                    cout << "Where was the maintenace performed: ";
                    getline(cin, location); // Get all the users preferred record info using getlines so that whitespace is allowed

                    MaintenanceRecord userRecord(index, vehicleName, title, odometer, cost, date, location); // Create new maintenance record using the useres input
                    userRecord.writeRecordToFile(); // Write record to the file in append mode
                }else if(recordMenuInput == 2){ // If user wants to delete record
                    string indexToRemove;
                    while(true){ // Loop in case the index cant be found
                        cout << endl << "Please enter the index of the record to remove: ";
                        cin >> indexToRemove; // Get the index of the record
                        if(deleteRecord(indexToRemove)){ // Delete record, if its deleted successfully it return true
                            cout << "Record Removed..." << endl << endl;
                            cout << endl << "Maintenance History:" << endl;
                            printAllRecords();
                            cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << endl;
                            break; //Break free from the while loop
                        }else{ // If deleteRecord returns false because it couldnt find the index
                            cout << "Record could not be removed, please try again..." << endl;
                        }
                    }
                }else if(recordMenuInput == 3){ // User want to go to main menu
                    goto MAINMENU;
                }
            
        }
    }
    return 0; // Finished
}
