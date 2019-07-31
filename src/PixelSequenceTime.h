#pragma once

#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>  // string

std::string qGetTimeString() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    // ss << std::put_time(std::localtime(&in_time_t), "%l~%M~%S~%p");
    ss << std::put_time(std::localtime(&in_time_t), "%l~%M %p ");

    auto s = ss.str();
    // if (s[0] == ' ') {
    //     s.pop
    // }
    s.pop_back();
    return s;
}