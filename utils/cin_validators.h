#pragma once
#include <iostream>
#include <string>
#include <limits>

#include "settings.h"
#include "debug.h"

void resetCin();
bool checkCin();
int cinCheckInt(const string& message);
double cinCheckDouble(const string& message);

/// @brief Checks if you wrote 
/// @param message 
/// @return 
bool cinCheckIsWoman(const string& message);