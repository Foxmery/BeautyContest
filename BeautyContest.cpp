#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib> // for system("cls"); setting
#include <vector>
using namespace std;

//Settings
bool clearConsoleSETTING = 1;//TODO: remoove global
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
};


void printMainMenu();
void clearConsole(bool clearConsoleSETTING);
int findFreeIndex(Contestants contestant[]);
bool checkCin();//TEST: new untested func
//void askForAction(int &choice);



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
            cout << "How many contestants do you want to add: ";
            cin >> contestantsToAdd;
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

                cout << "Enter age: ";//TODO: validation neded if only numbers
                cin >> contestant[validIndex].age;
                cout << endl;

                cout << "Enter gender (M/F): ";//TODO: validation neded if only letters 
                string input;
                getline(cin,input);

                // switch(input){

                // }
                cout << endl;

                cout << "Enter hip circumference (cm): "; //TODO: validation neded if only numbers
                cout << endl;

                cout << "Enter shoulder circumference (cm): "; //TODO: validation neded if only numbers
                cout << endl;

                cout << "Enter neck circumference (cm): "; //TODO: validation neded if only numbers
                cout << endl;

                cout << "Enter calf circumference (cm): "; //TODO: validation neded if only numbers
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
            cout<<"ERROR: Expectednumber from 0 to 6 got: "<< choise << endl; 
            break;


        }
    } while (true);



}

void printMainMenu() {

    cout <<
        "\n-------------BEAUTY CONTEST-------------\n"
        "1. Add new contestant\n"
        "    -Spaces left: spaces left in array\n"
        "    -How many contestants do you want to add (Validation: can't exceed the free spaces left)\n"
        "2. Show all contestants\n"
        "3. Search and show contestants by\n"
        "    3.1 The lowest age (input lowest age)\n"
        "    3.2 Name\n"
        "4. Sort contestants by oldest to youngest (No output)\n"
        "5. File\n"
        "    5.1 Export\n"
        "    5.2 Import\n"
        << endl;
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

string toLower(string str){//TODO: remoove the vectors
    vector<char> lettersIn; 
    vector<char> lettersOut;

    for (int i = 0; i < size(str); i++)
    {
        lettersIn[i] = str[i];
    }

    for(char letter : lettersIn){
        char newLetter;
        if (letter >= 'A' && letter <= 'Z'){
            newLetter = letter + 32;
        } else {
            newLetter = letter; //look at changes in test.cpp
        }
    }


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