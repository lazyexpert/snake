#include <iostream>

#include "Application.cpp"

int main(int argc, char** argv) {
	Application* app = new Application(argc, argv);
	app->start();
} 
