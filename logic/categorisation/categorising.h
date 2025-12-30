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

/// @brief Categorizes every contestant 
/// @param contestant From where to get the contestants
/// @param category14_16 First age group
/// @param category17_19 Secund age group
/// @param category20_22 Third age group
/// @param category23_25 Forth age group
void categorizeContestantsByAge(Contestants contestant[], Contestants category14_16[], Contestants category17_19[], Contestants category20_22[], Contestants category23_25[]);