#include <iostream>
#include "string.h"

class Utils {
public:
    Utils() {}

    static bool compareStrings(const char* str1, char* str2) {
        if(strlen(str1) != strlen(str2)) 
            return false;

        for(int t=0; t<strlen(str1); t++) 
            if(str1[t] != str2[t])
                return false;

        return true;        
    }

    static bool parseArgs(std::string target, int argc, char** argv){
        for(int t=0; t<argc; t++) 
            if(compareStrings(target.c_str(), argv[t]))
                return true;
        return false;
    }
};