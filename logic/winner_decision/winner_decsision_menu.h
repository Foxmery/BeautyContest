#pragma once
#include <iostream>

using namespace std;

#include "../contestants_manipulation/contestants_printers.h"
#include "../contestants_manipulation/contestans_sorters.h"


#include "../../utils/cin_validators.h"
#include "../../utils/debug.h"
#include "../../utils/contestant.h"

/// @brief Deciding who are the winners losers and real winners
/// @param contestant Contestants to decide form
/// @param winners Where winners are saved for latter use
void winnerDecider (Contestants contestant[], Contestants winners[]);


