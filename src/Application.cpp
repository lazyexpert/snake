# include <iostream>

using namespace std;

class Application {
public: 
    Application() {
        cout << "Application instance created.\n";
    }

    void start() {
        cout << "Starting application.\n";
    }
};
