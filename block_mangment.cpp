#include "block_mangment.h"

void titlePrinter(string title, int width, char filler = ' ');



void mainMenuText() {
    cout << endl;
    
    titlePrinter("BEAUTY CONTEST", SCREENWIDTH, '-');
    cout <<
        "1. Add new contestant\n"
        "    1.1 Manual adding\n"
        "    1.2 Random values\n"
        "2. Show all contestants\n"
        "3. Search\n"
        "    3.1 The lowest age\n"
        "    3.2 Age\n"
        "    3.3 Name\n"
        "    3.4 Gender\n"
        //LATER: 3.5 When winner got decided a option unlocks to show the winners. If not decided yet - notify user. When new contestants are added the option should be locked again.
        "4. Sort\n"
        "    4.1 Sort by Age ascending\n"
        "    4.2 Sort by Name\n"
        "    4.3 Output sorted without change alphabetically\n"
        "    4.4 Output sorted without change by age\n"
        "    4.5 Sort by ID\n"
        "5. -Categorize contestants in age groups\n"
        "6. -Decide winners\n"
        "    6.1 Scores between 0.54 - 0.62\n"
        "    6.2 Output Scores > 0.63 ascending, then < 0.53\n"
        "7. -File\n"
        "    7.1 Export\n"
        "    7.2 Import\n"
        "8. Debugmode = " << (DEBUGMODE ? "true" : "false") << "\n"
        "0. Exit"
        << endl;
}

void searchMenuText(){
    clearConsole(CLEARCONSOLE);
    cout << endl;

    titlePrinter("SEARCH", SCREENWIDTH, '-');
    cout <<
        //"\n\n-------------SEARCH-------------\n"
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

    titlePrinter("SORT", SCREENWIDTH, '-');
    cout <<
        //"\n\n-------------SORT-------------\n"
        "    1. Sort by Age ascending\n"
        "    2. Sort by Name\n"
        "    3. Output sorted without change alphabetically\n"
        "    4. Output sorted without change by age\n"
        "    5. Sort by ID\n"
        "    0. Back\n"
        << endl;
}

void winnersMenuText(){
    clearConsole(CLEARCONSOLE);
    cout << endl;

    titlePrinter("Decide winners", SCREENWIDTH, '-');
    cout <<
        //"\n\n-------------Decide winners-------------\n"
        "    1. Scores between 0.54 - 0.62\n"
        "    2. Output Scores > 0.63 ascending, then < 0.53\n"
        "    0. Back\n"
        << endl;
}

void fileMenuText(){
    clearConsole(CLEARCONSOLE);
    cout << endl;

    titlePrinter("FILE", SCREENWIDTH, '-');
    cout <<
        //"\n\n-------------FILE-------------\n"
        "    1. Export\n"
        "    2. Import\n"
        "    0. Back\n"
        << endl;
}

void addingContestantsMenuText(){        
    clearConsole(CLEARCONSOLE);
    cout << endl;

    titlePrinter("Add new contestant",SCREENWIDTH, '-');
    cout <<
        //"\n\n-------------Add new contestant-------------\n"
        "    1. Manual adding\n"
        "    2. Random values\n"
        "    0. Back\n"
        << endl;
}

void titlePrinter(string title, int width, char filler){   

    
    int sizeOfMessage = title.size();
    int fillerAroundMessage = (width - sizeOfMessage) / 2;
    
    bool isTitleEven = sizeOfMessage % 2 == 0;//Check 
    bool isWidthEven = width % 2 == 0;//Check

    
    bool extraFillerAtEndNeeded = isTitleEven ^ isWidthEven;
 
    
    //at least one filler if title is too large
    if(fillerAroundMessage < 1)
    {
    deBugInfo("WARNING: Message is too large with " << fillerAroundMessage << endl);
    fillerAroundMessage = 1;
    extraFillerAtEndNeeded = false;
    }
    
    
    //fillers at start
    for(int i = 0; i < fillerAroundMessage; i++){
        cout << filler;
    }

    // print out Title
    cout << title;
    
    //fillers at end
    for(int i = 0; i < fillerAroundMessage + extraFillerAtEndNeeded; i++){
        cout << filler;
    }
    cout << endl;
}

void mainMenuTextBASEEDITION() {
    cout << endl;
    
    titlePrinter("BEAUTY CONTEST", SCREENWIDTH, '-');
    cout <<
        //"\n\n-------------BEAUTY CONTEST-------------\n"
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

    titlePrinter("SEARCH", SCREENWIDTH, '-');
    cout <<
        //"\n\n-------------SEARCH-------------\n"
        "    1. Lowest age \n"
        "    2. Name\n"
        "    0. Back\n"
        << endl;
}