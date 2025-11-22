#include "exit_logic.h"

void askUserExit(){
    while (true) {
        clearConsole(CLEARCONSOLE);
        cout << "Do you really want to exit? y/n" << endl;

        string answer;
        getline(cin, answer);

        if (answer.compare("y") == 0) {
            cout << "Goodbye!";
            exit(0);
        }
        else if (answer.compare("n") == 0) {
            clearConsole(CLEARCONSOLE);
            break;
        }
        else {
            deBugInfo("ERROR: expected y or n");
        }
    }
}
