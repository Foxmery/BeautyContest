#pragma once
#include <iostream>
#include <string>

using namespace std;

#define deBugInfo(message) if (DEBUGMODE) { cout << message << endl; } // macro

// 
// void deBugInfo(const sting& message){
//     if (DEBUGMODE) cout << message << endl;
// } // does not work