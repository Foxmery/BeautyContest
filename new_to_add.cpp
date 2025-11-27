// //FUNCTION TO ADD


// #define NOMINMAX
// #include <cstdint> //defiens integer types regardless of os
// #include <iostream>
// #include <string>
// #include <cstdlib> // for system("cls"); setting
// #include <limits>
// #include <algorithm>

// using namespace std;


// const int MAXCONTESTANTS = 30;
// const bool DEBUGMODE = 0;

// struct Contestants {
//     int ID;
//     bool isObjectUsed = 0;
//     string name; 
//     int age;
//     bool isWoman = 1;
//     double hipCirc;
//     double shoulderCirc;
//     double calfCirc;
//     double neckCirc;
// };

// #define deBugInfo(message) if (DEBUGMODE) { cout << message; } // macro

// int findFreeIndex(Contestants contestant[], int searchingFor, int afterIndex) {
//     //Outputs the first contestant it sees depending on if you want the contestant spot to be free or used
//     //It searches after a curtain index so after putting it in a cycle it doesn`t output the same contestant
//     for (int n = afterIndex; n < MAXCONTESTANTS; n++) {
//         int cont = contestant[n].isObjectUsed;
//         // cout << cont << endl;n
//         if (cont == searchingFor) {
//             // cout << "yep" << endl;
//             deBugInfo("SYSTEM: Found free place at index: "<< n);

//             return n;
//         }

//     }
//     // cout << "No empty spaces" << endl;
//     return -1;
// }



// int main(){
// srand(time(0));
// Contestants contestant[MAXCONTESTANTS];

// //TODO: Implement new function:easyContInit
// //TODO: Remove extra spaces in print contestant 3?4 line
// //TODO: Add defalult values in struct Contestants

// for(int i = 0; i < 5;i++){
//     contestant[i] = randomContestantGenerator(i);
// } 
//                 cout << "------All contestants------" << endl;
                
//                 for(int i = 0; i < MAXCONTESTANTS; i++){

//                     int validIndex = findFreeIndex(contestant, 1, i);
//                     i = validIndex;
//                                        //When findFreeIndex is done it outputs -1. This "if" breaks when detects -1;
//                     if (validIndex == -1) {
//                         cout << endl;
//                         break;
//                     }
                    
//                     printContestant(contestant, validIndex);
//                 }
// //                break;

// /*                int i = 0;
//                 int lastIndex = 0;

//                 do{
                    
//                     //if next contestant is not in use remoove stop the program
//                     if (contestant[i+1].isObjectUsed == 0){
//                         break;
//                     }
//                     if(contestant[i].age > contestant[i+1].age){
//                         //swap contestant places
//                         Contestants placeHolder = contestant[i];
//                         contestant[i] = contestant[i+1];
//                         contestant[i+1] = placeHolder;

//                     } else if (i == 0){
//                         lastIndex++;
//                         i = lastIndex;

//                     } else {
//                         i--;

//                     }

//                 } while(i != MAXCONTESTANTS);
//                 */
// }
                
                 