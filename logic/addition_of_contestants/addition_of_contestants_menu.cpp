#include "addition_of_contestants_menu.h"

int GetValidContestantInputCount(int& leftSpaces);
void inputContestantData(int& leftSpaces, int& IDcounter, Contestants contestant[], bool random);
void printNamesOfAddedContestants(string savedNames[]);

/// @brief Manages submenu for contestant addition and removal
/// @param contestant Contestants you want to change
/// @param leftSpaces How many space are left in the contestant struct
/// @param IDcounter From what id to start adding 
/// @param menuChoice What the user choose to do 
void additionOfContestantsMenu(Contestants contestant[], int& leftSpaces, int& IDcounter, int& menuChoice){
    clearConsole(CLEARCONSOLE);
    

    switch (menuChoice){
        case 0:
        {
            clearConsole();
            return;
            break;
        }
        case 1:
        {
            inputContestantData(leftSpaces, IDcounter, contestant, false);
            break;
        }
        case 2:
        {
            inputContestantData(leftSpaces, IDcounter, contestant, true);
            break;
        }
        case 3:
        {
            printAllContestantsFormatted(contestant, "ALL CONTESTANTS");
            cout << endl;
            
            int idToRemove = 0;
            do{
                if (idToRemove != 0) {
                    deleteContestantsByID(contestant, idToRemove);
                    leftSpaces++;
                }
                idToRemove = cinCheckInt("Enter ID of contestants to remove or 0 to cancel: ");
            } while(idToRemove != 0);

            clearConsole(CLEARCONSOLE);
            break;
        }
        default:
        {
            clearConsole();
            cout << "Invalid option!" << endl;
            deBugInfo("ERROR: expected from 0 - 3 got: " << menuChoice);
            break;
        }
            
    }
}


/// @brief Gets user to type a value within the left spaces for contestants
/// @param leftSpaces left space for use in the Contestants struct
/// @return a valid number of contestants to add to the struct
int GetValidContestantInputCount(int& leftSpaces){

    bool isValid = false;
    do{
        cout << "Spaces left: " << leftSpaces << endl;

        int contestantsToAdd = cinCheckInt("How many contestants do you want to add: ");

        isValid = contestantsToAdd > leftSpaces;
        if (isValid) {
            clearConsole(CLEARCONSOLE);
            cout << "Too many contestants!" << endl << endl;
        } else {
            return contestantsToAdd;
        }
    } while(isValid);
    return 0;
}

/// @brief Manager for random and single contestant initialisation
/// @param leftSpaces Left free spaces in COntestants struct
/// @param IDcounter The last ishued ID
/// @param contestant Array of all contestants
/// @param random If you want manual addition of contestants or random values
void inputContestantData(int& leftSpaces, int& IDcounter, Contestants contestant[], bool random){

    if (leftSpaces <= 0){
        cout << "No spaces left.\n Remove contestants to add more!\n";
        return;
    }

    int contestantsToAdd = GetValidContestantInputCount(leftSpaces);
    leftSpaces -= contestantsToAdd;

    string savedNames[MAXCONTESTANTS];

    
    deBugInfo("SYSTEM: size savedNames: " << size(savedNames) << endl);

    for (int i = 0; contestantsToAdd > i; i++) {

        int validIndex = getNextFreeSlot(contestant);
        
        int newID = IDcounter++;
        if (random){
            randomContestantGenerator(contestant[validIndex], newID);
        } else {
            readSingleContestant(contestant[validIndex], newID);
        }
        
        savedNames[i] = contestant[validIndex].name;
    }

    if(savedNames[0] == ""){
        clearConsole(CLEARCONSOLE);
        cout << "No contestants added." << endl;
        deBugInfo("SYSTEM: contestantsToAdd: " << contestantsToAdd);
    } else {
        printNamesOfAddedContestants(savedNames);
    }
}

/// @brief Output all the saved names to the user
/// @param savedNames string array of all saved names
void printNamesOfAddedContestants(string savedNames[]){

    clearConsole(CLEARCONSOLE);

    deBugStringArray(savedNames, MAXCONTESTANTS);
    cout << "Contestant/s ";

    bool foundEmptyIndex = false;

    for(int i = 0; !foundEmptyIndex && MAXCONTESTANTS - 1 >= i; i++){
        string name = savedNames[i];
        foundEmptyIndex = (name == "");

        if(i != 0 && !foundEmptyIndex) cout <<", "; 
        cout << name;

    }

    cout << " maybe added successfully!" << endl;
}