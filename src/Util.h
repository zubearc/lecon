#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <functional>
#ifdef _WIN32
#include <Windows.h>
#else
#include <sys/time.h> // unix gettimeofday
#include <sys/types.h>
#define _ASSERT
#endif
#include <signal.h>
#include "Values.h"

// My bootleg string split!
inline int splitString(char delimiter, const std::string& what, int& pos, std::string& out) {
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
inline std::string slurp(const std::string& path) {
	std::ostringstream buf;
	std::ifstream input(path.c_str());
	buf << input.rdbuf();
	return buf.str();
}

inline std::stringstream slurps(const std::string& path) {
	std::stringstream buf;
	std::ifstream input(path.c_str());
	buf << input.rdbuf();
	return buf;
}


inline int getCurrentHour() {
	auto t = time(NULL);
	auto tm_struct = localtime(&t);

	int hour = tm_struct->tm_hour;
	return hour;
}

inline long long CurrentTimeMS() {
#ifdef _WIN32
	SYSTEMTIME time;
	GetSystemTime(&time);
	LONG time_ms = (time.wSecond * 1000) + time.wMilliseconds;
	return time_ms;
#else
	struct timeval te;
	gettimeofday(&te, NULL); // get current time
	long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000; // calculate milliseconds
	// printf("milliseconds: %lld\n", milliseconds);
	return milliseconds;
#endif
}

inline unsigned int randr(unsigned int min, unsigned int max) {
	double scaled = (double)rand() / RAND_MAX;

	return (max - min + 1) * scaled + min;
}

inline void SleepMS(int milliseconds) {
#ifdef _WIN32
	Sleep(milliseconds);
#else
	usleep(milliseconds * 1000);
#endif
}