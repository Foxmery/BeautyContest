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


int getRealSizeOfCharArray(char arr[], int sizeArr, char end = '\0'){
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