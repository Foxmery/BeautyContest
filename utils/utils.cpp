#include "utils.h"


int getRealSizeOfCharArray(char arr[], int sizeArr, char end){
    int realSize = 0;
    bool endOfArray = 0;
    for(int i = 0; i < sizeArr - 1 && !endOfArray; i++){
        realSize++;
        endOfArray = arr[i + 1] == end;
    }
    return realSize; 
}


int countDifferencesBetweenCharArrays(char first[], char second[], int sizeFirst, int sizeSecond){

    int realSizeFirst = getRealSizeOfCharArray(first, sizeFirst);
    int realSizeSecond = getRealSizeOfCharArray(second, sizeSecond);

    int lastToCheck = max(realSizeFirst, realSizeSecond);
    int minSize = min(sizeFirst, sizeSecond);
    if(lastToCheck > minSize){
        lastToCheck = minSize;
        deBugInfo("WARNING - countDifferencesBetweenCharArrays: Size of array is too small!" << endl);
    }

    deBugInfo("SYSTEM: lastToCheck: " << lastToCheck << endl);

    int differences = 0;

    for(int i  = 0; i < lastToCheck ; i++ ){
        bool different = tolower(first[i]) != tolower(second[i]);
        if(different) differences++;
        deBugInfo("F: " << first[i] << " S: " << second[i] << " D? " << different << endl);
        //deBugInfo("SYSTEM: Comparing " << tolower(first[i]) << " and " << tolower(second[i]) << " | " << "nowDiff: " << differences);
    }
    deBugInfo("Total differences: " << differences <<" | Compared: " << first << " and " << second << endl << endl);
    return differences;
}


/// @brief Makes all capital chars of a string into small
/// @param s String you want to lower
/// @return The lowered string
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
