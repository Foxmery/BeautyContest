#include "file_menu.h"

void fileManagerMenu(Contestants contestant[], int menuChoice){

    switch(menuChoice){
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
    }


}