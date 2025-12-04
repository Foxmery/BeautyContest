#include "sorting_menu.h"


void sortingMenu (Contestants contestant[], int& menuChoice){


    switch (menuChoice){
        case 0:
            //back... somehow
            break;
        case 1: // Sort by Age

            break;
        case 2: // Sort by Name

            break;
        case 3: // Sort contestants from youngest to oldest

            break;
        default:
            cout << "Invalid option!" << endl;
            deBugInfo("ERROR: expected from 0 - 3 got: " << menuChoice);
            break;
    }

        int lastIndex = 0;

    for(int i = 0;i < MAXCONTESTANTS; i++){

        int validIndex = getNextUsedSlot(contestant, i);//find the next index that is usable
        //if next contestant is not in use remove stop the program
        if (contestant[validIndex].isObjectUsed == 0){
            continue;
        }

        if(contestant[i].age > contestant[i+1].age){
            //swap contestant places
            Contestants placeHolder = contestant[i];
            contestant[i] = contestant[i+1];
            contestant[i+1] = placeHolder;

        } else if (i == 0){
            lastIndex++;
            i = lastIndex;

        } else {
            i = i - 2;//goes two spaces back but i++ will put it to one space back
        }
    }
}
