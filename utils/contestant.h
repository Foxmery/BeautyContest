#pragma once
#include <string>
#include "settings.h"

struct Contestants {
    int ID;
    bool isObjectUsed = false;
    char name[MAXNAMECHARS]; 
    int age = 0;
    bool isWoman = false;
    double hipCirc = 0.0;
    double shoulderCirc = 0.0;
    double calfCirc = 0.0;
    double neckCirc = 0.0;
};