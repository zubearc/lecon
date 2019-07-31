#include "PixelSequenceAlert.h"

#include <string>
#include <iostream>

#include "PixelSequences.h"
#include "Util.h"

std::vector<NearbyAlert> qNearbyAlert;

void qNearbyUpdate() {
    system("python ../scripts/getcitizen.py");

    auto ws = slurps("../data/nearby_incidents.txt");
    
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

bool qAlertHasNearby() {
    if (qNearbyAlert.size())
        return true;
    return false;
}

void qNearbyAlertStart(NearbyAlert alert) {
    flush();
    write("NEARBY!", 0x4040);
    render();

    delay(2000);

    writeFlashing(alert.title, 0x4000);

    writeScrollable(alert.precinct, 0x4010);
    // render();

    delay(1000);

    writeScrollable(alert.location, 0x40, 100);

    delay(1000);

    // String tx3 = " 3M ago";
    // writeScrollable(tx3, 0x4010);
    // render();

    delay(1000);
}

void qNearbyAlertStart() {
    for (auto alert : qNearbyAlert) {
        qNearbyAlertStart(alert);
    }

    qNearbyAlert = {};
}