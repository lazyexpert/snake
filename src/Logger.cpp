#include <iostream>

class Logger {
    bool debug;

public:
    Logger(bool debug){
        this->debug = debug;
    }

    void log(std::string data) {
        if(this->debug)
            std::cout<<data;
    }
};