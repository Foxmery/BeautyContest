#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>// for system("cls"); setting
using namespace std;



void printMainMenu();

struct Contestants {
    int ID;
    char name[30]; //LATTER: No mmater the lengh of the name we can write it
    int age;
    bool isWoman;
    double hipCirc;
    double  shoulderCirc;
    double calfCirc;
};

void clearConsole(bool clearConsoleSETTING);


//void askForAction(int &choice);


int main() {
    /*
    contestants properties = ID, Name, Age, gender, hip circumference, shoulder circumference, neck circumference, calf circumference

    -------------BASE PROGRAM - BEAUTY CONTEST-------------
    1. Add new contestant
        -"Spaces left:" spaces left in array
        -"How many contestants do you want to add:" (Validation: cant exceed the free sapces left)
    2. Show all contestants
    3. Search and show contestants by
        3.1 The lowest age (input lowest age)
        3.2 Name
    4. Sort contestants by oldest to youngest (No output)
    5. File
        5.1 Export in
        5.2 Import from

    */

    // TODO: make the struct infrastructure

    // TODO: function for printing contestants array
    // TODO: 



    const int MAXCONTESTANTS = 30;
    int leftSpaces = MAXCONTESTANTS;

    Contestants contestant[MAXCONTESTANTS]; //TODO: find a way to know which of the array slots are used and which are free(maybe with another bool array that  gets 1 if the slot is in use)


    bool clearConsoleSETTING = 1;

    

    int menuChoice;
    

    do {
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
            for (int i = 0; contestantsToAdd < i; i++) {

                cout << "Enter name: ";
                
                cout << endl;

                cout << "Enter age: ";
                cout << endl;

                cout << "Enter gender (M/F): ";
                cout << endl;

                cout << "Enter hip circumference (cm): ";
                cout << endl;

                cout << "Enter shoulder circumference (cm): ";
                cout << endl;

                cout << "Enter neck circumference (cm): ";
                cout << endl;

                cout << "Enter calf circumference (cm): ";
                cout << endl;

            }

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
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
        "    5.1 Export in .bjt\n"
        "    5.2 Import from .bjt\n"
        << endl;
}

void clearConsole(bool clearConsoleSETTING) {
    if (clearConsoleSETTING) {
        system("cls");
    }
}


// void myFunction() {
//     cout << "I just got executed!";
// }

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
