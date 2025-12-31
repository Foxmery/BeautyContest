/// @file exit_logic.cpp
/// @brief Handles the exit sequence and prompts to save unsaved changes.

#pragma once
#include <iostream>
#include <string>

#include "../../utils/visual_enhancement.h" 
#include "../../utils/debug.h"
#include "../../utils/settings.h"
#include "../../utils/contestant.h"
#include "../../utils/file_manager/file_manager.h"

using namespace std;

/// @brief Logic for exit menu Ask if you want tos ave unsaved changes
/// @param contestant What you want to save
/// @param savedChanages Whether changes were saved or not
/// @return Whether to stop the program or to continue it
bool askUserExit(Contestants contestant[], bool savedChanages);