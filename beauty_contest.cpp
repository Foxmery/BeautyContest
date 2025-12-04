#include "beauty_contest.h"

//LATER: possible to enter 3.1 to enter straight into a menu(maybe learn regex again)
//LATER: add way to add ascic pictures for contestants
//LATER: Remove feature that moves and packs all of the contestants to the start of the array, removing non existant contestant outputs error
//LATER: Ability to move around the menu with arrows

int main() {
    clearConsole(CLEARCONSOLE);
    srand(time(0)); //"True randomness"

    int leftSpaces = MAXCONTESTANTS;
    bool freeSpaces[MAXCONTESTANTS];
    int IDcounter = 1; //keep track of what is the last id added

    Contestants contestant[MAXCONTESTANTS];

    int menuChoice;

    do {
        mainMenuText();
        menuChoice = cinCheckInt("Type a number to chose your action: ");
                
        switch (menuChoice) {

            case 0: //Exit program 
                askUserExit();
                break;

            case 1: //Adding of contestant 
            {
                addingContestantsMenuText();
                menuChoice = cinCheckInt("Type a number to chose your action: ");

                additionOfContestantsMenu(contestant, leftSpaces, IDcounter, menuChoice);
                break;
            }
               
            case 2: //Show all contestants
            {   
                clearConsole(CLEARCONSOLE);
                
                printAllContestants(contestant);

                break;
            }
               

            case 3://Search
            {   
                searchMenuText();
                menuChoice = cinCheckInt("Type a number to chose your action: ");
                cout << endl;

                searchShowContestantsMenu(contestant, menuChoice);
                
                break;
            }
            

            case 4: //Sorting
            {
                sortMenuText();
                menuChoice = cinCheckInt("Type a number to chose your action: ");
                cout << endl;

                sortingMenu(contestant, menuChoice);

                break;
            }
                

            case 5:
            {
                //TODO: Make submenu to chose 

                break;
            }

            case 6:
            {
                //TODO: Make submenu to chose 

                break;
            }

            default:
            {   
                deBugInfo("ERROR: Expectednumber from 0 to 6 got: "<< menuChoice << endl);
                cout<< "Please enter a valid option!";
                break;
            }
                
        }
    } while (true);



}



