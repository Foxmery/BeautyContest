#include "search_show_contestant_menu.h"


/// @brief Did you mean functions if name is close to one from the contestants list
/// @param event If the search was successful or not
/// @param startingMessage Whit what you want to start your unsuccessful search message
/// @param s What name user searched for
/// @param didYouMeanNames List of possible names user maybe wanted to type
void unsuccessfulSearch(bool event, string startingMessage, char s[], string didYouMeanNames[]);

/// @brief Simpler unsuccessful messenger function
/// @param event Weather the search was successful or not
/// @param startingMessage How you want to start the unsuccessfulness
/// @param num Parameter user searched for
void unsuccessfulSearch(bool event, string startingMessage, string num);

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

            unsuccessfulSearch(!foundPerson, "Person with age ", to_string(age));
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
            bool gender = cinCheckIsWoman("Enter gender to search for (m/f): ");

            bool foundPerson = searchContestantsByWoman(contestant, gender);

            unsuccessfulSearch(!foundPerson, "Person with gender ", gender ? "f" : "m");
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

void unsuccessfulSearch(bool event, string startingMessage, string num){
    if (event){
        cout << startingMessage << num << " has not been found.\n";
    }
}


