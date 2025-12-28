#include "cin_validators.h"

bool checkCin(){
    if(cin) 
    {
        cin.clear(); 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        deBugInfo("SYSTEM: cin restarted" << endl);
        return true;
    } else {
        cin.clear(); 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        deBugInfo("ERROR: cin broke. Restarted" << endl);
        return false;
    }
}

void resetCin (){
    cin.clear(); // fix the stream
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // yeet the garbage
}
void casualCinReset(){
    resetCin ();
    deBugInfo("SYSTEM: cin restarted" << endl);
}
void neededCinReset(){
    resetCin ();
    deBugInfo("ERROR: cin broke. Restarted" << endl);
}

int cinCheckInt(const string& message) {
    int value;
    while (true) {
        cout << message;

        if (cin >> value) {
            casualCinReset();
            return value;
        } else {
            neededCinReset();
            cout << "Invalid input. Try again." << endl;
        }
    }
}


double cinCheckDouble(const string& message) {
    double value;
    while (true) {
        cout << message;//LATER: to be able to put values with , or . and have them intact

        if (cin >> value) {
            casualCinReset();
            return value;
        } else {
            neededCinReset();
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
        deBugInfo("gender: " << gender << endl);


        if (gender == 'm') {
            casualCinReset();
            return false;
        } else if (gender == 'f') {
            casualCinReset();
            return true;
        } else {
            cout << "Invalid gender. Try again (m/f): ";
            neededCinReset();
            deBugInfo("ERROR: cin broke. Restarted" << endl);
            cin >> input;
        }
    }
}