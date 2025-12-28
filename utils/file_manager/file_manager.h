#pragma once
#include <iostream>  
#include <fstream>   
#include <cstring>   
#include <iomanip>   

using namespace std;

#include "../../utils/settings.h"
#include "../../utils/contestant.h"


/// @brief Saves file of contestnats
/// @param contestant Contestants to save
void saveToFile(Contestants contestant[]);

/// @brief Loads file of contestnats
/// @param contestant Contestants to load
void loadFromFile(Contestants contestant[]);

