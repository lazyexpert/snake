#include <iostream>
#include "string.h"

#include "Utils.cpp"
#include "headers/Logger.hpp"
#include "headers/View.hpp"
#include "headers/Model.hpp"
#include "headers/Controller.hpp"

using namespace std;

/**
 * Main Application Class.
 * Basically - the compostion of all modules.
 */
class Application {    
    View* view; 
    Model* model;
    Controller* controller;

public:
    /* Accepting command line arguments */    
    Application(int argc, char** argv) {   
        bool res = Utils::parseArgs("debug", argc, argv);
        Logger::init(res);

        this->model = new Model();
        this->view = new View();
        this->controller = new Controller(this->model, this->view);

        Logger::write("Application instance created.\n");
        Logger::write(res ? "Debug mode: true.\n" : "Debug mode: false.\n");
    }

    /* Obvious - starting app */
    void start() {
        Logger::write("Starting application.\n");
    }
};
