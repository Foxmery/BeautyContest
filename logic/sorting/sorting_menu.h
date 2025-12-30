#pragma once
#include <iostream>
#include <string>


#include "../contestants_manipulation/contestants_printers.h"
#include "../contestants_manipulation/contestants_searchers.h"
#include "../contestants_manipulation/contestants_manager.h"
#include "../contestants_manipulation/contestans_sorters.h"



#include "../../block_mangment.h"

#include "../../utils/settings.h"
#include "../../utils/contestant.h"

using namespace std;

/// @brief Manages the logic for the sorting menu
/// @param contestant Contestants to sort
/// @param menuChoice what user wants to sort
/// @param madeChanges If user made any change to the inputed contestants
void sortingMenu (Contestants contestant[], int& menuChoice, bool& madeChanges);


