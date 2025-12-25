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

void additionOfContestantsMenu(Contestants contestant[], int& leftSpaces, int& IDcounter, int& menuChoice);

