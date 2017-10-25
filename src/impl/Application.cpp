#include <iostream>
#include "string.h"

#include "../headers/View.hpp"
#include "../headers/Model.hpp"
#include "../headers/Controller.hpp"
#include "../headers/Application.hpp"

#define CELLS_IN_WIDTH 30
#define CELLS_IN_HEIGHT 20

using namespace std;


Application :: Application(int argc, char** argv) 
{   
  bool isDebug = this->parseArgs("debug", argc, argv);    
  if (!isDebug) {
    cout.setstate(ios_base::failbit);
  }

  cout << "Application instance created\n";
  cout << (isDebug ? "Debug mode: true\n" : "Debug mode: false\n");  

  View* view = new View();
  Model* model = new Model(CELLS_IN_WIDTH, CELLS_IN_HEIGHT);      
  this->controller = new Controller(model, view);
}

bool Application :: parseArgs(string target, int argc, char** argv)
{
  for(int t = 0; t < argc; t++) 
    if(!strcmp(target.c_str(), argv[t]))
      return true;
  return false;
}

void Application :: start() 
{
  cout << "Starting application.\n";

  this->controller->start();
}

