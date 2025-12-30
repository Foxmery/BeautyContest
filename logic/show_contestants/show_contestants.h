#pragma once
#include <iostream>
#include <string>

#include "../contestants_manipulation/contestants_printers.h"

#include "../../block_mangment.h"

#include "../../utils/settings.h"
#include "../../utils/contestant.h"

/// @brief Prints all contestants according to user
/// @param contestant 
/// @param winners If 
/// @param category14_16 
/// @param category17_19 
/// @param category20_22 
/// @param category23_25 
/// @param menuChoice 
void showContestantsMenu(Contestants contestant[], Contestants winners[], Contestants category14_16[], Contestants category17_19[], Contestants category20_22[], Contestants category23_25[], int menuChoice, bool winnersDecided, bool madeCategories); 
