#include "contestants_searchers.h"

/**
 * @brief Outputs the first contestant it sees depending on if you want the contestant spot to be free or used.
 * * It searches after a certain index so after putting it in a cycle it doesn`t output the same contestant
 * when no match found after the index outputs -1 which has to be detected with if statement.
 * * @param contestant  The array of all contestants.
 * @param searchingFor The value you want isObjectUsed to match.
 * @param afterIndex    The index to start searching from (to avoid duplicates).
 * @return int        The index of the next matching slot, or -1 if full.
 */
int findNextIndexByStatus(Contestants contestant[], int searchingFor = 0, int afterIndex = 0) {

    deBugInfo("SYSTEM:FNIBS Starting search at index: " << afterIndex << endl);
    for (int n = afterIndex; n < MAXCONTESTANTS; n++) {
        int cont = contestant[n].isObjectUsed;
        if (cont == searchingFor) {
            deBugInfo("SYSTEM:FNIBS Found match at index: "<< n << endl);
            return n;
        }
    }
    deBugInfo("SYSTEM:FNIBS No spaces with " << searchingFor << endl);
    return -1;
}


   
int getNextFreeSlot(Contestants contestant[], int startIdx) {
    return findNextIndexByStatus(contestant, 0, startIdx);
}

  
int getNextUsedSlot(Contestants contestant[], int startIdx) {
    return findNextIndexByStatus(contestant, 1, startIdx);
}


//Holly grail of search in contestant function but maybe will be split to smaller functions
int searchContestantNumberPROTOTYPE(Contestants contestant[], const int& searchMode, const double& targetValue, const int& startIdx) {
        //should implemented this

    for (int i = startIdx; i < MAXCONTESTANTS; i++) {
        
        // Skip empty slots unless you are specifically looking for 'isObjectUsed' (case 1)
        if (searchMode != 1 && !contestant[i].isObjectUsed) continue;

        double currentVal = 0;
        bool validMode = true;

        switch (searchMode) {
            case 0: currentVal = contestant[i].ID; break;
            case 1: currentVal = contestant[i].isObjectUsed; break;
            // Case 2 (Name) is removed -> Strings cannot be doubles!
            case 3: currentVal = contestant[i].age; break;
            case 4: currentVal = contestant[i].isWoman; break;
            case 5: currentVal = contestant[i].hipCirc; break;
            case 6: currentVal = contestant[i].shoulderCirc; break;
            case 7: currentVal = contestant[i].calfCirc; break;
            case 8: currentVal = contestant[i].neckCirc; break;
            default: validMode = false; break;
        }

        if (validMode && currentVal == targetValue) {
            deBugInfo("SYSTEM: Found match at index: " << i);
            return i;
        }
    }
    return -1;
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
    int validIndex = getNextUsedSlot(contestant);
    for(int i = validIndex; i < MAXCONTESTANTS && validIndex != -1; i++){

        validIndex = getNextUsedSlot(contestant, i);

        i = validIndex;
        if (contestant[validIndex].isWoman == isWoman){
            printContestant(contestant, validIndex);
            foundPerson = true;
        }
    }
    return foundPerson;
}

/// @brief 
/// @param arr 
/// @param sizeArr 
/// @param end 
/// @return 
int getRealSizeOfCharArray(char arr[], int sizeArr, char end = '\0'){
    int realSize = 0;
    bool endOfArray = 0;
    for(int i = 0; i < sizeArr - 1 && !endOfArray; i++){
        realSize++;
        endOfArray = arr[i + 1] == end;
        // cout << "Next: " << arr[i + 1] << endl;
        // cout << "EndOfArr: " << endOfArray << endl;
    }
    return realSize; 
}

bool searchContestantByName(Contestants contestant[], char nameToSearch[], int sizeToSearch, string didYouMeanNames[]){
    bool foundPerson = false;
    int validIndex = getNextUsedSlot(contestant);
    int didYouMean_ValidIndex = 0;
    for(int i = validIndex; i < MAXCONTESTANTS && validIndex != -1; i++ )
    {
        
        

        char contName[MAXNAMECHARS];
        strcpy(contName, contestant[i].name);

        int sizeFirst = getRealSizeOfCharArray(contName, sizeof(contName) / sizeof(contName[0]));
        int sizeSecond = getRealSizeOfCharArray(nameToSearch, sizeToSearch / sizeof(nameToSearch[0]));
        int diffrences = countDifferencesBetweenCharArrays(contName, nameToSearch, sizeFirst, sizeSecond); //!strcmp(contestant[i].name, nameToSearch);
        
        
        if(diffrences == 0){
            printContestant(contestant, i);
            foundPerson = true;
        } else if (diffrences == 1 && !foundPerson){
            didYouMeanNames[didYouMean_ValidIndex] = contestant[i].name;
            didYouMean_ValidIndex++;
        }
        
        validIndex = getNextUsedSlot(contestant, i);
        i = validIndex;
        deBugInfo("Next validIndex: " << validIndex << endl);
    }
    return foundPerson;
}