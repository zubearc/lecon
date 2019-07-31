#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include "Values.h"

// My bootleg string split!
inline int splitString(char delimiter, String &what, int &pos, String &out) {
	auto len = what.length();
	if (pos == len) return 0;
	for (int i = pos + 1; i < len; i++) {
		auto c = what[i];
		if (c == delimiter) {
			auto s = what.substr(pos == 0 ? pos : pos + 1, i - pos);
			pos = i;
			out = s;
			return i;
		}
	}
	out = what.substr(pos == 0 ? pos : pos + 1, (int)len - pos);
	pos = len;
	return len;
}

/** Read file into string. */
inline std::string slurp (const std::string& path) {
  std::ostringstream buf; 
  std::ifstream input (path.c_str()); 
  buf << input.rdbuf(); 
  return buf.str();
}

inline std::stringstream slurps(const std::string& path) {
  std::stringstream buf; 
  std::ifstream input (path.c_str()); 
  buf << input.rdbuf(); 
  return buf;
}


inline int getCurrentHour() {
    auto t = time(NULL);
    auto tm_struct = localtime(&t);

    int hour = tm_struct->tm_hour;
    return hour;
}
