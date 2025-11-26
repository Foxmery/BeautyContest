#include"contestant_manipulation.h"

void randomContestantGenerator (Contestants& contestant, int ID) 
{   
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
    //TODO: make names for men and woman(use gemini)
    bool isObjectUsed = true;
    string name = names[rand() % 60];
    int age = rand() % 85 + 15;
    bool isWoman = rand() % 2;
    double hipCirc;
    double shoulderCirc;
    double calfCirc;
    double neckCirc;
    if (isWoman){
       hipCirc = (rand() % 600)/100.0  + 31;
       shoulderCirc = (rand() % 1600)/100.0  + 95;
       calfCirc = (rand() % 2100)/100.0  + 95;
       neckCirc = (rand() % 700)/100.0  + 33;
    }else{
       hipCirc = (rand() % 800)/100.0  + 36;
       shoulderCirc = (rand() % 2100)/100.0  + 110;
       calfCirc = (rand() % 1600)/100.0  + 90;
       neckCirc = (rand() % 800)/100.0  + 34;
    }

}    