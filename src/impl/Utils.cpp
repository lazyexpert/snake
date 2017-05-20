#include <iostream>
#include "string.h"

#include "../headers/Utils.hpp"

Utils :: Utils() {}

bool Utils :: parseArgs(std::string target, int argc, char** argv)
{
  for(int t = 0; t < argc; t++) 
    if(!strcmp(target.c_str(), argv[t]))
      return true;
  return false;
}