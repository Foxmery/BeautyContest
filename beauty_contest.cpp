#define NOMINMAX
#include <cstdint> //defiens integer types regardless of os
#include <iostream>
#include <string>
#include <cstdlib> // for system("cls"); setting
#include <limits>
#include <algorithm>

#include "menu_managment.h"
#include "exit_logic.h"
#include "visual_enhancement.h"
#include "debug.h"
#include "config.h"

using namespace std;


struct Contestants {
    int ID;
    bool isObjectUsed = 0;
    string name; 
    int age;
    bool isWoman = 1;
    double hipCirc;
    double shoulderCirc;
    double calfCirc;
    double neckCirc;
};


//Useful functions
int findFreeIndex(Contestants contestant[], int searchingFor = 0, int afterIndex = 0);
string toLowerString(string s);
void printContestant(Contestants contestant[], int index);



//CIN vlaidators
void resetCin ();
bool checkCin();
int cinCheckInt(const string& message);
double cinCheckDouble(const string& message);


int main() {

    // TODO: function for printing contestants array
    // TODO: 



    int leftSpaces = MAXCONTESTANTS;
    bool freeSpaces[MAXCONTESTANTS];
    int IDcounter = 0;


    /*for (int i = sizeof(freeSpaces); sizeof(freeSpaces) > i; i++) {
        cout << freeSpaces[i];
    }*/ // LATER TODO: implement the list so we can remove people and use the empty sapces
    /*cout<< freeSpaces;*/
    Contestants contestant[MAXCONTESTANTS];





    int menuChoice;


    do {
    //LATER: Ability to move around the menu with arrows
        mainMenuText();
        menuChoice = cinCheckInt("Type a number to chose your action: ");
    
        switch (menuChoice) {

            case 0: //Exit program 
                askUserExit();
                break;

            case 1: //Add new contestant 
            {
                 //TODO: Make submenu to chose 
                //LATER: Remoove feature that moves and packs all of the contestants to the start of the array, remooving non exitant contestant outputs error
            
                clearConsole(CLEARCONSOLE);

                
                cout << "Spaces left: " << leftSpaces << endl;
                
                // int contestantsToAdd;
                int contestantsToAdd = cinCheckInt("How many contestants do you want to add: ");
                

                //Validate input
                if (contestantsToAdd > leftSpaces) {
                    cout << "Too many contestants!" << endl;
                    break;
                }

                // TODO: add way to enter peoples properties in with struct
                for (int i = 0; contestantsToAdd > i; i++) {

                    int validIndex = findFreeIndex(contestant);

                    contestant[validIndex].isObjectUsed = true;

                    //Update contestant ID and increment one above
                    contestant[validIndex].ID = IDcounter++;
                    

                    cout << "Enter name: ";
                    getline(cin,contestant[validIndex].name);
                    cout << endl;

                    contestant[validIndex].age = cinCheckInt("Enter age: ");
                    cout << endl;

                    cout << "Enter gender (m/f): ";
                    string input;
                    //Accpets m,male,f,female case-insensitive
                    do{
                        //LATER: make it with enum and swtich
                        getline(cin,input);

                        input = toLowerString(input);
                        if (input == "m" || input == "male"){
                            contestant[validIndex].isWoman = 0;
                            break;
                        } else if ( input == "f" || input == "female"){
                            contestant[validIndex].isWoman = 1;
                            break;
                        } else {
                            cout<<"Invalid gender. Try again."<<endl;
                            cout << "Enter gender (M/F): ";
                        }
                    }   while (true);
                    cout << endl;

                    contestant[validIndex].hipCirc = cinCheckDouble("Enter hip circumference (cm): ");
                    cout << endl;

                    contestant[validIndex].shoulderCirc = cinCheckDouble("Enter shoulder circumference (cm): ");
                    cout << endl;

                    contestant[validIndex].neckCirc = cinCheckDouble("Enter neck circumference (cm): ");
                    cout << endl;

                    contestant[validIndex].calfCirc = cinCheckDouble("Enter calf circumference (cm): ");
                    cout << endl;
                    //contestant ..name.. saved!
                }
                //(numberOfcontestants) (names) saved successfuly!
                
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

                        //In case there is no such person foundPerson will stay 0 outputing a message. if 1 will jsut print the person
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





int findFreeIndex(Contestants contestant[], int searchingFor , int afterIndex) {
    //Outputs the first contestant it sees depending on if you want the contestant spot to be free or used
    //It searches after a curtain index so after putting it in a sycle it doesn`t output the same contestant
    for (int n = afterIndex; n < MAXCONTESTANTS; n++) {
        int cont = contestant[n].isObjectUsed;
        // cout << cont << endl;n
        if (cont == searchingFor) {
            // cout << "yep" << endl;
            deBugInfo("SYSTEM: Found free place at index: "<< n);

            return n;
        }

    }
    // cout << "No empty spaces" << endl;
    return -1;
}

string toLowerString(string s){
    string newS = "";
    int sizeOfString = s.length();
    
    for(int i = 0; i < sizeOfString; i++){
        char letter = s[i];
        
        if( letter >= 'A' && letter <= 'Z'){
            newS.append(1,letter + 32);
            
        } else {
            newS.append(1,letter);
        }
    }
    return newS;
}

void printContestant(Contestants contestant[], int index){

    deBugInfo("Index: " << index);
    cout << "ID: " << contestant[index].ID << "   ";
    cout << "Name: " << contestant[index].name << "   ";
    cout << "Age: " << contestant[index].age << "   ";
    cout << "Gender: " << ((contestant[index].isWoman) ? "Woman" : "Man") << "   ";
    cout << "HipCirc: " << contestant[index].hipCirc << "   ";
    cout << "ShoulderCirc: " << contestant[index].shoulderCirc << "   ";
    cout << "CalfCirc: " << contestant[index].calfCirc << "   ";
    cout << "NeckCirc: " << contestant[index].neckCirc << "   ";
    cout << endl;
}




bool checkCin(){
    if(cin) 
    {
        cin.clear(); 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        deBugInfo("SYSTEM: cin restarted");
        return true;
    } else {
        cin.clear(); 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        deBugInfo("ERROR: cin broke. Restared");
        return false;
    }
}

void resetCin (){
    cin.clear(); // fix the stream
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // yeet the garbage
}

int cinCheckInt(const string& message) {
    int value;
    while (true) {
        cout << message;

        if (cin >> value) {
            resetCin ();
            deBugInfo("SYSTEM: cin restarted");
            return value;
        } else {
            resetCin ();
            deBugInfo("ERROR: cin broke. Restared");
            cout << "Invalid input. Try again." << endl;
        }
    }
}


double cinCheckDouble(const string& message) {
    double value;
    while (true) {
        cout << message;// to be able to put values with , or . and have them intact

        if (cin >> value) {
            resetCin ();
            deBugInfo("SYSTEM: cin restarted");
            return value;
        } else {
            resetCin ();
            deBugInfo("ERROR: cin broke. Restared");
            cout << "Invalid input. Try again." << endl;
        }
    }
}




// void myFunction() {
//     cout << "I just got executed!";
// }


//LATER TODO: add way to add ascci pictures for contestants
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file