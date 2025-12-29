#include"contestants_generators.h"

 void randomContestantGenerator (Contestants& contestant, const int& IDcounter) 
{   
    

    int ageVariation = 11;
    int ageOffSet = 15;

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

    bool isObjectUsed = rand() % 2;
    char name[MAXNAMECHARS];
    int age = rand() % ageVariation + ageOffSet;
    bool isWoman = rand() % 2;
    double hipCirc;
    double shoulderCirc;
    double calfCirc;
    double neckCirc;

    const int OFFSET = 12; // so they can enter in all the winner brackets


// Measurement,Women (Range),Men (Range)
// Hip Circ (H),90 - 105 cm,90 - 105 cm
// Shoulder  (S)95 - 110 cm,110 - 125 cm
// Calf Circ (C),32 - 40 cm,35 - 42 cm
// Neck Circ (N),30 - 35 cm,37 - 42 cm
// thank you gemini

    string tempName;
    if (isWoman){
        tempName = femaleNames[rand() % 60];
        hipCirc      = (rand() % 1500) / 100.0 + 90.0 + OFFSET;  
        shoulderCirc = (rand() % 1500) / 100.0 + 95.0;  
        calfCirc     = (rand() % 800)  / 100.0 + 32.0 ;  
        neckCirc     = (rand() % 500)  / 100.0 + 30.0;
    } else {
        tempName = maleNames[rand() % 60];
        hipCirc      = (rand() % 1500) / 100.0 + 90.0 + OFFSET;  
        shoulderCirc = (rand() % 1500) / 100.0 + 110.0; 
        calfCirc     = (rand() % 700)  / 100.0 + 35.0 ;  
        neckCirc     = (rand() % 500)  / 100.0 + 37.0;
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
    contestant.points = hipCirc / (shoulderCirc + neckCirc + calfCirc);
}

void readSingleContestant(Contestants& contestant, const int& IDcounter){

    contestant.ID = IDcounter;
    contestant.isObjectUsed = true;

    cout << "Enter name: ";
    cin.getline(contestant.name, MAXNAMECHARS);

    contestant.age = cinCheckInt("Enter age: ");

    contestant.isWoman = cinCheckIsWoman("Enter gender (m/f): ");

    contestant.hipCirc = cinCheckDouble("Enter hip circumference (cm): ");

    contestant.shoulderCirc = cinCheckDouble("Enter shoulder circumference (cm): ");

    contestant.neckCirc = cinCheckDouble("Enter neck circumference (cm): ");

    contestant.calfCirc = cinCheckDouble("Enter calf circumference (cm): ");

    contestant.points = contestant.hipCirc / (contestant.shoulderCirc + contestant.neckCirc + contestant.calfCirc);
}