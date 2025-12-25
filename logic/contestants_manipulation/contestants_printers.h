#pragma once


#include "../../utils/contestant.h"
#include "../../utils/debug.h"
using namespace std;


/// @brief Prints out contestant in one single line(has debug that shows the index)
/// @param contestant   The array of all contestants.
/// @param index        The index of the contestant.(if deBug == 1 prints out the index too)
void printContestant(Contestants contestant[], int index);