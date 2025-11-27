#include "contestants_manipulation_menu.h"

int inputContestantsToAdd(int contestantsToAdd,int& leftSpaces);
void inputContestantData(const int contestantsToAdd, int& IDcounter, Contestants contestant[], bool random);
void readSingleContestant(Contestants& contestant,const int& IDcounter);

void contestantsManipulationMenu(Contestants contestant[], int& leftSpaces, int& IDcounter, int& menuChoice){
    
    //TODO: Make submenu to chose 
    //TODO: Way to add as many random contestants as you like
    clearConsole(CLEARCONSOLE);
    int contestantsToAdd = inputContestantsToAdd(contestantsToAdd, leftSpaces);
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

    cout << "Contestants added successfully!" << endl;
}



int inputContestantsToAdd(int contestantsToAdd,int& leftSpaces){
    do{
        cout << "Spaces left: " << leftSpaces << endl;

        contestantsToAdd = cinCheckInt("How many contestants do you want to add: ");

        //Validate input
        if (contestantsToAdd > leftSpaces) {
            cout << "Too many contestants!" << endl;
            continue;
        } else {
            return contestantsToAdd;
        }
    } while(true);
}

void inputContestantData(const int contestantsToAdd, int& IDcounter, Contestants contestant[], bool random){
    //Manually enter contestants information
    for (int i = 0; contestantsToAdd > i; i++) {

        int validIndex = findFreeIndex(contestant);
        //Update contestant ID and increment one above
        
        if (random){
            randomContestantGenerator(contestant[validIndex], IDcounter++);
        } else {
            readSingleContestant(contestant[validIndex], IDcounter++);
        }

        
    }
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


    