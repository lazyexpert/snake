#ifndef Application_H
#define Application_H

#include "View.hpp"

/**
 * Main Application Class.
 * Basically - the compostion of all modules.
 */
class Application
{
    View* view;

    bool parseArgs(std::string, int, char**);

public:
    /* Accepting command line arguments */    
    Application(int argc, char** argv);

    /* Obvious - starting app */
    void start();
};

#endif