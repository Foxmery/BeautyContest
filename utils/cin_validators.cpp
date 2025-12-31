/// @file cin_validators.cpp
/// @brief Helper functions to validate user input from the console.

#include "cin_validators.h"

void resetCin (){
    cin.clear(); // fix the stream
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // yeet the garbage
}


int cinCheckInt(const string& message) {
    int value;
    while (true) {
        cout << message;

        if (cin >> value) {
            resetCin();
            return value;
        } else {
            resetCin();
            cout << "Invalid input. Try again." << endl;
        }
    }
}


double cinCheckDouble(const string& message) {
    double value;
    while (true) {
        cout << message;

        if (cin >> value) {
            resetCin();
            return value;
        } else {
            resetCin();
            cout << "Invalid input. Try again." << endl;
        }
    }
}

bool cinCheckIsWoman(const string& message){
    
    while(true) {
        cout << message;

        char input = ' ';
        cin >> input;
        
        deBugInfo("SYSTEM: input: " << input << " | ");
        char gender = tolower(input); 
        deBugInfo("Gender: " << gender << endl);


        if (gender == 'm') {
            resetCin();
            return false;
        } else if (gender == 'f') {
            resetCin();
            return true;
        } else {
            cout << "Invalid gender. Try again!" << endl;
            resetCin();
            deBugInfo("ERROR: cin broke. Restarted" << endl);
        }
    }
}