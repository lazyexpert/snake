#include <iostream>
#include "Logger.cpp"
#include "string.h"
#include "Utils.cpp"

using namespace std;

class Application {
    bool debug;    
    Logger* logger;

public:
    Application(int argc, char** argv) {
        this->debug = Utils::parseArgs("debug", argc, argv);
        this->logger = new Logger(this->debug);
        
        this->logger->log("Application instance created.\nDebug mode: ");
        this->logger->log(this->debug == 1 ? "true.\n" : "false.\n");
    }

    void start() {
        this->logger->log("Starting application.\n");        
    }
};
