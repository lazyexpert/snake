#include <iostream>
#include "string.h"
#include "Utils.cpp"

using namespace std;

/**
 * Main Application Class.
 * Basically - the compostion of all modules.
 */
class Application {
    bool debug;    
    
public:
    /* Accepting command line arguments */    
    Application(int argc, char** argv) {        
        this->debug = Utils::parseArgs("debug", argc, argv);
        
        cout << "Application instance created.\nDebug mode: ";
        cout << (this->debug == 1 ? "true.\n" : "false.\n");
    }

    /* Obvious - starting app */
    void start() {
        cout << "Starting application.\n";
    }
};
