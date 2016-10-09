#include <iostream>
#include "string.h"

#include "Utils.cpp"
#include "Logger.cpp"

using namespace std;

/**
 * Main Application Class.
 * Basically - the compostion of all modules.
 */
class Application {
    bool debug;

    Logger* logger;

public:
    /* Accepting command line arguments */    
    Application(int argc, char** argv) {        
        this->debug = Utils::parseArgs("debug", argc, argv);
        
        this->logger = new Logger(this->debug);         

        this->logger->write("Application instance created.\n");
        this->logger->write(this->debug == 1 ? "Debug mode: true.\n" : "Debug mode: false.\n");
    }

    /* Obvious - starting app */
    void start() {
        this->logger->write("Starting application.\n");
    }
};
