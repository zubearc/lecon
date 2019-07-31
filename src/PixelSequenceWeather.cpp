#include "PixelSequenceWeather.h"

#include <string>
#include <iostream>

#include "PixelSequences.h"
#include "Util.h"

void qWeatherUpdate() {
    system("python ../scripts/getweather.py");

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
    // for (auto e : future) {
    //     printf("%s\n", e.c_str());
    // }
}

void qWeatherStart() {
    flush();
	write("   " + qWeatherCurrentTemperature, 0xFF071585);
	// write("NOW", 0xff0000, 16);
	render();
	delay(2000);

	writeFlashing(qWeatherCurrentConditions, 0xC7158500);
	////  write("NOW", 0xff0000, 16);
	//  render();
	//  delay(2000);

    for (auto fe : qWeatherFuture) {
        flush();
        write(fe, 0x2000);
        // write("1 HR", 0x2000, 16);
        render();
        delay(2000);
    }
}