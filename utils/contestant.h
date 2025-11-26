#pragma once
#include <string>

struct Contestants {
    int ID;
    bool isObjectUsed = false;
    std::string name; 
    int age;
    bool isWoman = true;
    double hipCirc;
    double shoulderCirc;
    double calfCirc;
    double neckCirc;
};