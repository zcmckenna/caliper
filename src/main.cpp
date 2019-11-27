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
using namespace std;

// Must have a function named "main", which is the starting point of a C++ program.
int main() {
    ifstream welcomeInput("../welcome-text");
    
    if(welcomeInput.fail()){
        cerr << "Failed opening welcome text file";
        return -1;
    } // Error message if can't find welcome text file
    cout << endl;
    for(string welcomeLine; getline(welcomeInput, welcomeLine);){
        cout << welcomeLine << endl;
    } // Open welcome-text file from the root directory and output the parse the text 
    int mainMenuInput;
    
    while(true){
        mainMenuInput = 0;
        cout << endl
             << "(1) List maintenance history"
             << endl
             << "(2) Manage maintenance records"
             << endl
             << ":";
        
        if(!(cin >> mainMenuInput)){
            cout << "Please enter an integer..." << endl;
            cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else if(mainMenuInput != 1 && mainMenuInput != 2){
            cout << "Please enter either 1 or 2..." << endl;
        }else{
            break;
        }
    }
    cout << "Good to go..." << endl;
	return 0;
}
