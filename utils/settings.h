#pragma once

/// @brief The max contestants user can manipulate
constexpr unsigned int MAXCONTESTANTS = 30;

/// @brief Limit how long can be a name
constexpr unsigned int MAXNAMECHARS = 100;

/// @brief How long the titles are
constexpr unsigned int TITLEWIDTH = 65;


/// @brief Switch for Debuging
inline bool DEBUGMODE = false;

/// @brief Switch for clear console feature
inline bool CLEARCONSOLE = true;

/// @brief Switch for autosave feature
inline bool AUTOSAVE = false;

/// @brief Switch for auto categorisation after adding new contestant
inline bool AUTOCATEGORIZE = false;
