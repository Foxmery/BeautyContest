#include "sorting_menu.h"

/// @brief Sorts contestants by name descending without changing the original
/// @param contestant Contestants to be outputted
void outputSortedNoChangeAlphabetically(Contestants contestant[]);

/// @brief Sorts contestants by age ascending without changing the original
/// @param contestant Contestants to be outputted
void outputSortedNoChangeAge(Contestants contestant[]);



void sortingMenu (Contestants contestant[], int& menuChoice, bool& madeChanges){

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
            madeChanges = false;
            break;
        }
        case 2:
        {
            sortContestants(contestant, SORT_BY_NAME);
            madeChanges = false;
            break;
        }
        case 3:
        {
            sortContestants(contestant, SORT_BY_ID);
            madeChanges = false;
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




