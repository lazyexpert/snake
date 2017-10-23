#ifndef Application_H
#define Application_H

#include "View.hpp"
#include "Model.hpp"
#include "Controller.hpp"

/**
 * Main Application Class.
 * Basically - the compostion of all modules.
 */
class Application
{
    View* view;
    Model* model;
    Controller* controller;

    bool parseArgs(std::string, int, char**);

public:
    /* Accepting command line arguments */    
    Application(int, char**);

    void start();
};

#endif