#include <iostream>
#include <time.h>

#include "../headers/Logger.hpp"

using namespace std;

Logger :: Logger() {}

bool DEBUG;

string Logger :: format(string ss) {
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
        
    string tmp = asctime (timeinfo);       
    
    return tmp
            .substr(0,tmp.length()-1)
            .append(" ")
            .append(ss)
            .append("\n");
}

void Logger :: init(bool debug) {
    DEBUG = debug;
}

void Logger :: write(string data) {  
    if(DEBUG) cout << Logger::format(data);
}