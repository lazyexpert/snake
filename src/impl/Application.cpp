#include <iostream>
#include "string.h"

#include "../headers/View.hpp"
#include "../headers/Application.hpp"

using namespace std;


Application :: Application(int argc, char** argv) 
{   
  bool isDebug = this->parseArgs("debug", argc, argv);    
  if (!isDebug) {
    cout.setstate(ios_base::failbit);
  }

  cout << "Application instance created\n";
  cout << (isDebug ? "Debug mode: true\n" : "Debug mode: false\n");  

  this->view = new View();        
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
  this->view->start();
}

