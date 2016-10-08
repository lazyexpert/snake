#include "Application.cpp"
#include "stdio.h"

void test() {
	printf("Hello world");
}

/**
 * Main program entry point
 */ 
int main(int argc, char** argv) {
	Application* app = new Application(argc, argv);
	app->start();

	void (*pf)();
	pf=&test;
	pf();
} 
