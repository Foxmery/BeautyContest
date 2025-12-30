#pragma once
#include <iostream>
#include <string>
#include <cstring>

#include "../../utils/contestant.h"
#include "../../utils/debug.h"
#include "../../utils/settings.h"
#include "../../utils/cin_validators.h"

using namespace std;


/** @brief Generates a random contestant values.
 * *  Has female and Male names that are picked randomly according to gender. 
 * Other parameters as hipCirc, shoulderCirc, calfCirc, neckCirc are picked between ranges according to gender.
 * * @param contestant  The array of all contestants.
 * @param IDcounter     The ID the contestant should get.
 */
void randomContestantGenerator (Contestants& contestant, const int& ID);


/// @brief Puts infor from user to contestant
/// @param contestant the contestant that needs manipulation
/// @param IDcounter the last id issued
void readSingleContestant(Contestants& contestant, const int& IDcounter);
