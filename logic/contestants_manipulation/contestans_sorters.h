#pragma once
#include <cstring>
#include <string>

using namespace std;

#include "contestants_searchers.h"
#include "contestants_manager.h"

#include "../../utils/contestant.h"
#include "../../utils/settings.h"
#include "../../utils/debug.h"

enum SortMode {
    SORT_BY_ID = 0,
    SORT_BY_NAME = 1,
    SORT_BY_AGE_ASC = 2,
    SORT_BY_POINTS_ASC = 4,
    SORT_BY_POINTS_DESC = 3
};

/// @brief Manages the logic for the sorting menu
/// @param contestant The contestants to sort
/// @param mode       SORT_BY_ID, SORT_BY_NAME, SORT_BY_AGE_ASC, SORT_BY_POINTS_ASC, SORT_BY_POINTS_DESC
void sortContestants(Contestants contestant[], SortMode mode);

