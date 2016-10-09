#ifndef Logger_H
#define Logger_H
#include <iostream>

using namespace std;

class Logger {
private:
    Logger();
    static string format(string ss);
    static bool debug;
public:
    static void init(bool debug);
    static void write(string data);
};

#endif