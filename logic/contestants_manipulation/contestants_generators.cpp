#include"contestants_generators.h"

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
    char name[MAXNAMECHARS];
    int age = rand() % 85 + 15;
    bool isWoman = rand() % 2;
    double hipCirc;
    double shoulderCirc;
    double calfCirc;
    double neckCirc;

    string tempName;
    if (isWoman){
        tempName = femaleNames[rand() % 60];
        hipCirc = (rand() % 600)/100.0  + 31;
        shoulderCirc = (rand() % 1600)/100.0  + 95;
        calfCirc = (rand() % 2100)/100.0  + 95;
        neckCirc = (rand() % 700)/100.0  + 33;
    } else {
        tempName = maleNames[rand() % 60];
        hipCirc = (rand() % 800)/100.0  + 36;
        shoulderCirc = (rand() % 2100)/100.0  + 110;
        calfCirc = (rand() % 1600)/100.0  + 90;
        neckCirc = (rand() % 800)/100.0  + 34;
    }

    

    contestant.ID = IDcounter;
    contestant.isObjectUsed = true;

    strncpy(contestant.name, tempName.c_str(), MAXNAMECHARS - 1);
    contestant.name[tempName.length()] = '\0';

    contestant.age = age;
    contestant.isWoman = isWoman;
    contestant.hipCirc = hipCirc;
    contestant.shoulderCirc = shoulderCirc;
    contestant.calfCirc = calfCirc;
    contestant.neckCirc = neckCirc;
}

void readSingleContestant(Contestants& contestant, const int& IDcounter){

    contestant.ID = IDcounter;
    contestant.isObjectUsed = true;

    cout << "Enter name: ";
    cin >> contestant.name;

    contestant.age = cinCheckInt("Enter age: ");

    contestant.isWoman = cinCheckIsWoman("Enter gender (m/f): ");

    contestant.hipCirc = cinCheckDouble("Enter hip circumference (cm): ");

    contestant.shoulderCirc = cinCheckDouble("Enter shoulder circumference (cm): ");

    contestant.neckCirc = cinCheckDouble("Enter neck circumference (cm): ");

    contestant.calfCirc = cinCheckDouble("Enter calf circumference (cm): ");
}