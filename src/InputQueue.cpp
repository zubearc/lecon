#include "InputQueue.h"

std::queue<std::string> iq;

void queueCommand(std::string command) {
    iq.push(command);
}

std::string getCommand() {
    return iq.back();
}