#include "sorting_menu.h"

void sortContestantsAgeAscending(Contestants contestant[]);
void swapContestantPlaces(Contestants contestant[], int FIndex, int SIndex);



void sortingMenu (Contestants contestant[], int& menuChoice){

    switch (menuChoice){
        case 0:
        {
            return;
        }
        case 1: // Sort by Age
            //TODO: Replace this with option 3
            break;
        case 2: // Sort by Name
        
            break;
        case 3: // Sort contestants from youngest to oldest
            sortContestantsAgeAscending(contestant);
            cout << "Contestants sorted successefully!\n";
            break;
        default:
            cout << "Invalid option!" << endl;
            deBugInfo("ERROR: expected from 0 - 3 got: " << menuChoice << endl);
            break;
    }

   
}

void sortContestantsAgeAscending(Contestants contestant[]){
    //NOW: FINISH THIS LOGIC
    int validIndex = getNextUsedSlot(contestant, 0);
    int nextValidIndex = getNextUsedSlot(contestant, 1);

    bool slotsNeedProcessing = !(validIndex == -1) && !(nextValidIndex == -1);

    for(int i = 0; i < MAXCONTESTANTS && slotsNeedProcessing; i++){

        bool lastIndex = contestant[validIndex].isObjectUsed == 0;

        bool nowLargerNext = contestant[validIndex].age > contestant[nextValidIndex].age;
        if(nowLargerNext){
            swapContestantPlaces(contestant, validIndex, nextValidIndex);
            if(lastIndex) {
                i = nextValidIndex;
            } else {
                i = i - 2;
            }
        } 

        validIndex = getNextUsedSlot(contestant, i);
        nextValidIndex = getNextUsedSlot(contestant, validIndex + 1);
        slotsNeedProcessing = !(validIndex == -1) && !(nextValidIndex == -1);


        deBugInfo("validIndex: " << validIndex << " | " << "nextValidIndex: " << nextValidIndex << " | " << "slotsNeedProcessing: " << slotsNeedProcessing << endl);
    }
}

void swapContestantPlaces(Contestants contestant[], int FIndex, int SIndex){
    deBugInfo("Swapping: " << FIndex << " and " << SIndex);
    Contestants placeHolder = contestant[FIndex];
    contestant[FIndex] = contestant[SIndex];
    contestant[SIndex] = placeHolder; 
}

// void sortContestantsAgeAscending(Contestants contestant[]){
//     int lastIndex = 0;

//     for(int i = 0; i < MAXCONTESTANTS; i++){

//         int validIndex = getNextUsedSlot(contestant, i);//find the next index that is usable
//         //if next contestant is not in use remove stop the program
//         if (contestant[validIndex].isObjectUsed == 0){
//             continue;
//         }

//         if(contestant[i].age > contestant[i+1].age){
//             //swap contestant places
//             Contestants placeHolder = contestant[i];
//             contestant[i] = contestant[i+1];
//             contestant[i+1] = placeHolder;

//         } else if (i == 0){
//             lastIndex++;
//             i = lastIndex;

//         } else {
//             i = i - 2;//goes two spaces back but i++ will put it to one space back
//         }
//     }
// }



