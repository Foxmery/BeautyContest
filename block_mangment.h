#pragma once
#include <iostream>
#include <string>
#include <cmath>

#include "utils/settings.h"
#include "utils/visual_enhancement.h"
#include "utils/debug.h"

using namespace std;


//MAIN MENU/S

/// @brief Outputs Main Menu
/// @param winnersDecided If winners were decided
/// @param madeCategories If categories were made
void mainMenuText(bool winnersDecided = false, bool madeCategories = false);


//SUBMENUS

/// @brief Outputs the search submenu.
void searchMenuText();

/// @brief Outputs the sort submenu.
void sortMenuText();

/// @brief Outputs the winners submenu.
void winnersMenuText();

/// @brief Outputs the addition of contestants submenu.
void addingContestantsMenuText();

/// @brief Outputs the winners submenu.
void winnersMenuText();

/// @brief Outputs the file submenu 
void fileMenuText();


//MENUS HELPER/S

/** @brief Helper for printing out beautiful filler around the title in the center.
 * * Puts the title in the center and fills the empty space with filler.
 * Accounts when title cant centered and puts one extra filler at end.
 * If title is too big: debug warning alarms and puts only one filler at both ends.
 * * @param title   The message you want to be seen.
 * @param width     What space are working with.
 * @param filler    The char that will be around the title.
 */
void titlePrinter(string title, int width, char filler);
