#pragma once
#include <iostream>
#include <string>

#include "settings.h"

using namespace std;

/// @brief macro i used to debug my code easily
#define deBugInfo(message) if (DEBUGMODE) { cout << message; } 

/// @brief Debugger that prints full array of strings
/// @param s What assay you want to print
/// @param size The number of string in the array
void deBugStringArray (string s[], int size);