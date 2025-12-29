#pragma once


constexpr unsigned int MAXCONTESTANTS = 30;
constexpr unsigned int MAXNAMECHARS = 100;


//Screen(2d array of chars) dimensions in the terminal
inline unsigned int SCREENWIDTH = 65; //numbers of chars possible can be used in the X axis
inline unsigned int SCREENHEIGHT = 20; //numbers of chars possible to be used in the Y axis //LATER:

inline bool DEBUGMODE = false; 
inline bool CLEARCONSOLE = true; 

//LATER: 
inline int AUTOSAVESECONDS = 30; 

inline bool AUTOCATEGORIZE = false;