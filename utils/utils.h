#pragma once
#include <string>

#include "debug.h"

using namespace std;


/// @brief Number of chars in array before a terminator
/// @param arr char array you what to search in
/// @param sizeArr size fo set array
/// @param end where to stop counting
/// @return real size of array
int getRealSizeOfCharArray(char arr[], int sizeArr, char end = '\0');

/// @brief Gives differences between two char array. 
/// Has protection against putting two unequal sized arrays
/// @param first The first array
/// @param second The second array
/// @param sizeFirst The size of the first array 
/// @param sizeSecond The size of the second array
/// @return Count of differences between two equal size arrays
int countDifferencesBetweenCharArrays(char first[], char second[], int sizeFirst, int sizeSecond);


