#pragma once
#include <iostream>
#include <string>

#include "../utils/contestant.h"
#include "../utils/debug.h"
#include "../utils/settings.h"

using namespace std;

//CONTESTANTS ADDERS

/** @brief Generates a random contestant values.
 * *  Has female and Male names that are picked randomly according to gender. 
 * Other parameters as hipCirc, shoulderCirc, calfCirc, neckCirc are picked between ranges according to gender.
 * * @param contestant  The array of all contestants.
 * @param IDcounter     The ID the contestant should get.
 */
void randomContestantGenerator (Contestants& contestant, const int& ID);


//SLOT SEARCHING

/// @brief Wrapper Function to find next free slot in contestants starting from startIdx
/// @param contestant   The array of all contestants.
/// @param startIdx     The index to start searching from.
/// @return int         The index of next Free slot, or -1 if not found.  
int getNextFreeSlot(Contestants contestant[], int startIdx = 0);

/// @brief Wrapper Function to find next used slot in contestants starting from startIdx
/// @param contestant   The array of all contestants.
/// @param startIdx     The index to start searching from.
/// @return int         The index of next used slot, or -1 if not found. 
int getNextUsedSlot(Contestants contestant[], int startIdx = 0);


//CONTESTANT PRINTER

/// @brief Prints out contestant in one single line(has debug that shows the index)
/// @param contestant   The array of all contestants.
/// @param index        The index of the contestant.(if deBug == 1 prints out the index too)
void printContestant(Contestants contestant[], int index);

//LATER: Table(maybe separate function)