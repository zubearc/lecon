// #ifdef 
#if 1
#include "InterfaceWebsocket.h"
#include "BoardConfig.h"
#include "Util.h"
#include <functional>

using namespace nyctlib;
pthread_t websocketThread;
pthread_t streamingThread;
WSInterface wsi;

long long lastSendHash = 0;

bool active = true;

void iWebsocketInit() {

}

void iWebsocketTest() {
	if (wsi.listening) {
		if (lastSendHash != 0 && boardStateHash != 0) {
			if (lastSendHash == boardStateHash) {
				return;
			}
		}

		lastSendHash = boardStateHash;
		wsi.broadcastBinaryPreferred(WSInterface::MessageType::SubscribtionFeed, 
			WSInterface::MessageType::SubscribtionFeed, 
			// (char*)globalWindow.matrix, 
			// sizeof(ws2811_led_t) * globalWindow.size
			(char*)ledstring.channel[0].leds,
			sizeof(ws2811_led_t) * LED_COUNT
		);
	}
}

void killWebsocketThread() {
	pthread_cancel(websocketThread);
}

extern "C" inline void* runWebsocketThread(void* userData) {
	// auto execable = (std::function<void(void)>*)userData;
	// boardWindowInit();
	printf("iWS: Running exe\n");
	wsi.start("", 6761);
	printf("iWS: Started\n");
	// (*execable)();
	// resumeNormalOperations(0);
	return 0;
};

extern "C" inline void* runStreamingThread(void* userData) {
	while (active) {
		iWebsocketTest();
		SleepMS(200);
	}
	return 0;
};

void iWebsocketStartBackground() {
    killWebsocketThread();
	printf("iWS: Started WSI\n");

	// std::function<void(void)> func = [&]() {
	// 	printf("iWS: Starting to listen on 6761\n");
	// 	wsi.start("", 6761);
	// 	printf("iWS: Started\n");
	// };

	pthread_create(&websocketThread, NULL, &runWebsocketThread, /*params*/NULL);
	// pthread_create(&streamingThread, NULL, &runStreamingThread, /*params*/NULL);
}
#endif