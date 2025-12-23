#include "exit_logic.h"

void askUserExit(){
    //EXPLANATION: annoying confirmation window like in any other professional program 
    string answer;
    clearConsole(CLEARCONSOLE);
    while (true) {
        cout << "Do you really want to exit? y/n" << endl;
        getline(cin, answer);

        clearConsole(CLEARCONSOLE);
        if (answer.compare("y") == 0) {
            cout << "Goodbye!";
            exit(0);
        } else if (answer.compare("n") == 0) {
            break; // continues the program
        } else {
            deBugInfo("ERROR: expected y or n" << endl);
        }
    }
}
