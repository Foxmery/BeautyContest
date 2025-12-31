/// @file block_mangment.cpp
/// @brief Implementation of text-based menu displays and title formatting.

#include "block_mangment.h"

void titlePrinter(string title, int width, char filler = ' ');


void mainMenuText(bool winnersDecided, bool madeCategories) {
    cout << endl;
    
    titlePrinter("BEAUTY CONTEST", TITLEWIDTH, '-');
    cout <<
        "1. Contestant\n"
        "    1.1 Manual adding\n"
        "    1.2 Random values\n"
        "    1.3 Remove contestant\n"
        << (winnersDecided || madeCategories ? "2. Show\n"                 : "2. Show all contestants\n")
        << (winnersDecided || madeCategories ? "    2.1 All contestants\n" : "")
        << (winnersDecided                   ? "    2.2 Winners\n"         : "")
        << (                  madeCategories ? "    2.3 Categories\n"      : "") <<
        "3. Search\n"
        "    3.1 The lowest age\n"
        "    3.2 Age\n"
        "    3.3 Name\n"
        "    3.4 Gender\n"
        "4. Sort\n"
        "    4.1 Sort by Age ascending\n"
        "    4.2 Sort by Name\n"
        "    4.3 Sort by ID\n"
        "    4.4 Output sorted without change by age\n"
        "    4.5 Output sorted without change alphabetically\n"
        "5. Categorize contestants in age groups\n"
        "6. Decide winners\n"
        "7. File\n"
        "    7.1 Export\n"
        "    7.2 Import\n"
        "    7.3 Reset...\n"
        "8. Settings...\n"
        "0. Exit"
        << endl;
}

void addingContestantsMenuText(){        
    clearConsole(CLEARCONSOLE);
    cout << endl;

    titlePrinter("CONTESTANT", TITLEWIDTH, '-');
    cout <<
        "    1. Manual adding\n"
        "    2. Random values\n"
        "    3. Remove contestant\n"
        "    0. Back\n"
        << endl;
}

void showContestantMenuText(bool winnersDecided, bool madeCategories){
    bool large = winnersDecided || madeCategories;
    if (large) titlePrinter("SHOW", TITLEWIDTH, '-');
    cout <<
           (large          ? "    1. All contestants\n" : "")
        << (winnersDecided ? "    2. Winners\n"         : "")
        << (madeCategories ? "    3. Categories\n"      : "")
        << (large          ? "    0. Back"              : "")
        << endl;
}

void searchMenuText(){
    clearConsole(CLEARCONSOLE);
    cout << endl;

    titlePrinter("SEARCH", TITLEWIDTH, '-');
    cout <<
        "    1. The lowest age\n"
        "    2. Age\n"
        "    3. Name\n"
        "    4. Gender\n"
        "    0. Back\n"
        << endl;
}


void sortMenuText(){
    clearConsole(CLEARCONSOLE);
    cout << endl;

    titlePrinter("SORT", TITLEWIDTH, '-');
    cout <<
        "    1. Sort by Age ascending\n"
        "    2. Sort by Name\n"
        "    3. Sort by ID\n"
        "    4. Output sorted without change by age\n"
        "    5. Output sorted without change alphabetically\n"
        "    0. Back\n"
        << endl;
}



void fileMenuText(){
    clearConsole(CLEARCONSOLE);
    cout << endl;

    titlePrinter("FILE", TITLEWIDTH, '-');
    cout <<
        "    1. Export\n"
        "    2. Import\n"
        "    3. Reset auto_save.dat\n"
        "    4. Reset contestants.dat\n"
        "    5. Reset Contestants struct\n"
        "    6. Reset EVERYTHING\n"
        "    0. Back\n"
        << endl;
}

void settingsMenuText(){

    titlePrinter("SETTINGS", TITLEWIDTH, '-');
    cout << 
        "   1. Debugmode = " << (DEBUGMODE ? "true" : "false") << "\n"
        "   2. Clear console = " << (CLEARCONSOLE ? "true" : "false") << "\n"
        "   3. Auto save = " << (AUTOSAVE ? "true" : "false") << "\n"
        "   4. Auto categorize = " << (AUTOCATEGORIZE ? "true" : "false") << "\n"
        "   0. Back\n"
        << endl;
}



void titlePrinter(string title, int width, char filler){   

    
    int sizeOfMessage = title.size();
    int fillerAroundMessage = (width - sizeOfMessage) / 2;
    
    bool isTitleEven = sizeOfMessage % 2 == 0;
    bool isWidthEven = width % 2 == 0;

    bool extraFillerAtEndNeeded = isTitleEven ^ isWidthEven;
 
    
    bool atLeastOneFiller = fillerAroundMessage < 1;
    if(atLeastOneFiller)
    {
    deBugInfo("WARNING: Message is too large with " << fillerAroundMessage << endl);
    fillerAroundMessage = 1;
    extraFillerAtEndNeeded = false;
    }
    
    
    //fillers at start
    for(int i = 0; i < fillerAroundMessage; i++){
        cout << filler;
    }

    cout << title;
    
    //fillers at end
    for(int i = 0; i < fillerAroundMessage + extraFillerAtEndNeeded; i++){
        cout << filler;
    }
    cout << endl;
}

//Outdated
void mainMenuTextBASEEDITION() {
    cout << endl;
    
    titlePrinter("BEAUTY CONTEST", TITLEWIDTH, '-');
    cout <<
        "1. Add new contestant\n"
        "    1.1 Manual adding\n"
        "    1.2 Random values\n"
        "2. Show all contestants\n"
        "3. Search\n"
        "    3.1 The lowest age\n"
        "    3.2 Name\n"
        "4. Sort contestants by youngest to oldest (No output)\n"
        "5. File\n"
        "    5.1 Export\n"
        "    5.2 Import\n"
        "0. Exit"
        << endl;
}

void searchMenuTextBASEEDITION(){
    clearConsole(CLEARCONSOLE);
    cout << endl;

    titlePrinter("SEARCH", TITLEWIDTH, '-');
    cout <<
        "    1. Lowest age \n"
        "    2. Name\n"
        "    0. Back\n"
        << endl;
}

void winnersMenuText(){
    clearConsole(CLEARCONSOLE);
    cout << endl;

    titlePrinter("Decide winners", TITLEWIDTH, '-');
    cout <<
        "    1. Scores between 0.54 - 0.62\n"
        "    2. Output Scores > 0.63 ascending, then < 0.53\n"
        "    0. Back\n"
        << endl;
}