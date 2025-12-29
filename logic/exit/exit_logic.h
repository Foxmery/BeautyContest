#pragma once
#include <iostream>
#include <string>

#include "../../utils/visual_enhancement.h" 
#include "../../utils/debug.h"
#include "../../utils/settings.h"
#include "../../utils/contestant.h"
#include "../../utils/file_manager/file_manager.h"

using namespace std;

/// @brief Logic for exit menu
/// @param contestant From where you wa
/// @param savedChanages  
/// @return 
bool askUserExit(Contestants contestant[], bool savedChanages);