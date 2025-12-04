#define NOMINMAX
#include <cstdint> //defiens integer types regardless of os
#include <iostream>
#include <string>
#include <cstdlib> // for system("cls"); setting
#include <limits>
#include <algorithm>

using namespace std;


const int MAXCONTESTANTS = 30;
const bool DEBUGMODE = 0;

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

#define deBugInfo(message) if (DEBUGMODE) { cout << message << endl; } // macro

int searchContestantNumberPROTOTYPE(Contestants contestant[],const int& searchMode,const double& targetValue,const int& startIdx) {
        //shouldve implemented this
    
    

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
//FUCNTION TO ADD
Contestants easyContInit(int ID = -1, bool isObjectUsed = 0, string name = "NONE", int age = 0, bool isWoman = 0, double hipCirc = 0, double shoulderCirc = 0, double calfCirc = 0, double neckCirc = 0){
    
    Contestants cont;
    cont.ID = ID;
    cont.isObjectUsed = isObjectUsed;
    cont.name = name;
    cont.age = age;
    cont.isWoman = isWoman;
    cont.hipCirc = hipCirc;
    cont.shoulderCirc = shoulderCirc;
    cont.calfCirc = calfCirc;
    cont.neckCirc = neckCirc;
    return cont;
    
}

Contestants randomContestantGenerator (int ID) 
{
Contestants cont;
string names[60] = {
    "Arden", "Lyra", "Corvin", "Selene", "Marek", "Isolde",
    "Dorian", "Kara", "Theron", "Vera", "Cassian", "Mira",
    "Lior", "Sabine", "Jarek", "Elara", "Nolan", "Talia",
    "Caelan", "Rhea", "Lucian", "Nadia", "Silas", "Iris",
    "Rowan", "Delphine", "Kellan", "Freya", "Orion", "Maeve",
    "Darius", "Lina", "Anders", "Helena", "Stellan", "Cora",
    "Evander", "Seren", "Malek", "Yara", "Quentin", "Selah",
    "Brennan", "Elowen", "Tristan", "Nova", "Soren", "Elise",
    "Ronan", "Astrid", "Leander", "Nerina", "Magnus", "Ayla",
    "Cyrus", "Junia", "Therin", "Sabriel"
};
    //TODO: put srand(time(0)); in the header
    
    cont.isObjectUsed = true;
    cont.name = names[rand() % 60];
    cont.age = rand() % 85 + 15;
    cont.isWoman = rand() % 2;
    if (cont.isWoman){
       cont.hipCirc = (rand() % 600)/100.0  + 31;
       cont.shoulderCirc = (rand() % 1600)/100.0  + 95;
       cont.calfCirc = (rand() % 2100)/100.0  + 95;
       cont.neckCirc = (rand() % 700)/100.0  + 33;
    }else{
       cont.hipCirc = (rand() % 800)/100.0  + 36;
       cont.shoulderCirc = (rand() % 2100)/100.0  + 110;
       cont.calfCirc = (rand() % 1600)/100.0  + 90;
       cont.neckCirc = (rand() % 800)/100.0  + 34;
    }
    return cont;
}    

int main(){
srand(time(0));
Contestants contestant[MAXCONTESTANTS];

//TODO: Remove endl in deBugInfo and add endl where needed after change
//TODO: Implement new function:easyContInit
//TODO: Remove extra spaces in print contestant 3?4 line
//TODO: Add defalult values in struct Contestants
/*contestant[0] = easyContInit(1,1,"Bofadese",35,1,3.5,5.6,7.8,70);
contestant[1] = easyContInit(2,1,"Ligma",67,1,6.5,2.4,9,10);
contestant[2] = easyContInit(3,1,"Candys",47,1,4.5,3.4,7,6);
contestant[3] = easyContInit(4,1,"Deze",39,1,3.6,57,19,9);
contestant[4] = easyContInit(5,1,"Tuov",68,0,1,2,33,4);
contestant[5] = easyContInit(6,1,"Sugondese",16,0,6,4,7,8);
contestant[6] = easyContInit(7,1,"Nanaia",17,1,4,5,6,7);
*/
//                clearConsole(CLEARCONSOLE);


for(int i = 0; i < 5;i++){
    contestant[i] = randomContestantGenerator(i);
} 
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
//                break;

/*                int i = 0;
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
                */
}
                
                 