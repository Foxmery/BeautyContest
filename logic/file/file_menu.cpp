#include "file_menu.h"

void fileManagerMenu(Contestants contestant[], int& menuChoice, bool& savedChanages, bool& madeCategories, bool& winnersDecided, int& IDcounter, int& leftSpaces){

    clearConsole(CLEARCONSOLE);

    switch(menuChoice){
        case 0:
        {
            return;
            break;
        }
        case 1:
        {
            if (saveToFile(contestant,"zfiles/contestants.dat")){
                cout << "Data saved successfully!" << endl;

                savedChanages = true;
            } 

            break;
        }
        case 2:
        {
            if (loadFromFile(contestant, "zfiles/contestants.dat")){
                cout << "Data loaded successfully!" << endl;

                IDcounter = biggestContestantID(contestant) + 1;

                leftSpaces = countOfContestants(contestant);
                madeCategories = false;
                winnersDecided = false;
                savedChanages = true;
            }

            break;
        }
        case 3:
        {
            
            if (removeFileData("zfiles/auto_save.dat")){
                cout << "Scraped auto_save.dat successfully!" << endl;

                savedChanages = false;
            }

            break;
        }
        case 4:
        {
            if (removeFileData("zfiles/contestants.dat")){
                cout << "Scraped contestants.dat successfully!" << endl;

                savedChanages = false;
            }

            break;
        }
        case 5:
        {
            resetContestants(contestant);
            cout << "Deleted all contestants!" << endl;

            leftSpaces = MAXCONTESTANTS;
            madeCategories = false;
            winnersDecided = false;
            savedChanages = false;

            break;
        }
        case 6:
        {
            if (removeFileData("zfiles/contestants.dat")){
                cout << "Scraped contestants.dat successfully!" << endl;
            }

            if (removeFileData("zfiles/auto_save.dat")){
                cout << "Scraped auto_save.dat successfully!" << endl;
            }

            resetContestants(contestant);
            cout << "Deleted all contestants!" << endl;

            leftSpaces = MAXCONTESTANTS;
            madeCategories = false;
            winnersDecided = false;
            savedChanages = false;
            IDcounter = 1;

            break;
        }
        default:
        {
            clearConsole(CLEARCONSOLE);
            cout << "Invalid option!" << endl;
            deBugInfo("ERROR: expected from 0 - 4 got: " << menuChoice);
            
            break;
        }
    }


}