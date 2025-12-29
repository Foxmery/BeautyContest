#pragma once
#include <iostream>
#include <string>

using namespace std;

#include "../contestants_manipulation/contestants_generators.h"
#include "../contestants_manipulation/contestants_searchers.h"

#include "../../utils/visual_enhancement.h"
#include "../../utils/settings.h"
#include "../../utils/contestant.h"
#include "../../utils/cin_validators.h"
#include "../../utils/utils.h"


/// @brief Logic for contestnat menu
/// @param contestant Contestants struct you want ot change
/// @param leftSpaces Spaces left with tag isObjectUsed = false;
/// @param IDcounter From what id to start
/// @param menuChoice What to do
void additionOfContestantsMenu(Contestants contestant[], int& leftSpaces, int& IDcounter, int& menuChoice);

