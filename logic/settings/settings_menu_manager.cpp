/// @file settings_menu_manager.cpp
/// @brief Handles user interactions for changing program settings (Debug, AutoSave, etc.).

#include "settings_menu_manager.h"

void settingsMenu (int menuChoice){

    while (true){

        switch (menuChoice){
            case 0:
            {
                clearConsole(CLEARCONSOLE);
                
                return;
                break;
            }
            case 1:
            {
                clearConsole(CLEARCONSOLE);
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
                clearConsole(CLEARCONSOLE);
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
                clearConsole(CLEARCONSOLE);
                AUTOSAVE = !AUTOSAVE;   

                if(AUTOSAVE){
                    cout << "Auto save on!\n";
                } else {
                    cout << "Auto save off!\n";  
                }

                break;
                clearConsole(CLEARCONSOLE);
            }
            case 4:
            {
                clearConsole(CLEARCONSOLE);
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
                clearConsole(CLEARCONSOLE);
                cout << "Invalid option!" << endl;
                deBugInfo("ERROR: expected from 0 - 6 got: " << menuChoice);
                break;
            }
        }
        settingsMenuText();
        menuChoice = cinCheckInt("Type a number to chose your action: ");
    }

}