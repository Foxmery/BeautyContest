#pragma once


constexpr unsigned int MAXCONTESTANTS = 30;

constexpr unsigned int MAXNAMECHARS = 100;


//Screen(2d array of chars) dimensions in the terminal
constexpr unsigned int SCREENWIDTH = 65; //numbers of chars possible can be used in the X axis
constexpr unsigned int SCREENHEIGHT = 20; //numbers of chars possible to be used in the Y axis

//Miscellaneous settings
inline bool DEBUGMODE = true;  //Oh no global variable. i am a bad guy
constexpr bool CLEARCONSOLE = 0; 
constexpr bool USE_SHORT_NAMES = 0; 
//LATER: hipCircumfrance -> HC, shoulderCircumfrance -> SC

//LATER: 
inline int autosaveTimeSeconds = 30; 

//LATER:
inline bool autoCategorize = false;