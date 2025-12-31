#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

#include "../contestants_manipulation/contestants_searchers.h"

#include "../../utils/visual_enhancement.h"
#include "../../utils/settings.h"
#include "../../utils/contestant.h"
#include "../../utils/cin_validators.h"
#include "../../utils/utils.h"

/// @brief Logic for contestants menu. Has a did you mean feature when searching for names
/// @param contestant Where you want to search
/// @param menuChoice What user wants to search
void searchShowContestantsMenu(Contestants contestant[], int& menuChoice);