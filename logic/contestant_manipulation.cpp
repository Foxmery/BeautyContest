#include"contestant_manipulation.h"

 


void randomContestantGenerator (Contestants& contestant, const int& IDcounter) 
{   
    string femaleNames[60] = {
        "Mary", "Patricia", "Linda", "Barbara", "Elizabeth", "Jennifer", "Maria", "Susan", "Margaret", "Dorothy",
        "Lisa", "Nancy", "Karen", "Betty", "Helen", "Sandra", "Donna", "Carol", "Ruth", "Sharon",
        "Michelle", "Laura", "Sarah", "Kimberly", "Deborah", "Jessica", "Shirley", "Cynthia", "Angela", "Melissa",
        "Brenda", "Amy", "Anna", "Rebecca", "Virginia", "Kathleen", "Pamela", "Martha", "Debra", "Amanda",
        "Stephanie", "Carolyn", "Christine", "Marie", "Janet", "Catherine", "Frances", "Ann", "Joyce", "Diane",
        "Alice", "Julie", "Heather", "Teresa", "Doris", "Gloria", "Evelyn", "Jean", "Cheryl", "Mildred"
    };

    string maleNames[60] = {
        "James", "John", "Robert", "Michael", "William", "David", "Richard", "Joseph", "Thomas", "Charles",
        "Christopher", "Daniel", "Matthew", "Anthony", "Donald", "Mark", "Paul", "Steven", "Andrew", "Kenneth",
        "Joshua", "Kevin", "Brian", "George", "Edward", "Ronald", "Timothy", "Jason", "Jeffrey", "Ryan",
        "Jacob", "Gary", "Nicholas", "Eric", "Jonathan", "Stephen", "Larry", "Justin", "Scott", "Brandon",
        "Benjamin", "Samuel", "Frank", "Gregory", "Raymond", "Alexander", "Patrick", "Jack", "Dennis", "Jerry",
        "Tyler", "Aaron", "Jose", "Adam", "Henry", "Nathan", "Douglas", "Zachary", "Peter", "Kyle"
    };

    bool isObjectUsed = true;
    string name;
    int age = rand() % 85 + 15;
    bool isWoman = rand() % 2;
    double hipCirc;
    double shoulderCirc;
    double calfCirc;
    double neckCirc;
    if (isWoman){
        name = femaleNames[rand() % 60];
        hipCirc = (rand() % 600)/100.0  + 31;
        shoulderCirc = (rand() % 1600)/100.0  + 95;
        calfCirc = (rand() % 2100)/100.0  + 95;
        neckCirc = (rand() % 700)/100.0  + 33;
    } else {
        name = maleNames[rand() % 60];
        hipCirc = (rand() % 800)/100.0  + 36;
        shoulderCirc = (rand() % 2100)/100.0  + 110;
        calfCirc = (rand() % 1600)/100.0  + 90;
        neckCirc = (rand() % 800)/100.0  + 34;
    }
    contestant = {IDcounter, isObjectUsed, name, age, isWoman, hipCirc, shoulderCirc, calfCirc, neckCirc};
    
}


void printContestant(Contestants contestant[], int index){

    deBugInfo("Index: " << index << "   ");
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

    for (int n = afterIndex; n < MAXCONTESTANTS; n++) {
        int cont = contestant[n].isObjectUsed;
        if (cont == searchingFor) {
            deBugInfo("SYSTEM: Found match at index: "<< n << endl);
            return n;
        }
    }
    //deBugInfo("SYSTEM: No empty spaces"<< endl);
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

int searchContestantName(Contestants contestant[], string targetName, int startIdx) {
    //EXPLANATION: Goes through the contestant array to find matching name. 
    //Skips over objects with isObjectUsed = false;

    for (int i = startIdx; i < MAXCONTESTANTS; i++) {
        if (!contestant[i].isObjectUsed) continue; // skips if contestant spot is not in use


        if (contestant[i].name == targetName) {
             return i;
        }
    }
    return -1;
}

//TODO: find a way to do this with not sleep deprived brain
// int findContestantByAge(Contestants contestant[], int searchingFor , int afterIndex){
//     for (int n = afterIndex; n < MAXCONTESTANTS; n++) {
//         int cont = contestant[n].age;

//         if (cont == searchingFor) {
//             deBugInfo("SYSTEM: Found age at index: "<< n << endl);
//             return n;
//         }

//     }
//     //deBugInfo("SYSTEM: No empty spaces"<< endl);
//     return -1;
// }