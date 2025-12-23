#pragma once
#include <iostream>
#include <string>

#include "settings.h"

using namespace std;

#define deBugInfo(message) if (DEBUGMODE) { cout << message; } // macro
void deBugStringArray (string s[],int size);

// 
// void deBugInfo(const sting& message){
//     if (DEBUGMODE) cout << message << endl;
// } // does not work