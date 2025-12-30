#pragma once


#include "contestants_searchers.h"

#include "../../block_mangment.h"

#include "../../utils/contestant.h"
#include "../../utils/debug.h"

using namespace std;


/// @brief Prints out contestant in one single line(has debug that shows the index)
/// @param contestant   The array of all contestants.
/// @param index        The index of the contestant.(if deBug == 1 prints out the index too)
void printContestant(Contestants contestant[], int index);

/// @brief Prints out all contestants with isUsed = 1
/// @param contestant Array of contestnats
void printAllContestants(Contestants contestant[]);

/// @brief Prints all contestnats but little bit more formatted
/// @param contestant Contestant array
/// @param title Title of the table 
void printAllContestantsFormatted(Contestants contestant[], string title);