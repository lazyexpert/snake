#include <iostream>
#include "string.h"

using namespace std;

class Application {
    bool debug;

    bool compareStrings(char* str1, char* str2) {
        if(strlen(str1) != strlen(str2)) 
            return false;

        for(int t=0; t<strlen(str1); t++) 
            if(str1[t] != str2[t])
                return false;

        return true;        
    }

    bool parseArgs(char* target, int argc, char** argv){
        for(int t=0; t<argc; t++) 
            if(compareStrings(target, argv[t]))
                return true;
        return false;
    }

public:
    Application(int argc, char** argv) {
        char* debug = strdup("debug");

        this->debug = this->parseArgs(debug, argc, argv);
        cout << "Application instance created.\nDebug mode: ";
        cout << (this->debug == 1 ? "true.\n" : "false.\n" );
    }

    void start() {
        cout << "Starting application.\n";
    }
};
