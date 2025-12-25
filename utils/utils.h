#pragma once
#include <string>

#include "debug.h"

using namespace std;

string toLowerString(string s);

/// @brief Gives real size of array searching for a terminator
/// @param arr char array you wnat to search in
/// @param sizeArr sie fo set array
/// @param end where to stop counting
/// @return real size of array
int getRealSizeOfCharArray(char arr[], int sizeArr, char end = '\0');

/// @brief Gives
/// @param first 
/// @param second 
/// @param sizeFirst 
/// @param sizeSecond 
/// @return 
int countDifferencesBetweenCharArrays(char first[], char second[], int sizeFirst, int sizeSecond);
//TODO:fix this when two arrays of that are with diffrent size we get the largest with the first command max but what if the actualSize of the second is not that large... index out of bound error?