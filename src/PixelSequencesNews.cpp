#pragma once
#if 0
#include <string>
#include <vector>
#include "PixelSequences.h"
#include "Util.h"

std::vector<NearbyAlert> qNewsAlerts;

void qNewsUpdate() {
    auto ws = slurps("../data/news.txt");
    
    std::string timestamp;
    while (std::getline(ws, timestamp)) {
        std::string ititle;
        if (!std::getline(ws, ititle)) return;

        std::string pct;
        if (!std::getline(ws, pct)) return;
        
        std::string loc;
        if (!std::getline(ws, loc)) return;

        printf("Got new incident %s - %s @ %s\n", ititle.c_str(), pct.c_str(), loc.c_str());

        qNearbyAlert.push_back({ std::stoi(timestamp), ititle, pct, loc });
    }
}

bool qNewsHasNew() {

}

void qNewsDisplay() {

}
#endif