#include "debug.h"

void deBugInfo(const string& message, const bool& debugMode){
    if (debugMode){
        cout << message << endl;
    }
}


