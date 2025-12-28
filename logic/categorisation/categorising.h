#pragma once
#include <iostream>
// #include <>

using namespace std;

#include "../../utils/contestant.h"
#include "../../utils/debug.h"
#include "../../utils/settings.h"

#include "../../block_mangment.h"

#include "../contestants_manipulation/contestants_manager.h"
#include "../contestants_manipulation/contestants_searchers.h"

/// @brief 
/// @param contestant 
/// @param category14_16 
/// @param category17_19 
/// @param category20_22 
/// @param category23_25 
void categorizeContestantsByAge(Contestants contestant[], Contestants category14_16[], Contestants category17_19[], Contestants category20_22[], Contestants category23_25[]);