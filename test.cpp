#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib> // for system("cls"); setting
#include <vector>
using namespace std;

string toLowerString(string &str);

int main(){
    string str = "BannaNa";
    toLowerString(str);
    cout << str;
}

string toLowerString(string &str){
    vector<char> lettersIn;
    vector<char> lettersOut;
    
    for (int i = 0; i < size(str); i++)
    {
        lettersIn[i] = str[i];
    }

    for(char letter : lettersIn){
        char newLetter;
        if (letter >= 'A' && letter <= 'Z'){
            newLetter = letter + 32;
        } else {
            newLetter = letter;//finit the vlaidation here
            //TODO: figure out why this cant run in cpp.sh.com
            
            //TODO: figure out how to concatenate the chars to string
        }
    }

    
}