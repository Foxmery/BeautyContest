/// @file contestans_sorters.cpp
/// @brief Implementation of sorting algorithms (Bubble Sort) for contestants.

#include "contestans_sorters.h"

void sortContestants(Contestants contestant[], SortMode mode) {
    bool swapped = true;

    while (swapped) {
        swapped = false;
        
        int validIndex = getNextUsedSlot(contestant);

        while (validIndex != -1) {
            
            int nextValidIndex = getNextUsedSlot(contestant, validIndex + 1);

            if (nextValidIndex == -1) {
                break;
            }

            bool shouldSwap = false;

            switch (mode) {
                case SORT_BY_ID:
                    shouldSwap = contestant[validIndex].ID > contestant[nextValidIndex].ID;
                    break;
                case SORT_BY_NAME:
                    shouldSwap = strcmp(contestant[validIndex].name, contestant[nextValidIndex].name) > 0;
                    break;
                case SORT_BY_AGE_ASC:
                    shouldSwap = contestant[validIndex].age > contestant[nextValidIndex].age;
                    break;
                case SORT_BY_POINTS_DESC:
                    shouldSwap = contestant[validIndex].points < contestant[nextValidIndex].points;
                    break;
                case SORT_BY_POINTS_ASC:
                    shouldSwap = contestant[validIndex].points > contestant[nextValidIndex].points;
                    break;
            }

            if (shouldSwap) {
                swapContestantPlaces(contestant, validIndex, nextValidIndex);
                swapped = true;
            }

            validIndex = nextValidIndex;
        }
    }
    
    deBugInfo("SYSTEM: Sorting complete." << endl);
}
