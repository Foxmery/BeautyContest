#include "show_contestants.h"

void showContestants(Contestants contestant[]){    
    titlePrinter("All contestants",SCREENWIDTH, '-');

    printAllContestants(contestant);
    
    titlePrinter("", SCREENWIDTH, '-');
    cout << endl;
}