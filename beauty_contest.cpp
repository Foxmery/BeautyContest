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
                addingContestantsMenu();
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
            

            case 4: //Sort the contestants
            {

                int i = 0;
                int lastIndex = 0;

                do{
                    
                    //if next contestant is not in use remove stop the program
                    if (contestant[i+1].isObjectUsed == 0){
                        break;
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
                        i--;

                    }

                } while(i != MAXCONTESTANTS);

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



