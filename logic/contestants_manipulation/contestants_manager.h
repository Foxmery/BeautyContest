#pragma once

#include "contestants_searchers.h"

#include "../../utils/contestant.h"
#include "../../utils/debug.h"
using namespace std;


/// @brief Swaps contestant places with given indexes
/// @param contestant Where you want the swaping to be done
/// @param Findex First contestant to swap
/// @param Sindex Second contestant to swap
void swapContestantPlaces(Contestants contestant[], int FIndex, int SIndex);

/// @brief Duplicates info from one contestants struct to other
/// @param from where you get info to dupe
/// @param to location to dupe on
void dupeContestantInfo (Contestants from[], Contestants to[]);