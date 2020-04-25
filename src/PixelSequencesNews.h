#pragma once

#include <string>
#include <vector>

struct NewsAlert {
    int timestamp = 0;
    std::string title;
    std::string description;
    std::string source;
};

extern std::vector<NearbyAlert> qNewsAlerts;

void qNewsUpdate();

bool qNewsHasNew();

void qNewsDisplay();