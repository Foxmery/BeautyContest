#pragma once
#include <string>
using namespace std;

string toLowerString(string s);

/// @brief Gives real size of array searching for a terminator
/// @param arr char array you wnat to search in
/// @param sizeArr sie fo set array
/// @param end where to stop counting
/// @return real size of array
int getRealSizeOfCharArray(char arr[], int sizeArr, char end = '\0');