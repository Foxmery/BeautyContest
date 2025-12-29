#include "show_contestants.h"

void showContestantsMenu(Contestants contestant[], Contestants winners[], Contestants category14_16[], Contestants category17_19[], Contestants category20_22[], Contestants category23_25[], int menuChoice, bool winnersDecided, bool madeCategories){    

    switch(menuChoice){
        case 0:
        {
            clearConsole();
            return;
            break;
        }
        case 1:
        {
            clearConsole();
            printAllContestantsFormatted(contestant, "ALL CONTESTANTS");
            break;
        }
        case 2:
        {   
            clearConsole();
            if (!madeCategories){
                cout << "Winners have not been decided yet!\n";
                break;
            }    
            printAllContestantsFormatted(winners, "WINNERS");
            break;
        }
        case 3:
        {
            clearConsole();
            if (!winnersDecided){
                cout << "Categories have not been made yet!\n";
                break;
            }  
            printAllContestantsFormatted(category14_16, "Category 14/16 years");

            printAllContestantsFormatted(category17_19, "Category 17/19 years");

            printAllContestantsFormatted(category20_22, "Category 20/22 years");

            printAllContestantsFormatted(category23_25, "Category 23/25 years");
            break;

        }        
        default:
        {
            clearConsole();
            cout << "Invalid option!" << endl;
            deBugInfo("ERROR: expected from 0 - 3 got: " << menuChoice);
            break;
        }
    }

}