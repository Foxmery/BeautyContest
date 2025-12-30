#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;


// #include "../contestants_manipulation/contestants_manager.h"
#include "../contestants_manipulation/contestants_searchers.h"

#include "../../utils/visual_enhancement.h"
#include "../../utils/settings.h"
#include "../../utils/contestant.h"
#include "../../utils/cin_validators.h"
#include "../../utils/utils.h"

/// @brief 
/// @param contestant 
/// @param menuChoice 
void searchShowContestantsMenu(Contestants contestant[], int& menuChoice);