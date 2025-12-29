#pragma once
#include <iostream>

using namespace std;

#include "../../utils/file_manager/file_manager.h"
#include "../../utils/visual_enhancement.h"
#include "../../utils/debug.h"
#include "../contestants_manipulation/contestants_manager.h"


/// @brief 
/// @param contestant 
/// @param menuChoice 
void fileManagerMenu(Contestants contestant[], int& menuChoice, bool& savedChanages, bool& madeCategories, bool& winnersDecided, int& IDcounter, int& leftSpaces);