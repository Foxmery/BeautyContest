/// @file winner_decsision_menu.cpp
/// @brief Logic for calculating and displaying the winners.

#include "winner_decsision_menu.h"

void winnerDecider (Contestants contestant[], Contestants winners[]){
    
    Contestants tooGoodContestants[MAXCONTESTANTS];
    Contestants tooBadContestants[MAXCONTESTANTS];
    Contestants outSiders[MAXCONTESTANTS]; 

    for(int i = getNextUsedSlot(contestant, 0); i != -1; i = getNextUsedSlot(contestant, i + 1)){

        double contPoints = contestant[i].points;
        deBugInfo("SYSTEM: Contestant with points: " << contPoints);
        if (contPoints >= 0.54 && contPoints <= 0.62){
            winners[getNextFreeSlot(winners)] = contestant[i];
            deBugInfo("SYSTEM: Putting contestant into winners: ");

        } else if(contPoints < 0.54){
            tooBadContestants[getNextFreeSlot(tooBadContestants)] = contestant[i];
            deBugInfo("SYSTEM: Putting contestant into tooBadContestants: ");

        } else if(contPoints > 0.62){
            tooGoodContestants[getNextFreeSlot(tooGoodContestants)] = contestant[i];
            deBugInfo("SYSTEM: Putting contestant into tooGoodContestants: " << endl);

        } else {
            outSiders[getNextFreeSlot(outSiders)] = contestant[i];
            deBugInfo("SYSTEM: Putting contestant into outSiders: ");


        }   
        printContestant(contestant, i); //DEBUG
        cout << endl;

    }

    clearConsole(CLEARCONSOLE);
    
    sortContestants(winners, SORT_BY_POINTS_DESC);
    sortContestants(tooBadContestants, SORT_BY_POINTS_ASC);
    sortContestants(tooGoodContestants, SORT_BY_POINTS_ASC);

    printAllContestantsFormatted(winners, "WINNERS");
    if(getNextUsedSlot(tooBadContestants)   != -1) printAllContestantsFormatted(tooBadContestants, "GIVE UP");
    if(getNextUsedSlot(tooGoodContestants)  != -1) printAllContestantsFormatted(tooGoodContestants, "THE REAL WINNERS");
    if(getNextUsedSlot(outSiders)           != -1) printAllContestantsFormatted(outSiders, "OUTSIDERS");

}