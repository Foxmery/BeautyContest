#pragma once
#include <iostream>
#include <string>

#include "../contestants_manipulation/contestants_printers.h"

#include "../../block_mangment.h"

#include "../../utils/settings.h"
#include "../../utils/contestant.h"

/// @brief Manages logic for the printing the contestants. Outputs a message if category or winners weren't defined yet
/// @param contestant Contestants to be printed
/// @param winners Winners to be printed
/// @param category14_16 First age group to be printed
/// @param category17_19 Secund age group to be printed
/// @param category20_22 Third age group to be printed
/// @param category23_25 Forth age group to be printed
/// @param menuChoice What user wants to print
/// @param winnersDecided Are winners decided to be printed
/// @param madeCategories Are categories made to be printed
void showContestantsMenu(Contestants contestant[], Contestants winners[], Contestants category14_16[], Contestants category17_19[], Contestants category20_22[], Contestants category23_25[], int menuChoice, bool winnersDecided, bool madeCategories); 
