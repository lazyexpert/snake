#include <iostream>
#include "string.h"

#include "../headers/Utils.hpp"
#include "../headers/View.hpp"
#include "../headers/Application.hpp"

using namespace std;


Application :: Application(int argc, char** argv) {   
    bool res = Utils::parseArgs("debug", argc, argv);    

    cout << "Application instance created.";
    cout<< (res ? "Debug mode: true." : "Debug mode: false.");
    
    this->view = new View();        
}

void Application :: start() {
    cout << "Starting application.";
    this->view->start();
}

