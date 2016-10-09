#ifndef Utils_H
#define Utils_H

#include <iostream>

class Utils 
{
public:
    Utils();

    static bool compareStrings(const char* str1, char* str2);

    static bool parseArgs(std::string target, int argc, char** argv);
};

#endif