#pragma once

#include <string>
#include <vector>

struct NearbyAlert {
    int timestamp = 0;
    std::string title;
    std::string precinct;
    std::string location;
};

extern std::vector<NearbyAlert> qNearbyAlert;

void qNearbyUpdate();

bool qAlertHasNearby();

void qNearbyAlertStart();