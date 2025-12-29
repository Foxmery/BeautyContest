#include "file_menu.h"

void fileManagerMenu(Contestants contestant[], int menuChoice){

    clearConsole();

    switch(menuChoice){
        case 0:
        {
            clearConsole();
            return;
            break;
        }
        case 1:
        {
            saveToFile(contestant);
            break;
        }
        case 2:
        {
            loadFromFile(contestant);
            break;
        }
        default:
        {
            clearConsole();
            cout << "Invalid option!" << endl;
            deBugInfo("ERROR: expected from 0 - 2 got: " << menuChoice);
            break;
        }
    }


}