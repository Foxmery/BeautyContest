#include "beauty_contest.h"

//TODO: Make settings in a struct





int main() {
    clearConsole(CLEARCONSOLE);
    srand(time(0)); 

    int leftSpaces = MAXCONTESTANTS;
    bool freeSpaces[MAXCONTESTANTS];
    int IDcounter = 1; 

    bool winnersDecided = false;
    bool madeCategories = false;
    bool savedChanages = true;

    Contestants contestant[MAXCONTESTANTS];
    if(loadFromFile(contestant, "zfiles/auto_save.dat")){
        cout << "Successfully loaded form auto_save.dat!" << endl;
    }
    IDcounter = biggestContestantID(contestant) + 1;
    

    Contestants category14_16[MAXCONTESTANTS];
    Contestants category17_19[MAXCONTESTANTS];
    Contestants category20_22[MAXCONTESTANTS];
    Contestants category23_25[MAXCONTESTANTS];

    Contestants winners[MAXCONTESTANTS];

    int menuChoice;

    
    bool running = true;
    do {

        if(AUTOSAVE && !savedChanages){
            if (saveToFile(contestant, "zfiles/auto_save.dat"))
                cout << "Changes were auto saved!" << endl;
        }

        mainMenuText(winnersDecided,  madeCategories);
        menuChoice = cinCheckInt("Type a number to chose your action: ");
                
        switch (menuChoice) {

            case 0:
            {
                clearConsole(CLEARCONSOLE);
            

                if (askUserExit(contestant, savedChanages)){
                    running = false;
                }


                break;
            }
            case 1: 
            {
                clearConsole(CLEARCONSOLE);



                int leftSpacesBefore = leftSpaces;
                int leftSpacesAfter;
                
                addingContestantsMenuText();
                menuChoice = cinCheckInt("Type a number to chose your action: ");
                cout << endl;


                additionOfContestantsMenu(contestant, leftSpaces, IDcounter, menuChoice);


                leftSpacesAfter = leftSpaces;
                bool contestantsWereChanged = leftSpacesBefore != leftSpacesAfter;
                if (contestantsWereChanged){

                    if(AUTOCATEGORIZE){
                        categorizeContestantsByAge(contestant, category14_16,  category17_19, category20_22, category23_25);
                        madeCategories = true;
                    } else {
                        madeCategories = false;
                    }
                    savedChanages = false;
                    winnersDecided = false;

                }
                break;
            }
               
            case 2:
            {   
                clearConsole(CLEARCONSOLE);

                bool showMore = madeCategories || winnersDecided;
                if (showMore){
                    showContestantMenuText(winnersDecided, madeCategories);
                    menuChoice = cinCheckInt("Type a number to chose your action: ");
                    cout << endl;
                }
                
                if (!showMore) menuChoice = 1;
                showContestantsMenu(contestant, winners, category14_16, category17_19, category20_22, category23_25, menuChoice, madeCategories, winnersDecided);

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


                bool changesWereMade = menuChoice == 1 || menuChoice == 2 || menuChoice == 3; 
                if(changesWereMade){
                    savedChanages = false;
                }

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
                clearConsole(CLEARCONSOLE);


                winnerDecider(contestant, winners);


                winnersDecided = true;
                break;
            }

            case 7:
            {
                clearConsole(CLEARCONSOLE);

                fileMenuText();
                menuChoice = cinCheckInt("Type a number to chose your action: ");
                cout << endl;


                fileManagerMenu(contestant, menuChoice, savedChanages, madeCategories, winnersDecided, IDcounter, leftSpaces);
                

                break;
            }

            case 8: 
            {   
                clearConsole(CLEARCONSOLE);

                settingsMenuText();
                menuChoice = cinCheckInt("Type a number to chose your action: ");
                cout << endl;


                settingsMenu(menuChoice);


                break;
            }

            default:
            {   
                deBugInfo("ERROR: Expectednumber from 0 to 6 got: "<< menuChoice << endl);
                cout<< "Please enter a valid option!";
                break;
            }
        }
    } while (running);
return 0;
}



