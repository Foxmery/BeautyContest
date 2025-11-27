#include "beauty_contest.h"

//LATER: possible to enter 3.1 to enter straight into a menu(maybe learn regex again)
//LATER: add way to add ascic pictures for contestants
//LATER: Remove feature that moves and packs all of the contestants to the start of the array, removing non existant contestant outputs error
//LATER: Ability to move around the menu with arrows

int main() {
    srand(time(0)); //"True randomness"

    int leftSpaces = MAXCONTESTANTS;
    bool freeSpaces[MAXCONTESTANTS];
    int IDcounter = 1;

    Contestants contestant[MAXCONTESTANTS];

    int menuChoice;

    do {
        mainMenuText();
        menuChoice = cinCheckInt("Type a number to chose your action: ");
                
        switch (menuChoice) {

            case 0: //Exit program 
                askUserExit();
                break;

            case 1: //Adding of contestant 
            {
                addingContestantsMenu();
                menuChoice = cinCheckInt("Type a number to chose your action: ");

                contestantsManipulationMenu(contestant, leftSpaces, IDcounter, menuChoice);
                break;
            }
               
            case 2: //Show all contestants
            {   
                //LATER: Make submenu to chose 
                clearConsole(CLEARCONSOLE);
                cout << "------All contestants------" << endl;
                
                for(int i = 0; i < MAXCONTESTANTS; i++){

                    int validIndex = findFreeIndex(contestant, 1, i);
                    i = validIndex;

                    //When findFreeIndex is done it outputs -1. This "if" breaks when detects -1;
                    if (validIndex == -1) {
                        cout << endl;
                        break;
                    }
                
                    printContestant(contestant, validIndex);
                }
                break;
            }
               

            case 3://Search and show contestants by:
            {   
                //TODO: Make submenu to chose     
                clearConsole(CLEARCONSOLE);
                searchMenuText();
                menuChoice = cinCheckInt("Type a number to chose your action: ");
                cout << endl;

                switch(menuChoice){
                    case 1: //Print out the lowest age
                    {
                        clearConsole(CLEARCONSOLE);

                        int lowestAge = numeric_limits<std::int32_t>::max(); //Here is used #include <cstdint> for int32_t
                        cout << lowestAge << endl;/*debugin*/

                        for(int i = 0; i < MAXCONTESTANTS; i++){

                            int validIndex = findFreeIndex(contestant, 1, i);
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
                        int p = 0;/*debugin*/

                        for(int i = 0; i < MAXCONTESTANTS; i++){
                            cout << "SYSTEM: P = " << p << endl;/*debugin*/
                            cout << "SYSTEM: i = " << i << endl;/*debugin*/

                            //NOW: TEST WHY PROGRAM IS MAKING AGES THE SAME!!!!!
                            cout << "Contestants with lowest age: " << lowestAge << endl;

                            int validIndex = findFreeIndex(contestant, 1, i);
                            i = validIndex;
                            if (contestant[validIndex].age = lowestAge){
                                printContestant(contestant, validIndex);
                            }

                            if(p == 10){/*debugin*/
                                exit(0); 
                            }
                            p++;/*debugin*/
                        }
                        break;
                    }
                    case 2: // Print out by name
                    {   
                        
                        // goes through all the the valid contestant
                        clearConsole(CLEARCONSOLE);

                        string input;
                        cout << "Enter name of contestant: ";
                        getline(cin, input);

                        //In case there is no such person foundPerson will stay 0 outputing a message. if 1 will just print the person
                        bool foundPerson = 0;
                        //searching for contestants name
                        for(int i = 0; i < MAXCONTESTANTS; i++ )
                        {
                            if(!contestant[i].isObjectUsed || contestant[i].name != input){
                                printContestant(contestant, i);
                                foundPerson = 1;
                            }
                        }
                        if (foundPerson){
                            cout << input << " has not been found.\n";
                            //LATER: do you want to search for someone else? y/n/0/1/yes,YES/no,NO/back,Back,b,B
                        }
                        break;
                    }
                }
            break;
            }
            

            case 4: //Sort the contestants
            {
                //TODO: Make submenu to chose 
                clearConsole(CLEARCONSOLE);

                int i = 0;
                int lastIndex = 0;

                do{
                    
                    //if next contestant is not in use remoove stop the program
                    if (contestant[i+1].isObjectUsed == 0){
                        break;
                    }
                    if(contestant[i].age > contestant[i+1].age){
                        //swap contestant places
                        Contestants placeHolder = contestant[i];
                        contestant[i] = contestant[i+1];
                        contestant[i+1] = placeHolder;

                    } else if (i == 0){
                        lastIndex++;
                        i = lastIndex;

                    } else {
                        i--;

                    }

                } while(i != MAXCONTESTANTS);

                break;
            }
                

            case 5:
            {
                //TODO: Make submenu to chose 
                clearConsole(CLEARCONSOLE);

                break;
            }

            case 6:
            {
                //TODO: Make submenu to chose 
                clearConsole(CLEARCONSOLE);

                break;
            }

            default:
            {   
                deBugInfo("ERROR: Expectednumber from 0 to 6 got: "<< menuChoice << endl);
                cout<< "Please enter a valid option!";
                break;
            }
                
        }
    } while (true);



}



