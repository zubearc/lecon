#pragma once

#include <string>
#include <vector>

static std::string qWeatherCurrentTemperature;
static std::string qWeatherCurrentConditions;
static std::vector<std::string> qWeatherFuture;

void qWeatherUpdate();

void qWeatherStart();