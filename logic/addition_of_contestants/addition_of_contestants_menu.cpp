#include "addition_of_contestants_menu.h"

int GetValidContestantCount(int& leftSpaces);
void inputContestantData(const int contestantsToAdd, int& IDcounter, Contestants contestant[], bool random);
void readSingleContestant(Contestants& contestant,const int& IDcounter);
void printAddedContestants(string savedNames[]);

void additionOfContestantsMenu(Contestants contestant[], int& leftSpaces, int& IDcounter, int& menuChoice){
    //TODO: Make submenu to chose 
    //TODO: Way to add as many random contestants as you like
    clearConsole(CLEARCONSOLE);
    int contestantsToAdd = GetValidContestantCount(leftSpaces);
    if (leftSpaces == 0){
        
    }

    leftSpaces -= contestantsToAdd;

    switch (menuChoice){
        case 0:
            break;
        case 1:
            inputContestantData(contestantsToAdd, IDcounter, contestant, false);
            break;
        case 2:
            inputContestantData(contestantsToAdd,IDcounter,contestant, true);
            break;
        default:
            cout << "Invalid option!" << endl;
            deBugInfo("ERROR: expected from 0 - 2 got: " << menuChoice);
            break;
    }
}



int GetValidContestantCount(int& leftSpaces){
    do{
        cout << "Spaces left: " << leftSpaces << endl;

        int contestantsToAdd = cinCheckInt("How many contestants do you want to add: ");

        //Validate input
        if (contestantsToAdd > leftSpaces) {
            clearConsole(CLEARCONSOLE);
            cout << "Too many contestants!" << endl << endl;
            continue;
        } else {
            return contestantsToAdd;
        }
    } while(true);
}

void inputContestantData(const int contestantsToAdd, int& IDcounter, Contestants contestant[], bool random){
    string savedNames[MAXCONTESTANTS];
    deBugInfo("SYSTEM: size savedNames: " << size(savedNames) << endl);
    //Manually enter contestants information
    for (int i = 0; contestantsToAdd > i; i++) {

        int validIndex = findFreeIndex(contestant);
        //Update contestant ID and increment one above
        
        if (random){
            randomContestantGenerator(contestant[validIndex], IDcounter++);
        } else {
            readSingleContestant(contestant[validIndex], IDcounter++);
        }
        savedNames[i] = contestant[validIndex].name;

    }
    // deBugInfo("SYSTEM: exited from adding contestants");

    if(savedNames[0] == ""){
        clearConsole(CLEARCONSOLE);
        cout << "No contestants added." << endl;
        deBugInfo("SYSTEM: contestantsToAdd: " << contestantsToAdd);
    } else {
        printAddedContestants(savedNames);
    }
}

void printAddedContestants(string savedNames[]){
    //EXPLANATION: prints out the added contestants names

    clearConsole(CLEARCONSOLE);
    deBugStringArray(savedNames, MAXCONTESTANTS);
    cout << "Contestant/s ";

    //Print out the names
    bool foundEmptyIndex = false;

    for(int i = 0; !foundEmptyIndex && MAXCONTESTANTS - 1 >= i; i++){
        // deBugInfo("SYSTEM: index: " << i << endl);
        string name = savedNames[i];
        foundEmptyIndex = (name == "");

        if(i != 0 && !foundEmptyIndex) cout <<", "; 
        cout << name;

    }


    cout << " maybe saved successfully!" << endl;
    
}

void readSingleContestant(Contestants& contestant,const int& IDcounter){
    //ID
    contestant.ID = IDcounter;

    //Name
    cout << "Enter name: ";
    getline(cin,contestant.name);
    cout << endl;

    //Age
    contestant.age = cinCheckInt("Enter age: ");
    cout << endl;

    //Gender
    cout << "Enter gender (M/F): ";
    string input;
    do {
        getline(cin, input);

        // Safety check for empty input
        if (input.empty()) continue; 

        // Get first character and lowercase it immediately
        char gender = tolower(input[0]); 

        if (gender == 'm') {
            contestant.isWoman = false;
            break;
        } else if (gender == 'f') {
            contestant.isWoman = true;
            break;
        }

        cout << "Invalid gender. Try again (M/F): ";

    } while (true);
    cout << endl;

    //Hips
    contestant.hipCirc = cinCheckDouble("Enter hip circumference (cm): ");
    cout << endl;

    //Shoulders
    contestant.shoulderCirc = cinCheckDouble("Enter shoulder circumference (cm): ");
    cout << endl;

    //Neck
    contestant.neckCirc = cinCheckDouble("Enter neck circumference (cm): ");
    cout << endl;

    //Calf
    contestant.calfCirc = cinCheckDouble("Enter calf circumference (cm): ");
    cout << endl;
}


    