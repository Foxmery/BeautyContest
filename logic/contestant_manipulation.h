#pragma once
#include <iostream>
#include <string>

#include "../utils/contestant.h"
#include "../utils/debug.h"
#include "../utils/settings.h"

using namespace std;

void randomContestantGenerator (Contestants& contestant, const int& ID);
Contestants easyContInit(const int& ID,const bool& isObjectUsed,const string& name,const int& age,const bool& isWoman,const double& hipCirc,const double& shoulderCirc,const double& calfCirc,const double& neckCirc);
int findFreeIndex(Contestants contestant[], int searchingFor = 0, int afterIndex = 0);
void printContestant(Contestants contestant[], int index);