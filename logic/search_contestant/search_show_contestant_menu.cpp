#include "search_show_contestant_menu.h"

//NOW: go back to making search_show_contestant.cpp(first look at findFreeIndex)
void searchShowContestantsMenu(Contestants contestant[], int& menuChoice){
    switch(menuChoice){
        case 1: //Print out the lowest age
        {
            clearConsole(CLEARCONSOLE);

            int validIndex = findFreeIndex(contestant, 1);
            int lowestAge = contestant[validIndex].age;

            findLowestAge(contestant, validIndex, lowestAge);

            findContestantsByAge(contestant, validIndex, lowestAge);
            

            break;
        }
        case 2: // Print out by name
        {
            // goes through all the the valid contestant
            clearConsole(CLEARCONSOLE);

            string input;
            cout << "Enter name of contestant: ";
            getline(cin, input);

            bool foundPerson = false;
            //searching for contestants name
            for(int i = 0; i < MAXCONTESTANTS; i++ )
            {
                if(contestant[i].isObjectUsed && contestant[i].name == input){
                    printContestant(contestant, i);
                    foundPerson = true;
                }
            }
            if (foundPerson){
                cout << input << " has not been found.\n";
                //LATER: do you want to search for someone else? y/n/0/1/yes,YES/no,NO/back,Back,b,B
            }
            break;
        }
    }
}

void findLowestAge (Contestants contestant[], int& validIndex, int& lowestAge){
    for(int i = 0; i < MAXCONTESTANTS; i++){

        validIndex = findFreeIndex(contestant, 1, i);
        i = validIndex;

        //When findFreeIndex doesn`t find free spaces outputs -1. This "if" breaks when detects -1;
        if (validIndex == -1) {
            cout << endl;
            break;
        }

        //Is contestant having the lowest age? yes: update with new lowest age 
        int contestantAge = contestant[validIndex].age;
        if(contestantAge <= lowestAge){
            lowestAge = contestantAge;
        }

    }
}

void findContestantsByAge(Contestants contestant[], int& validIndex, int& age){
    for(int i = 0; i < MAXCONTESTANTS; i++){

        deBugInfo("SYSTEM: i =  "<< i << endl);
        deBugInfo("SYSTEM: age found: " << age << endl);

        int validIndex = findFreeIndex(contestant, 1, i);
        if (validIndex == -1)break;
        i = validIndex;
        if (contestant[validIndex].age == age){
            printContestant(contestant, validIndex);
        }
    }
}




