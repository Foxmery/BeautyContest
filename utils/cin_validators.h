#pragma once
#include <iostream>
#include <string>
#include <limits>

#include "settings.h"
#include "debug.h"


/// @brief Resets cin of any junk till new line
void resetCin();

/// @brief Check if user gave number, if not asks again for input
/// @param message What to ask the user to input
/// @return Integer value of users input
int cinCheckInt(const string& message);

/// @brief Check if user gave number, if not asks again for input
/// @param message What to ask the user to input
/// @return Double value of users input
double cinCheckDouble(const string& message);

/// @brief Checks if you user wrote  m or f 
/// @param message Message making user input data
/// @return Bool value of what user inputted m - false, f - true
bool cinCheckIsWoman(const string& message);