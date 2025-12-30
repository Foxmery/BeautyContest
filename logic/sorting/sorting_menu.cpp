#include "sorting_menu.h"


void sortContestantsID(Contestants contestant[]);
void sortContestantsName(Contestants contestant[]);
void sortContestantsAgeAscending(Contestants contestant[]);
void outputSortedNoChangeAlphabetically(Contestants contestant[]);
void outputSortedNoChangeAge(Contestants contestant[]);



void sortingMenu (Contestants contestant[], int& menuChoice, bool& savedChanages){

    clearConsole(CLEARCONSOLE);

    switch (menuChoice){
        case 0:
        {
            return;
            break;
        }
        case 1:
        {
            sortContestants(contestant,SORT_BY_AGE_ASC);
            cout << "Contestants sorted successfully!\n";
            savedChanages = false;
            break;
        }
        case 2:
        {
            sortContestants(contestant, SORT_BY_NAME);
            savedChanages = false;
            break;
        }
        case 3:
        {
            sortContestants(contestant, SORT_BY_ID);
            savedChanages = false;
            break;
        }
        case 4:
        {
            outputSortedNoChangeAge(contestant);
            break;
        }
        case 5: 
        {
            outputSortedNoChangeAlphabetically(contestant);
            break;
        }
        default:
        {
            
            cout << "Invalid option!" << endl;
            deBugInfo("ERROR: expected from 0 - 5 got: " << menuChoice);
            break;
        }
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

    sortContestants(alphSortedCont, SORT_BY_NAME);

    printAllContestantsFormatted(alphSortedCont, "CONTESTANTS SORTED BY NAME");
}

void outputSortedNoChangeAge(Contestants contestant[]){
    Contestants alphSortedCont[MAXCONTESTANTS];
    dupeContestantInfo(contestant, alphSortedCont);

    sortContestants(alphSortedCont, SORT_BY_AGE_ASC);

    printAllContestantsFormatted(alphSortedCont,"CONTESTANTS SORTED BY AGE");
}

void sortContestantsName(Contestants contestant[]){
    int validIndex = getNextUsedSlot(contestant, 0);
    int nextValidIndex = getNextUsedSlot(contestant, 1);

    bool slotsNeedProcessing = !(validIndex == -1) && !(nextValidIndex == -1);
    
    deBugInfo(endl << "SYSTEM: START validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl);
    for(int i = 0; i < MAXCONTESTANTS && slotsNeedProcessing; i++){

        bool lastIndex = validIndex == 0;
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

// switch (menuChoice){
//         case 0:
//         {
//             clearConsole();
//             return;
//             break;
//         }
//         case 1:
//         {
//             sortContestants(contestant);
//             cout << "Contestants sorted successfully!\n";
//             savedChanages = false;
//             break;
//         }
//         case 2:
//         {
//             sortContestantsName(contestant);
//             savedChanages = false;
//             break;
//         }
//         case 3:
//         {
//             sortContestantsID(contestant);
//             savedChanages = false;
//             break;
//         }
//         case 4:
//         {
//             outputSortedNoChangeAge(contestant);
//             break;
//         }
//         case 5: 
//         {
//             outputSortedNoChangeAlphabetically(contestant);
//             break;
//         }
//         default:
//         {
//             clearConsole();
//             cout << "Invalid option!" << endl;
//             deBugInfo("ERROR: expected from 0 - 5 got: " << menuChoice);
//             break;
//         }
//     }




