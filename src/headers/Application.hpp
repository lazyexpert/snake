#ifndef Application_H
#define Application_H

#include "Controller.hpp"

/**
 * Main Application Class.
 * Basically - the compostion of all modules.
 */
class Application
{
    Controller* controller;

    bool parseArgs(std::string, int, char**);

public:
    /* Accepting command line arguments */    
    Application(int, char**);

    void start();
};

#endif