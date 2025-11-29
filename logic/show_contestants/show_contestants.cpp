#include "show_contestants.h"

void printAllContestants(Contestants contestant[]){
   // cout << "------All contestants------" << endl;
    
    linePrinter("All contestants",SCREENWIDTH, '-');

    bool hasContestants = false;
    for(int i = 0; i < MAXCONTESTANTS; i++){

        int validIndex = findFreeIndex(contestant, 1, i);
        i = validIndex;

        //When findFreeIndex is done it outputs -1. This "if" breaks when detects -1;
        if (validIndex == -1) {
            cout << endl;
            
            if(!hasContestants) cout << "### No contestants ###\n";

            break;
        }
        hasContestants = true;
        printContestant(contestant, validIndex);
    }
    
    linePrinter("", SCREENWIDTH, '-');
}