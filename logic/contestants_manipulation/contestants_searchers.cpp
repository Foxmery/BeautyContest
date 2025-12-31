/// @file contestants_searchers.cpp
/// @brief Implementation of searching algorithms (by ID, Name, Age, etc.).

#include "contestants_searchers.h"

/**
 * @brief Outputs the first contestant it sees depending on if you want the contestant spot to be free or used.
 * * It searches after a certain index so after putting it in a cycle it doesnt output the same contestant
 * when no match found after the index outputs -1 which has to be detected with if statement.
 * * @param contestant  The array of all contestants.
 * @param searchingFor The value you want isObjectUsed to match.
 * @param afterIndex    The index to start searching from (to avoid duplicates).
 * @return int        The index of the next matching slot, or -1 if full.
 */
int findNextIndexByStatus(Contestants contestant[], int searchingFor = 0, int afterIndex = 0) {

    deBugInfo("SYSTEM - FNIBS:  was lunched!"  << endl);
    // deBugInfo("SYSTEM:FNIBS Starting search at index: " << afterIndex << endl);
    for (int n = afterIndex; n < MAXCONTESTANTS; n++) {
        int cont = contestant[n].isObjectUsed;
        if (cont == searchingFor) {
            // deBugInfo("SYSTEM:FNIBS Found match at index: "<< n << endl);
            return n;
        }
    }
    // deBugInfo("SYSTEM:FNIBS No spaces with " << searchingFor << endl);
    return -1;
}


   
int getNextFreeSlot(Contestants contestant[], int startIdx) {
    return findNextIndexByStatus(contestant, 0, startIdx);
}

  
int getNextUsedSlot(Contestants contestant[], int startIdx) {
    return findNextIndexByStatus(contestant, 1, startIdx);
}


bool searchContestantsByAge(Contestants contestant[],const int& age){

    bool foundPerson = false;
    int validIndex = getNextUsedSlot(contestant);
    for(int i = 0; i < MAXCONTESTANTS && validIndex != -1; i++){

        deBugInfo("SYSTEM: i =  "<< i << endl);
        deBugInfo("SYSTEM: age found: " << age << endl);

        validIndex = getNextUsedSlot(contestant, i);

        i = validIndex;
        if (contestant[validIndex].age == age){
            printContestant(contestant, validIndex);
            foundPerson = true;
        }
    }
    return foundPerson;
}


bool searchContestantsByWoman(Contestants contestant[],const bool& isWoman){

    bool foundPerson = false;
    for(int i = getNextUsedSlot(contestant); i < MAXCONTESTANTS && i != -1; i = getNextUsedSlot(contestant, i + 1)){

        if (contestant[i].isWoman == isWoman){
            printContestant(contestant, i);
            foundPerson = true;
        }
    }
    return foundPerson;
}
int biggestContestantID (Contestants contestant[]){

    int biggestID = 0;
    
    for(int i = getNextUsedSlot(contestant); i < MAXCONTESTANTS && i != -1; i = getNextUsedSlot(contestant, i + 1)){
        deBugInfo("SYSTEM - biggestContestantID: I: " << i << endl);
        if (contestant[i].ID > biggestID){
            biggestID = contestant[i].ID;
            deBugInfo("SYSTEM: biggestID: " << biggestID << " | I: " << i << endl);

        }
    }
    return biggestID;
}

int countOfContestants(Contestants contestant[]){
    int contestantCount = 0;

    for(int i = 0; i < MAXCONTESTANTS; i++){

        if (!contestant[i].isObjectUsed){
            contestantCount = contestantCount + 1;
            deBugInfo("SYSTEM:  contestantCount got incremented!" << endl);

        }
        deBugInfo("SYSTEM: contestantCount: " << contestantCount << endl;)
    }
    return contestantCount;
}

bool deleteContestantsByID(Contestants contestant[],const int& ID){

    bool foundPerson = false;
    int validIndex = getNextUsedSlot(contestant);
    for(int i = validIndex; i < MAXCONTESTANTS && validIndex != -1; i++){

        validIndex = getNextUsedSlot(contestant, i);

        i = validIndex;
        if (contestant[validIndex].ID == ID){
            cout << "Contestant " << contestant[validIndex].name << " successfully delted!" << endl;
            contestant[validIndex].isObjectUsed = false;
            foundPerson = true;
        }
    }
    return foundPerson;
}


bool searchContestantByName(Contestants contestant[], char nameToSearch[], int sizeToSearch, string didYouMeanNames[]){
    bool foundPerson = false;
    int validIndex = getNextUsedSlot(contestant);
    int didYouMean_ValidIndex = 0;
    for(int i = validIndex; i < MAXCONTESTANTS && validIndex != -1; i++ )
    {

        char contName[MAXNAMECHARS];
        strcpy(contName, contestant[i].name);

        int sizeFirst =  sizeof(contName) / sizeof(contName[0]);
        int sizeSecond = sizeToSearch / sizeof(nameToSearch[0]);
        int differences = countDifferencesBetweenCharArrays(contName, nameToSearch, sizeFirst, sizeSecond); 
        
        
        if(differences == 0){
            printContestant(contestant, i);
            foundPerson = true;
        } else if (differences == 1 && !foundPerson){
            didYouMeanNames[didYouMean_ValidIndex] = contestant[i].name;
            didYouMean_ValidIndex++;
        }
        
        validIndex = getNextUsedSlot(contestant, i);
        i = validIndex;
        deBugInfo("Next validIndex: " << validIndex << endl);
    }
    return foundPerson;
}

int searchLowestAge (Contestants contestant[]){

    int validIndex = getNextUsedSlot(contestant);
    int lowestAge = contestant[validIndex].age;
    for(int i = 1; i < MAXCONTESTANTS; i++){

        validIndex = getNextUsedSlot(contestant, i);
        i = validIndex;


        if (validIndex == -1) {
            cout << endl;
            break;
        }


        int contestantAge = contestant[validIndex].age;
        if(contestantAge <= lowestAge){
            lowestAge = contestantAge;
        }

    }
    return lowestAge;
}