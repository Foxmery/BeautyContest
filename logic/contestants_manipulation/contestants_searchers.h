#pragma once
#include <string>
#include <cstring>

#include "contestants_printers.h"

#include "../../utils/contestant.h"
#include "../../utils/debug.h"
#include "../../utils/settings.h"
#include "../../utils/utils.h"
using namespace std;



/// @brief Wrapper Function to find next free slot in contestants starting from startIdx
/// @param contestant   The array of all contestants.
/// @param startIdx     The index to start searching from.
int getNextFreeSlot(Contestants contestant[], int startIdx = 0);

/// @brief Wrapper Function to find next used slot in contestants starting from startIdx
/// @param contestant   The array of all contestants.
/// @param startIdx     The index to start searching from.
int getNextUsedSlot(Contestants contestant[], int startIdx = 0);

/// @brief Prints out
/// @param contestant The array of all contestants.
/// @param ID ID to delete
/// @return If it was successful
bool deleteContestantsByID(Contestants contestant[],const int& ID);

/// @brief Gives out the contestant with largest ID
/// @param contestant The array of all contestants.
/// @return biggestID
int biggestContestantID (Contestants contestant[]);

/// @brief Prints out contestants with given age and if it found someone
/// @param contestant The array of all contestants.
/// @param age age to search for
/// @return if it found a match
bool searchContestantsByAge(Contestants contestant[],const int& age);

/// @brief Prints out contestants with given gender
/// @param contestant The array of all contestants.
/// @param isWoman this is the given gender
/// @return if it found a match
bool searchContestantsByWoman(Contestants contestant[],const bool& isWoman);

/// @brief Searches contestnats by name and gives possible names
/// @param contestant The array of all contestants.
/// @param nameToSearch what name to search
/// @param sizeToSearch size of name
/// @param didYouMeanNames possible names
/// @return if person was found
bool searchContestantByName(Contestants contestant[], char nameToSearch[], int sizeToSearch, string didYouMeanNames[]);

