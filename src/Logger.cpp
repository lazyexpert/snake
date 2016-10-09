#include <iostream>
#include <time.h>
#include <string.h>
#include <stdlib.h> 

using namespace std;

class Logger {
    bool debug;

    string format(string ss) {
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

public:
    Logger(bool debug){
        this->debug = debug;
    }

    void write(string data) {
        if(this->debug) {
            string temp = this->format(data);
            cout << temp;            
        }        
    }


};
