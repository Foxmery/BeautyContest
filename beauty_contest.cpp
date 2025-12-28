#include "beauty_contest.h"

//LATER: asscii pciture of beauty contest before entering main menu
//LATER: possible to enter 3.1 to enter straight into a menu(maybe learn regex again)
//LATER: add way to add ascic pictures for contestants
//LATER: Remove feature that moves and packs all of the contestants to the start of the array, removing non existant contestant outputs error
//LATER: Ability to move around the menu with arrows
//LATER: Message for autosave every 30 seconds 
//LATER: Settings menu
//LATER: Settings preferences as files


int main() {
    clearConsole(CLEARCONSOLE);
    srand(time(0)); 

    int leftSpaces = MAXCONTESTANTS;
    bool freeSpaces[MAXCONTESTANTS];
    int IDcounter = 1; 

    //LATER: for showContestants
    bool winnersDecided = false;

    //LATER: for showContestants
    bool madeCategories = false;



    Contestants contestant[MAXCONTESTANTS];

    Contestants category14_16[MAXCONTESTANTS];
    Contestants category17_19[MAXCONTESTANTS];
    Contestants category20_22[MAXCONTESTANTS];
    Contestants category23_25[MAXCONTESTANTS];

    Contestants winners[MAXCONTESTANTS];

    int menuChoice;

    do {
        mainMenuText(winnersDecided,  madeCategories);
        menuChoice = cinCheckInt("Type a number to chose your action: ");
                
        switch (menuChoice) {

            case 0:
            {
                clearConsole(CLEARCONSOLE);

                //LATER: You have unsaved changes! Do you want to save them? y/n
            
                askUserExit();
                break;
            }
            case 1: 
            {
                clearConsole(CLEARCONSOLE);

                addingContestantsMenuText();
                menuChoice = cinCheckInt("Type a number to chose your action: ");

                additionOfContestantsMenu(contestant, leftSpaces, IDcounter, menuChoice);

                if(autoCategorize){
                    categorizeContestantsByAge(contestant, category14_16,  category17_19, category20_22, category23_25);
                    madeCategories = true;
                } else {
                    madeCategories = false;
                }
                
                winnersDecided = false;
                break;
            }
               
            case 2:
            {   
                //LATER: show submenu and text in main menu for categories only if they were made ex: bool madeCategories; false every time new contestant is added, true after initilised command
                clearConsole(CLEARCONSOLE);
                
                showContestants(contestant);

                break;
            }
               

            case 3:
            {   
                clearConsole(CLEARCONSOLE);

                searchMenuText();
                menuChoice = cinCheckInt("Type a number to chose your action: ");
                cout << endl;

                searchShowContestantsMenu(contestant, menuChoice);
                
                break;
            }
            

            case 4: 
            {
                clearConsole(CLEARCONSOLE);

                sortMenuText();
                menuChoice = cinCheckInt("Type a number to chose your action: ");
                cout << endl;

                sortingMenu(contestant, menuChoice);

                break;
            }
                

            case 5:
            {
                clearConsole(CLEARCONSOLE);

                categorizeContestantsByAge(contestant, category14_16,  category17_19, category20_22, category23_25);
                madeCategories = true;

                break;
            }

            case 6:
            {
                winnerDecider(contestant, winners);
                winnersDecided = true;
                break;
            }
            case 7:
            {
                //TODO: Make submenu to chose 

                break;
            }

            case 8: //SETTINGS
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



