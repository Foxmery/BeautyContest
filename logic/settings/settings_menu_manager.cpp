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
                DEBUGMODE = !DEBUGMODE;

                if(DEBUGMODE){
                    cout << "DebugMode on!\n";
                } else {
                    cout << "DebugMode off!\n";  
                }

                break;
            }
            case 2:
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
            case 3:
            {
                clearConsole();
                AUTOSAVE = !AUTOSAVE;   

                if(AUTOSAVE){
                    cout << "Auto save on!\n";
                } else {
                    cout << "Auto save off!\n";  
                }

                break;
                clearConsole();
            }
            case 4:
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