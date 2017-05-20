#ifndef View_H
#define View_H

#include "Model.hpp"
#include <SFML/Graphics.hpp>

class View 
{
    int screenWidth;
    int screenHeight;

    int cellWidth;
    int cellHeight;

    int cellsInWidth;
    int cellsInHeight;

    void calculateDimensions();
    void calculateDimensions(int, int);
    void printDimensions();
    
    void handleMouseClick(int ,int);
    void handleKeypress(sf::Event*);
    void gentlyExit(sf::Window*);

    Model* model;

    void routeEvents(sf::Event*, sf::Window*);

public:
    View();

    void draw(sf::RenderWindow* window);
    void start();
};

#endif