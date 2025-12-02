#include "block_mangment.h"

void linePrinter(string message, int width, char filler = ' ');

//TODO: Implement the function in the menus
void mainMenuText() {
    cout << endl;
    
    linePrinter("BEAUTY CONTEST", SCREENWIDTH, '-');
    cout <<
        //"\n\n-------------BEAUTY CONTEST-------------\n"
        "1. Add new contestant\n"
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

void searchMenuText(){
    clearConsole(CLEARCONSOLE);
    cout << endl;

    linePrinter("SEARCH", SCREENWIDTH, '-');
    cout <<
        //"\n\n-------------SEARCH-------------\n"
        "    1. Lowest age \n"
        "    2. Name\n"
        "    0. Back\n"
        << endl;
}

void fileMenuText(){
    clearConsole(CLEARCONSOLE);
    cout << endl;

    linePrinter("FILE", SCREENWIDTH, '-');
    cout <<
        //"\n\n-------------FILE-------------\n"
        "    1. Export\n"
        "    2. Import\n"
        "    0. Back\n"
        << endl;
}

void addingContestantsMenu(){        
    clearConsole(CLEARCONSOLE);
    cout << endl;

    linePrinter("Add new contestant",SCREENWIDTH, '-');
    cout <<
        //"\n\n-------------Add new contestant-------------\n"
        "    1. Manual adding\n"
        "    2. Random values\n"
        "    0. Back\n"
        << endl;
}

void linePrinter(string message, int width, char filler){   
    //EXPLANATION: Makes a more visible line with message in center and filler around it 
    
    int sizeOfMessage = message.size();//Check
    int fillerAroundMessage = (width - sizeOfMessage) / 2;
    
    bool isMessageEven = sizeOfMessage % 2 == 0;//Check 
    bool isWidthEven = width % 2 == 0;//Check
    bool extraFillerAtEnd = isMessageEven ^ isWidthEven;
 
    
    //at least one filler if message is too large
    if(fillerAroundMessage < 1)
    {
    //TODO: deBug("WARNING: Message is too large with " << fillerAroundMessage << endl;)
    fillerAroundMessage = 1;
    extraFillerAtEnd = false;
    }
    
    
    //fillers at start
    for(int i = 0; i < fillerAroundMessage; i++){
        cout << filler;
    }
 
    cout << message;
    
    //fillers at end
    for(int i = 0; i < fillerAroundMessage + extraFillerAtEnd/* can I do that? */; i++){
        cout << filler;
    }
    cout << endl;
}