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

int cinCheckInt(const string& message) {
    int value;
    while (true) {
        cout << message;

        if (cin >> value) {
            resetCin ();
            deBugInfo("SYSTEM: cin restarted" << endl);
            return value;
        } else {
            resetCin ();
            deBugInfo("ERROR: cin broke. Restarted" << endl);
            cout << "Invalid input. Try again." << endl;
        }
    }
}


double cinCheckDouble(const string& message) {
    double value;
    while (true) {
        cout << message;//LATER: to be able to put values with , or . and have them intact

        if (cin >> value) {
            resetCin ();
            deBugInfo("SYSTEM: cin restarted" << endl);
            return value;
        } else {
            resetCin ();
            deBugInfo("ERROR: cin broke. Restarted" << endl);
            cout << "Invalid input. Try again." << endl;
        }
    }
}