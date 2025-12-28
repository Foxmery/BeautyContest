#include "contestans_sorters.h"








void sortContestants(Contestants contestant[], SortMode mode){

    int validIndex = getNextUsedSlot(contestant, 0);
    int nextValidIndex = getNextUsedSlot(contestant, 1);



    bool slotsNeedProcessing = !(validIndex == -1) && !(nextValidIndex == -1);
    
    
    deBugInfo(endl << "SYSTEM: START validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl);
    //LATER: for(int i = getNextUsedSlot(contestant, 0); i != -1; i = getNextUsedSlot(contestant, i + 1))
    for(int i = 0; i < MAXCONTESTANTS && slotsNeedProcessing; i++){

        bool shouldSwap = false;
        switch (mode) {
            case SORT_BY_ID:
                shouldSwap = contestant[validIndex].ID > contestant[nextValidIndex].ID;
                break;
            case SORT_BY_NAME:
                shouldSwap = strcmp(contestant[validIndex].name, contestant[nextValidIndex].name) > 0;
                break;
            case SORT_BY_AGE:
                shouldSwap = contestant[validIndex].age > contestant[nextValidIndex].age;
                break;
            case SORT_BY_POINTS_DESC:
                shouldSwap = contestant[validIndex].points < contestant[nextValidIndex].points; 
                break;
            case SORT_BY_POINTS_ASC:
                shouldSwap = contestant[validIndex].points > contestant[nextValidIndex].points;
                break;
        }

        bool lastIndex = validIndex == 0;
        if(shouldSwap){
            swapContestantPlaces(contestant, validIndex, nextValidIndex);
            if(lastIndex) {
                i = nextValidIndex;
            } else {
                i = i - 2;
            }
        } 
        deBugInfo("SYSTEM: lastIndex: " << lastIndex << " | " << "shouldSwap: " << shouldSwap << endl);

        validIndex = getNextUsedSlot(contestant, i);
        nextValidIndex = getNextUsedSlot(contestant, validIndex + 1);
        slotsNeedProcessing = !(validIndex == -1) && !(nextValidIndex == -1);
        deBugInfo("SYSTEM: validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl << endl);


        deBugInfo("validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl);
    }
}

// void sortContestantsName(Contestants contestant[]){
//     //LATER: if names are equal compare ages
//     int validIndex = getNextUsedSlot(contestant, 0);
//     int nextValidIndex = getNextUsedSlot(contestant, 1);

//     bool slotsNeedProcessing = !(validIndex == -1) && !(nextValidIndex == -1);
    
//     deBugInfo(endl << "SYSTEM: START validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl);
//     for(int i = 0; i < MAXCONTESTANTS && slotsNeedProcessing; i++){

//         bool lastIndex = validIndex == 0;
//         //LATER: make this check case insensitive
//         bool nowLargerNext = strcmp(contestant[validIndex].name, contestant[nextValidIndex].name) > 0;
//         if(nowLargerNext){
//             swapContestantPlaces(contestant, validIndex, nextValidIndex);
//             if(lastIndex) {
//                 i = nextValidIndex;
//             } else {
//                 i = i - 2;
//             }
//         } 
//         deBugInfo("SYSTEM: lastIndex: " << lastIndex << " | " << "nowLargerNext: " << nowLargerNext << endl);

//         validIndex = getNextUsedSlot(contestant, i);
//         nextValidIndex = getNextUsedSlot(contestant, validIndex + 1);
//         slotsNeedProcessing = !(validIndex == -1) && !(nextValidIndex == -1);
//         deBugInfo("SYSTEM: validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl << endl);


//         deBugInfo("validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl);
//     }
// }