#include "sorting_menu.h"

//LATER: SWITHC TO NEW SORTING FUNCTION sortContestants
//LATER: put fucnitons into separate file into contestans_manipulation/sorting.cpp
void sortContestantsID(Contestants contestant[]);
void sortContestantsName(Contestants contestant[]);
void sortContestantsAgeAscending(Contestants contestant[]);
void outputSortedNoChangeAlphabetically(Contestants contestant[]);
void outputSortedNoChangeAge(Contestants contestant[]);



void sortingMenu (Contestants contestant[], int& menuChoice){

    switch (menuChoice){
        case 0:
        {
            return;
        }
        case 1:
            sortContestantsAgeAscending(contestant);
            cout << "Contestants sorted successefully!\n";
            break;

        case 2:
            sortContestantsName(contestant);
            break;

        case 3:
            outputSortedNoChangeAlphabetically(contestant);
            break;

        case 4:
            outputSortedNoChangeAge(contestant);
            break;
        case 5: 
            //LATER: put it on top of list
            sortContestantsID(contestant);
            break;
;        default:
            cout << "Invalid option!" << endl;
            deBugInfo("ERROR: expected from 0 - 5 got: " << menuChoice << endl);
            break;
    }
}

void sortContestantsAgeAscending(Contestants contestant[]){

    int validIndex = getNextUsedSlot(contestant, 0);
    int nextValidIndex = getNextUsedSlot(contestant, 1);

    bool slotsNeedProcessing = !(validIndex == -1) && !(nextValidIndex == -1);
    
    deBugInfo(endl << "SYSTEM: START validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl);
    for(int i = 0; i < MAXCONTESTANTS && slotsNeedProcessing; i++){

        bool lastIndex = validIndex == 0;
        bool nowLargerNext = contestant[validIndex].age > contestant[nextValidIndex].age;
        if(nowLargerNext){
            swapContestantPlaces(contestant, validIndex, nextValidIndex);
            if(lastIndex) {
                i = nextValidIndex;
            } else {
                i = i - 2;
            }
        } 
        deBugInfo("SYSTEM: lastIndex: " << lastIndex << " | " << "nowLargerNext: " << nowLargerNext << endl);

        validIndex = getNextUsedSlot(contestant, i);
        nextValidIndex = getNextUsedSlot(contestant, validIndex + 1);
        slotsNeedProcessing = !(validIndex == -1) && !(nextValidIndex == -1);
        deBugInfo("SYSTEM: validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl << endl);


        deBugInfo("validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl);
    }
}

void outputSortedNoChangeAlphabetically(Contestants contestant[]){
    Contestants alphSortedCont[MAXCONTESTANTS];
    dupeContestantInfo(contestant, alphSortedCont);

    sortContestantsName(alphSortedCont);

    printAllContestants(alphSortedCont);
}

void outputSortedNoChangeAge(Contestants contestant[]){
    Contestants alphSortedCont[MAXCONTESTANTS];
    dupeContestantInfo(contestant, alphSortedCont);

    sortContestantsAgeAscending(alphSortedCont);

    printAllContestants(alphSortedCont);
}

void sortContestantsName(Contestants contestant[]){
    //LATER: if names are equal compare ages
    int validIndex = getNextUsedSlot(contestant, 0);
    int nextValidIndex = getNextUsedSlot(contestant, 1);

    bool slotsNeedProcessing = !(validIndex == -1) && !(nextValidIndex == -1);
    
    deBugInfo(endl << "SYSTEM: START validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl);
    for(int i = 0; i < MAXCONTESTANTS && slotsNeedProcessing; i++){

        bool lastIndex = validIndex == 0;
        //LATER: make this check case insensitive
        bool nowLargerNext = strcmp(contestant[validIndex].name, contestant[nextValidIndex].name) > 0;
        if(nowLargerNext){
            swapContestantPlaces(contestant, validIndex, nextValidIndex);
            if(lastIndex) {
                i = nextValidIndex;
            } else {
                i = i - 2;
            }
        } 
        deBugInfo("SYSTEM: lastIndex: " << lastIndex << " | " << "nowLargerNext: " << nowLargerNext << endl);

        validIndex = getNextUsedSlot(contestant, i);
        nextValidIndex = getNextUsedSlot(contestant, validIndex + 1);
        slotsNeedProcessing = !(validIndex == -1) && !(nextValidIndex == -1);
        deBugInfo("SYSTEM: validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl << endl);


        deBugInfo("validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl);
    }
}

void sortContestantsID(Contestants contestant[]){
    int validIndex = getNextUsedSlot(contestant, 0);
    int nextValidIndex = getNextUsedSlot(contestant, 1);

    bool slotsNeedProcessing = !(validIndex == -1) && !(nextValidIndex == -1);
    
    deBugInfo(endl << "SYSTEM: START validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl);
    for(int i = 0; i < MAXCONTESTANTS && slotsNeedProcessing; i++){

        bool lastIndex = validIndex == 0;
        //LATER: make this check case insensitive
        bool nowLargerNext = contestant[validIndex].ID > contestant[nextValidIndex].ID;
        if(nowLargerNext){
            swapContestantPlaces(contestant, validIndex, nextValidIndex);
            if(lastIndex) {
                i = nextValidIndex;
            } else {
                i = i - 2;
            }
        } 
        deBugInfo("SYSTEM: lastIndex: " << lastIndex << " | " << "nowLargerNext: " << nowLargerNext << endl);

        validIndex = getNextUsedSlot(contestant, i);
        nextValidIndex = getNextUsedSlot(contestant, validIndex + 1);
        slotsNeedProcessing = !(validIndex == -1) && !(nextValidIndex == -1);
        deBugInfo("SYSTEM: validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl << endl);


        deBugInfo("validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl);
    }
}

void sortContestantsPoints(Contestants contestant[]){
    int validIndex = getNextUsedSlot(contestant, 0);
    int nextValidIndex = getNextUsedSlot(contestant, 1);

    bool slotsNeedProcessing = !(validIndex == -1) && !(nextValidIndex == -1);
    
    deBugInfo(endl << "SYSTEM: START validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl);
    for(int i = 0; i < MAXCONTESTANTS && slotsNeedProcessing; i++){

        bool lastIndex = validIndex == 0;
        //LATER: make this check case insensitive
        bool nowLargerNext = contestant[validIndex].points > contestant[nextValidIndex].points;
        if(nowLargerNext){
            swapContestantPlaces(contestant, validIndex, nextValidIndex);
            if(lastIndex) {
                i = nextValidIndex;
            } else {
                i = i - 2;
            }
        } 
        deBugInfo("SYSTEM: lastIndex: " << lastIndex << " | " << "nowLargerNext: " << nowLargerNext << endl);

        validIndex = getNextUsedSlot(contestant, i);
        nextValidIndex = getNextUsedSlot(contestant, validIndex + 1);
        slotsNeedProcessing = !(validIndex == -1) && !(nextValidIndex == -1);
        deBugInfo("SYSTEM: validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl << endl);


        deBugInfo("validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl);
    }
}




