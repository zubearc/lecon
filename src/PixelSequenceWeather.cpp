#include <string>
#include <iostream>
#include "PixelSequenceWeather.h"
#include "PixelSequences.h"
#include "WindowManager.h"
#include "Util.h"

void qWeatherUpdate() {
    system("/usr/bin/python ../scripts/getweather.py");

    auto ws = slurps("../data/weather.txt");
    
    std::string timestamp;
    std::getline(ws, timestamp);

    printf("Weather: \n");
    printf("TS: %s\n", timestamp.c_str());

    std::string curr_temp;

    std::getline(ws, curr_temp);

    std::string curr_cond;

    std::getline(ws, curr_cond);

    std::vector<std::string> future;
    std::string future_entity;
    while (std::getline(ws, future_entity)) {
        future.push_back(future_entity);
    }

    qWeatherCurrentTemperature = curr_temp;
    qWeatherCurrentConditions = curr_cond;
    qWeatherFuture = future;
    for (auto e : qWeatherFuture) {
        printf("%s\n", e.c_str());
    }
}

void qWeatherStart() {
    wLimitWriteRegion(32, 8);
    flushLeft();
	write("   " + qWeatherCurrentTemperature, 0xFF071585);
	// write("NOW", 0xff0000, 16);
	render();
	delay(2000);

	// writeFlashing(qWeatherCurrentConditions, 0x276525);
    writeFlashing(qWeatherCurrentConditions, 0x204500);

	////  write("NOW", 0xff0000, 16);
	//  render();
	//  delay(2000);

    for (auto fe : qWeatherFuture) {
        flushLeft();
        write(fe, 0x2000);
        
        // write("1 HR", 0x2000, 16);
        printf("fe:%s\n",fe.c_str());

        // TODO: fix. for some reason render() does not render because the hash is the same as last
        // some sort of window derpiness. use forced directRender instead to workaround...
        // render();
        matrix_render2();
        _directRender();
        delay(2000);
    }
    wRestoreWriteRegion();
}