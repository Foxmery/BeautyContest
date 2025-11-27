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
    }else{
        name = maleNames[rand() % 60];
        hipCirc = (rand() % 800)/100.0  + 36;
        shoulderCirc = (rand() % 2100)/100.0  + 110;
        calfCirc = (rand() % 1600)/100.0  + 90;
        neckCirc = (rand() % 800)/100.0  + 34;
    }

    contestant = easyContInit(IDcounter,isObjectUsed,name,age,isWoman,hipCirc,shoulderCirc,calfCirc,neckCirc);

}

Contestants easyContInit(const int& ID,const bool& isObjectUsed,const string& name,const int& age,const bool& isWoman,const double& hipCirc,const double& shoulderCirc,const double& calfCirc,const double& neckCirc){
    //EXPLANATION: Adding new contestants is easier.
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
    
    
//TODO: Implement new function:easyContInit
//TODO: Add default values in struct Contestants
//TODO: Remove while trues

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

int findFreeIndex(Contestants contestant[], int searchingFor , int afterIndex) {
    //EXPLANATION: Outputs the first contestant it sees depending on if you want the contestant spot to be free or used
    //It searches after a curtain index so after putting it in a cycle it doesn`t output the same contestant
    for (int n = afterIndex; n < MAXCONTESTANTS; n++) {
        int cont = contestant[n].isObjectUsed;
        if (cont == searchingFor) {
            deBugInfo("SYSTEM: Found free place at index: "<< n << endl);

            return n;
        }

    }
    //deBugInfo("SYSTEM: No empty spaces"<< endl);
    return -1;
}