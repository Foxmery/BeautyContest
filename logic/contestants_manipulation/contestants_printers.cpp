#include "contestants_printers.h"

void printContestant(Contestants contestant[], int index){

    deBugInfo("Index: " << index << "   ");
    cout << "ID: " << contestant[index].ID << "   ";
    cout << "Name: " << contestant[index].name << "   ";
    cout << "Age: " << contestant[index].age << "   ";
    cout << "Gender: " << ((contestant[index].isWoman) ? "Woman" : "Man") << "   ";
    cout << "HipCirc: " << contestant[index].hipCirc << "   ";
    cout << "ShoulderCirc: " << contestant[index].shoulderCirc << "   ";
    cout << "CalfCirc: " << contestant[index].calfCirc << "   ";
    cout << "NeckCirc: " << contestant[index].neckCirc << "   ";
    cout << "Points: " << contestant[index].points << "   ";
    cout << endl;
}
void printAllContestants(Contestants contestant[]){
    bool hasContestants = false;
    //LATER: implement  i = getNextUsedSlot(contestant, i + 1) hehehe if it really works
    for(int i = 0; i < MAXCONTESTANTS; i++){

        int validIndex = getNextUsedSlot(contestant, i);
        i = validIndex;

        //When findNextIndexByStatus is done it outputs -1. This "if" breaks when detects -1;
        if (validIndex == -1) {
            cout << endl;
            
            if(!hasContestants) cout << "### No contestants ###\n\n";

            break;
        }
        hasContestants = true;
        printContestant(contestant, validIndex);
    }
}

void printAllContestantsFormatted(Contestants contestant[], string message){
    titlePrinter(message, SCREENWIDTH, '-');
    printAllContestants(contestant);
    titlePrinter("", SCREENWIDTH, '-');
    cout << endl;
    
}