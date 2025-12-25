#include "utils.h"

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



int getRealSizeOfCharArray(char arr[], int sizeArr, char end){
    int realSize = 0;
    bool endOfArray = 0;
    for(int i = 0; i < sizeArr - 1 && !endOfArray; i++){
        realSize++;
        endOfArray = arr[i + 1] == end;
        // cout << "Next: " << arr[i + 1] << endl;
        // cout << "EndOfArr: " << endOfArray << endl;
    }
    return realSize; 
}


int countDifferencesBetweenCharArrays(char first[], char second[], int sizeFirst, int sizeSecond){
    int lastToCheck = max(sizeFirst, sizeSecond);
    deBugInfo("SYSTEM: lastToCheck: " << lastToCheck << endl);

    int diffrences = 0;

    for(int i  = 0; i < lastToCheck ; i++ ){
        bool diffrent = tolower(first[i]) != tolower(second[i]);
        if(diffrent) diffrences++;
        deBugInfo("F: " << first[i] << " S: " << second[i] << " D? " << diffrent << endl);
        //deBugInfo("SYSTEM: Comparing " << tolower(first[i]) << " and " << tolower(second[i]) << " | " << "nowDiff: " << diffrences);
    }
    deBugInfo("Total differences: " << diffrences <<" | Compared: " << first << " and " << second << endl << endl);
    return diffrences;
}