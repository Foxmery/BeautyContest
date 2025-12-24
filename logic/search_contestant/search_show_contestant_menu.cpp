#include "search_show_contestant_menu.h"

int searchLowestAge (Contestants contestant[]);
bool searchContestantsByAge(Contestants contestant[],const int& age);
bool searchContestantsByWoman(Contestants contestant[],const bool& gender);

bool searchContestantByName(Contestants contestant[], char nameToSearch[], int sizeToSearch, string didYouMeanNames[]);
int countDifferencesBetweenCharArrays(char first[], char second[], int sizeFirst, int sizeSecond);

void unsuccessfulSearch(bool event, string startingMessage, char s[], string didYouMeanNames[]);
void unsuccessfulSearch(bool event, string startingMessage, int num);

void searchShowContestantsMenu(Contestants contestant[], int& menuChoice){
    switch(menuChoice){
        case 0:
        {
            return;
        }
        case 1: 
        {
            clearConsole(CLEARCONSOLE);
            
            cout << "Contestant/s with lowest age: " << endl;

            int lowestAge = searchLowestAge(contestant);
            bool foundPerson = searchContestantsByAge(contestant, lowestAge);
            


            break;
        }
        case 2:
        {
            clearConsole(CLEARCONSOLE);

            int age;
            age = cinCheckInt("Enter age of contestant: ");

            bool foundPerson = searchContestantsByAge(contestant, age);

            unsuccessfulSearch(!foundPerson, "Person with age ", age);
            break;
        }
        case 3: 
        {
           
            clearConsole(CLEARCONSOLE);

            
            cout << "Enter name of contestant: ";

            char nameToSearch[MAXNAMECHARS];
            cin >> nameToSearch;

            string didYouMeanNames[MAXCONTESTANTS];

            bool foundPerson = searchContestantByName(contestant, nameToSearch, sizeof(nameToSearch), didYouMeanNames);
            
            unsuccessfulSearch(!foundPerson, "Person with name ", nameToSearch , didYouMeanNames);
            break;
        }
        case 4:
        {
            clearConsole(CLEARCONSOLE);
            bool gender = cinCheckIsWoman("Enter gnder to search for (m/f): ");

            bool foundPerson = searchContestantsByWoman(contestant, gender);

            unsuccessfulSearch(!foundPerson, "Person with gender ", gender ? 'f' : 'm');
            break;
        }
    }
}


/// @brief Finds lowest age in Contestants struct
/// @param contestant array of all contestants
/// @return if it found a match
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

/// @brief Prints out contestants with given age and if it found someone
/// @param contestant array of all contestants
/// @param age age to search for
/// @return if it found a match
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

/// @brief Prints out contestants with given gender
/// @param contestant array of all contestants
/// @param isWoman this is the given gender
/// @return if it found a match
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

int countDifferencesBetweenCharArrays(char first[], char second[], int sizeFirst, int sizeSecond){
    int lastToCheck = max(sizeFirst, sizeSecond);
    deBugInfo("SYSTEM: lastToCheck: " << lastToCheck << endl);

    int diffrences = 0;

    for(int i  = 0; i < lastToCheck ; i++ ){
        bool diffrent = tolower(first[i]) != tolower(second[i]);
        if(diffrent) diffrences++;
        deBugInfo("F: " << first[i] << " S: " << second[i] << " D? " << diffrent << endl);
        //deBugInfo("SYSTEM: Comparing " << tolower(first[i]) << " and " << tolower(second[i]) << " | " << "nowDiff: " << diffrences);
    }
    deBugInfo("Total differences: " << diffrences <<" | Compared: " << first << " and " << second << endl << endl);
    return diffrences;
}


void unsuccessfulSearch(bool event, string startingMessage, char s[], string didYouMeanNames[]){
    if (event){
        cout << startingMessage << s << " has not been found.\n";

        //DID you mean logic
        bool haveSuggestions = didYouMeanNames[0] != "";
        if(haveSuggestions){
            cout << "Did you mean ";
            bool nextIsEmpty = false;
            for(int i = 0; !nextIsEmpty && MAXCONTESTANTS - 1 >= i; i++){
                string name = didYouMeanNames[i];
                nextIsEmpty = (name == "");

                if(i != 0 && !nextIsEmpty) cout <<" or "; 
                cout << name;

            }
            cout << ".\n";
        }
        

    }

    
}

void unsuccessfulSearch(bool event, string startingMessage, int num){
    if (event){
        cout << startingMessage << num << " has not been found.\n";
        //LATER: do you want to search for someone else? y/n/0/1/yes,YES/no,NO/back,Back,b,B
    }
}


