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
            clearConsole();
            return;
            break;
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
        default:
        {
            clearConsole();
            cout << "Invalid option!" << endl;
            deBugInfo("ERROR: expected from 0 - 4 got: " << menuChoice);
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


