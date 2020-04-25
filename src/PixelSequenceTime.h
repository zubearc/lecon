#pragma once

#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>  // string

std::string qGetDateString() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    // ss << std::put_time(std::localtime(&in_time_t), "%l~%M~%S~%p");
    ss << std::put_time(std::localtime(&in_time_t), "%a, %e");

    auto s = ss.str();
    return s;
}

std::string qGetTimeString(std::string seperator = "") {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::string f;
    if (seperator.size()) {
        f = "%l" + seperator + "%M %p";        
    } else {
        f = "%l %M %p";
    }

    std::stringstream ss;
    // ss << std::put_time(std::localtime(&in_time_t), "%l~%M~%S~%p");
    ss << std::put_time(std::localtime(&in_time_t), f.c_str());

    auto s = ss.str();
    // if (s[0] == ' ') {
    //     s.pop
    // }
    // s.pop_back();
    return s;
}