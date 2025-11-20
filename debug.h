#pragma once
#include <iostream>
#include <string>

using namespace std;

template<typename T>
void deBugInfo(const T& message, const bool& debugMode){
    if (debugMode) cout << message << endl;
}