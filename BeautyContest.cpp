#define NOMINMAX
#include <iostream>
#include <string>
#include <cstdlib> // for system("cls"); setting
#include <limits>
#include <algorithm>
#include "MenuManagment.h"

using namespace std;

//Settings
bool clearConsoleSETTING = 0;//TODO: remoove global
const int MAXCONTESTANTS = 30; //TODO: remoove global




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



void clearConsole(bool clearConsoleSETTING);
int findFreeIndex(Contestants contestant[]);
string toLowerString(string s);

//CIN vlaidators
bool checkCin();
int cinCheckInt(const string& message);
double cinCheckDouble(const string& message);



int main() {

    // TODO: function for printing contestants array
    // TODO: 



    int leftSpaces = MAXCONTESTANTS;

    bool freeSpaces[MAXCONTESTANTS];


    /*for (int i = sizeof(freeSpaces); sizeof(freeSpaces) > i; i++) {
        cout << freeSpaces[i];
    }*/ // LATER TODO: implement the list so we can remove people and use the empty sapces
    /*cout<< freeSpaces;*/
    Contestants contestant[MAXCONTESTANTS];





    int menuChoice;


    do {
    //LATER: Ability to move around the menu with arrows
        printMainMenu();
        cout << "Type a number to chose your action: ";
        cin >> menuChoice;
        cout << endl;

        if (!checkCin()){
            cout<<"ERROR: expected number got diffrent"<<endl;
            cout<<"Please eneter a valid number"<<endl;
            continue;
        }


        switch (menuChoice) {

        case 0: //Exit program 
            cin.ignore();

            while (true) {
                clearConsole(clearConsoleSETTING);
                cout << "Do you really want to exit? y/n" << endl;

                string answer;

                getline(cin, answer);
                /*char firstLeeter = answer[0];
                printf("%d", firstLeeter);*/ //just some debuggin things

                if (answer.compare("y") == 0) {
                    cout << "Goodbye!";
                    exit(0);
                }
                else if (answer.compare("n") == 0) {
                    clearConsole(clearConsoleSETTING);


                    break;
                }
                else {
                    cout << "ERROR: expected y or n got: " << answer<<endl;
                }
            }


            break;
        case 1: //Add new contestant 
            //TODO: Make submenu to chose 
            //LATER: Remoove feature, remooving non exitant outputs error
        
            clearConsole(clearConsoleSETTING);

            int contestantsToAdd;
            cout << "Spaces left: " << leftSpaces << endl;
            cinCheckInt("How many contestants do you want to add: ");
            cout << endl;
            

            //Validate input
            if (contestantsToAdd > leftSpaces) {
                cout << "Too many contestants!" << endl;
                break;
            }

            // TODO: add way to enter peoples properties in with struct
            for (int i = 0; contestantsToAdd > i; i++) {

                int validIndex = findFreeIndex(contestant);

                contestant[validIndex].isObjectUsed = true;


                cout << "Enter name: ";
                getline(cin,contestant[validIndex].name);
                cout << endl;

                contestant[validIndex].age = cinCheckInt("Enter age: ");
                cout << endl;

                cout << "Enter gender (m/f): ";//Accpets m,male,f,female case-insensitive
                string input;
                do{
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

            }
            break;
        case 2:
                    //TODO: Make submenu to chose 
            clearConsole(clearConsoleSETTING);

            break;
        case 3:
                    //TODO: Make submenu to chose 
            clearConsole(clearConsoleSETTING);

            break;
        case 4:
                    //TODO: Make submenu to chose 
            clearConsole(clearConsoleSETTING);

            break;
        case 5:
                    //TODO: Make submenu to chose 
            clearConsole(clearConsoleSETTING);

            break;
        case 6:
                    //TODO: Make submenu to chose 
            clearConsole(clearConsoleSETTING);

            break;
        default:
            cout<<"ERROR: Expectednumber from 0 to 6 got: "<< menuChoice << endl; 
            break;


        }
    } while (true);



}



void clearConsole(bool clearConsoleSETTING) {
    if (clearConsoleSETTING) {
        system("cls");
    }
}
int findFreeIndex(Contestants contestant[]) {
    for (int n = 0; n < MAXCONTESTANTS; n++) {
        int cont = contestant[n].isObjectUsed;
        // cout << cont << endl;
        if (cont == 0) {
            // cout << "yep" << endl;
            return n;
        }

    }
    cout << "No empty spaces" << endl;
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



bool checkCin(){
    if(cin) 
    {
        cin.clear(); 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        cout<<"SYSTEM: cin restarted"<<endl;
        return true;
    } else {
        cin.clear(); 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        cout<<"ERROR: cin broke. Restared"<<endl;
        return false;
    }
}

int cinCheckInt(const string& message) {
    int value;
    while (true) {
        cout << message;

        if (cin >> value) {
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            cout<<"SYSTEM: cin restarted"<<endl;
            return value;
        } else {
            cin.clear(); // fix the stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // yeet the garbage
            cout<<"ERROR: cin broke. Restared"<<endl;
            cout << "Invalid input. Try again." << endl;
        }
    }
}


double cinCheckDouble(const string& message) {
    double value;
    while (true) {
        cout << message;

        if (cin >> value) {
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            cout<<"SYSTEM: cin restarted"<< endl;
            return value;
        } else {
            cin.clear(); // fix the stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // yeet the garbage
            cout<<"ERROR: cin broke. Restared"<< endl;
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