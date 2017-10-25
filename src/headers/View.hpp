#ifndef View_H
#define View_H

#include <iostream>
#include <SFML/Graphics.hpp>

class View 
{
  int screenWidth;
  int screenHeight;

  int cellWidth;
  int cellHeight;

  int cellsInWidth;
  int cellsInHeight;

  void printDimensions();

  sf::RenderWindow* window;

  public:
    View(int, int);

    void handleMouseClick(int ,int);
    void handleKeypress(sf::Event*);
    void gentlyExit(sf::Window*);
    void calculateDimensions(int, int);

    void draw(sf::RenderWindow*, int, int*);
    sf::RenderWindow* start();
};

#endif