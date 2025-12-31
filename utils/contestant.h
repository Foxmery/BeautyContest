/// @file contestant.h
/// @brief Defines the Contestants structure and related data fields.

#pragma once
#include <string>
#include "settings.h"

/// @brief A structure to hold all details for a single beauty contestant.
struct Contestants {

    /// @brief Unique identifier
    int ID;          

    /// @brief Identifier for active places in the strcut array. True -> active, false -> inactive
    bool isObjectUsed = false;

    /// @brief Contestant's full name
    char name[MAXNAMECHARS]; 

    /// @brief Contestant's age
    int age = 0;

    /// @brief Identifier for gender. true -> woman, false -> man
    bool isWoman = false;

    /// @brief Contestant's hip circumference 
    double hipCirc = 0.0;

    /// @brief Contestant's shoulder circumference 
    double shoulderCirc = 0.0;

    /// @brief Contestant's calf circumference 
    double calfCirc = 0.0;
    
    /// @brief Contestant's neck circumference 
    double neckCirc = 0.0;

    /// @brief Contestant's points
    double points = 0.0;
};