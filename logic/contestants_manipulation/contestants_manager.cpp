#include "contestants_manager.h"


void swapContestantPlaces(Contestants contestant[], int FIndex, int SIndex){
    deBugInfo("SYSTEM: Swaping indexes " << FIndex << " and " << SIndex << endl);
    Contestants placeHolder = contestant[FIndex];
    contestant[FIndex] = contestant[SIndex];
    contestant[SIndex] = placeHolder; 
}

void dupeContestantInfo (Contestants from[], Contestants to[]){
    for(int i = 0; i < MAXCONTESTANTS; i++){
        to[i] = from[i];
    }
}