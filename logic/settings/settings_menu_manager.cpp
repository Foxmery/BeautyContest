#include "settings_menu_manager.h"

void settingsMenu (int menuChoice){

    while (true){

        switch (menuChoice){
            case 0:
            {
                clearConsole();
                return;
                break;
            }
            case 1:
            {
                clearConsole();   
                break;
            }
            case 2:
            {
                clearConsole();
                break;
            }
            case 3:
            {
                clearConsole();
                DEBUGMODE = !DEBUGMODE;

                if(DEBUGMODE){
                    cout << "DebugMode on!\n";
                } else {
                    cout << "DebugMode off!\n";  
                }

                break;
            }
            case 4:
            {
                clearConsole();
                CLEARCONSOLE = !CLEARCONSOLE;   

                if(CLEARCONSOLE){
                    cout << "Clear console on!\n";
                } else {
                    cout << "Clear console off!\n";  
                }

                break;
            }
            case 5:
            {
                clearConsole();
                AUTOSAVESECONDS = cinCheckInt("Auto save on how may seconds (type 0 to turn off): ");

                clearConsole();
                cout << "Auto save set on every " << AUTOSAVESECONDS << "s" << endl;
                break;
            }
            case 6:
            {
                clearConsole();
                AUTOCATEGORIZE = !AUTOCATEGORIZE;  

                if(AUTOCATEGORIZE){
                    cout << "Auto categorize on!\n";
                } else {
                    cout << "Auto categorize off!\n";  
                }

                break;
            } 
            default:
            {
                clearConsole();
                cout << "Invalid option!" << endl;
                deBugInfo("ERROR: expected from 0 - 6 got: " << menuChoice);
                break;
            }
        }
        settingsMenuText();
        menuChoice = cinCheckInt("Type a number to chose your action: ");
    }

}