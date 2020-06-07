#pragma once

#include <functional>
#ifdef _WIN32
#include <Windows.h>
#else
#define DWORD
#define WINAPI
#endif
#include "BoardConfig.h"

#ifdef USE_FORK
inline void killChildThread() {
	if (childThreadPID != 0) {
		printf("killing %d\n", childThreadPID);
		kill(childThreadPID, SIGKILL);
	}
}

inline void executeOnChildThread(std::function<void(void)> execable) {
	killChildThread();

	int parentPid = getpid();

	int pid = fork();
	if (pid == 0) {
		printf("RUNNIN FROM %d\n", childThreadPID);
		execable();
		kill(parentPid, SIGUSR1); // Parent Reset State
		_exit(0);
	} else {
		childThreadPID = pid;
		printf("SET CHILD PID TO %d", childThreadPID);
	}
	// printf("RUNNIN FROM %d\n", childThreadPID);
}
#else

inline void killChildThread() {
#ifdef _WIN32

#else
	pthread_cancel(childThread);
#endif
}

extern void resumeNormalOperations(int signum);

DWORD WINAPI runChildThread(void* userData) {
	auto execable = (std::function<void(void)>*)userData;
	//boardWindowInit();
	(*execable)();
	resumeNormalOperations(0);
	return 0;
}

inline void executeOnChildThread(std::function<void(void)> execable) {
	killChildThread();
#ifdef _WIN32
	CreateThread(NULL, 0, &runChildThread, &execable, 0, NULL);
#else
	pthread_create(&childThread, NULL, &runChildThread, &execable);
#endif
}
#endif