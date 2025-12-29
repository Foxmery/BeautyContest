#include "exit_logic.h"


char cinCheckYN(string message);


bool askUserExit(Contestants contestant[], bool savedChanages){

    bool exiting = false;
    if (savedChanages){

        exiting = (cinCheckYN("Do you want to exit? yes / no") == 'y' ? true : false);
            
    } else {
        
        cout << "You have unsaved changes!" << endl;
        char answer = cinCheckYN("Do you want to save them? yes / no / Cancel");

        if (answer == 'y'){
            clearConsole(CLEARCONSOLE);
            if (saveToFile(contestant, "contestants.dat")){
                cout << "Data saved successfully!" << endl;
                exiting = true;
            } else {
                cout << "Couldn't save!" << endl;
                exiting = (cinCheckYN("Do you want to exit? yes / no") == 'y' ? true : false);
            }
        } else if(answer == 'n'){
            exiting = true;

        } else if(answer == 'c'){
            exiting = false;
        }
    }

    if (exiting){
        
        cout << "Goodbye!" << endl;
    }
    return exiting;
}


char cinCheckYN(string message){
    string input;
    char answer;

    do{
        cout << message << endl;
        getline(cin, input);
        answer = tolower(input[0]);

        if      (answer == 'y') { return 'y'; }
        else if (answer == 'n') { return 'n'; }
        else if (answer == 'c') { return 'c'; }
        else                    { cout << "Invalid input! Try Again!"; }

    } while (answer != '0');
    return 'c';
}

