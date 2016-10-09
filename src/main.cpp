#include <iostream>

#include "headers/Application.hpp"

/**
 * Main program entry point
 */ 
int main(int argc, char** argv) 
{	
	std :: cout << "Reached main.\nStarting app flow.\n";
	Application* app = new Application(argc, argv);
	app->start();
} 
