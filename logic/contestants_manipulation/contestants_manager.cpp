#include "contestants_manager.h"


void swapContestantPlaces(Contestants contestant[], int FIndex, int SIndex){
    deBugInfo("SYSTEM: Swapping indexes " << FIndex << " and " << SIndex << endl);
    Contestants placeHolder = contestant[FIndex];
    contestant[FIndex] = contestant[SIndex];
    contestant[SIndex] = placeHolder; 
}

void dupeContestantInfo (Contestants from[], Contestants to[]){
    for(int i = 0; i < MAXCONTESTANTS; i++){
        to[i] = from[i];
    }
}

void resetContestants (Contestants contestant[]){
    for(int i = getNextUsedSlot(contestant, 0); i != -1; i = getNextUsedSlot(contestant, i + 1)){
        contestant[i].isObjectUsed = false;
        deBugInfo("SYSTEM: Rested: " << contestant[i].name << endl);
    }
}