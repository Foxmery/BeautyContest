#pragma once


constexpr unsigned int MAXCONTESTANTS = 30;


//Screen(2d array of chars) dimensions in the terminal
constexpr unsigned int SCREENWIDTH = 65; //numbers of chars possible can be used in the X axis
constexpr unsigned int SCREENHEIGHT = 20; //numbers of chars possible to be used in the Y axis

//Miscellaneous settings
constexpr bool DEBUGMODE = 1; 
constexpr bool CLEARCONSOLE = 0; 
constexpr bool USE_SHORT_NAMES = 0; 
//LATER: hipCircumfrance -> HC, shoulderCircumfrance -> SC