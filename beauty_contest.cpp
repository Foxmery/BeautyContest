#include "beauty_contest.h"

//LATER: possible to enter 3.1 to enter straight into a menu(maybe learn regex again)
//LATER: add way to add ascic pictures for contestants
//LATER: Remove feature that moves and packs all of the contestants to the start of the array, removing non existant contestant outputs error
//LATER: Ability to move around the menu with arrows

int main() {
    clearConsole(CLEARCONSOLE);
    srand(time(0)); 

    int leftSpaces = MAXCONTESTANTS;
    bool freeSpaces[MAXCONTESTANTS];
    int IDcounter = 1; 

    Contestants contestant[MAXCONTESTANTS];

    int menuChoice;

    do {
        mainMenuText();
        menuChoice = cinCheckInt("Type a number to chose your action: ");
                
        switch (menuChoice) {

            case 0:
            {
                askUserExit();
                break;
            }
            case 1: 
            {
                addingContestantsMenuText();
                menuChoice = cinCheckInt("Type a number to chose your action: ");

                additionOfContestantsMenu(contestant, leftSpaces, IDcounter, menuChoice);
                break;
            }
               
            case 2:
            {   
                clearConsole(CLEARCONSOLE);
                
                showContestants(contestant);

                break;
            }
               

            case 3:
            {   
                searchMenuText();
                menuChoice = cinCheckInt("Type a number to chose your action: ");
                cout << endl;

                searchShowContestantsMenu(contestant, menuChoice);
                
                break;
            }
            

            case 4: 
            {
                sortMenuText();
                menuChoice = cinCheckInt("Type a number to chose your action: ");
                cout << endl;

                sortingMenu(contestant, menuChoice);

                break;
            }
                

            case 5:
            {
                                
                break;
            }

            case 6:
            {
                //TODO: Make submenu to chose 

                break;
            }
            case 7:
            {
                //TODO: Make submenu to chose 

                break;
            }

            case 8:
            {
                if(DEBUGMODE){
                    cout << "DebugMode off!\n";  
                } else {
                    cout << "DebugMode on!\n";
                }
                DEBUGMODE = !DEBUGMODE;
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



