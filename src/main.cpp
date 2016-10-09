#include "headers/Application.hpp"

/**
 * Main program entry point
 */ 
int main(int argc, char** argv) {
	Application* app = new Application(argc, argv);
	app->start();
} 
