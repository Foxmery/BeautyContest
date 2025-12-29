#pragma once
#include <iostream>  
#include <fstream>   
#include <cstring>   
#include <iomanip>   

using namespace std;

#include "../../logic/contestants_manipulation/contestants_manager.h"
#include "../../utils/settings.h"
#include "../../utils/contestant.h"


/// @brief Saves file of contestnats
/// @param contestant Contestants to save
/// @return If it was successful
bool saveToFile(Contestants contestant[], string filePath);

/// @brief Loads file of contestnats
/// @param contestant Contestants to load
/// @return If it was successful
bool loadFromFile(Contestants contestant[], string filePath);

/// @brief Remove all the data in a file
/// @param filePath File you want to scrape 
/// @return If it was successful
bool removeFileData(string filePath);


