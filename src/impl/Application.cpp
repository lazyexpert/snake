#include <iostream>
#include "string.h"

#include "../headers/Utils.hpp"
#include "../headers/View.hpp"
#include "../headers/Application.hpp"

using namespace std;


Application :: Application(int argc, char** argv) 
{   
    bool res = Utils::parseArgs("debug", argc, argv);    

    cout << "Application instance created.\n";
    cout<< (res ? "Debug mode: true.\n" : "Debug mode: false.\n");
        
    this->view = new View();        
}

void Application :: start() 
{
    cout << "Starting application.\n";
    this->view->start();
}

