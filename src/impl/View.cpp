#include <iostream>
#include <SFML/Graphics.hpp>

#include "../headers/View.hpp"
#include "../headers/Model.hpp"
#include "../headers/DataTypes.hpp"
#include "../headers/Directions.hpp"

using namespace std;
View :: View(int width, int height) 
{    
  cout << "View instance created\n";        
  
  this->cellsInWidth = width;
  this->cellsInHeight = height;

  int windowWidth = sf::VideoMode::getDesktopMode().width;
  int windowHeight = sf::VideoMode::getDesktopMode().height;
  this->calculateDimensions(windowWidth, windowHeight);
}

void View :: calculateDimensions(int width, int height) 
{
  this->screenWidth = width;
  this->screenHeight = height - 50;

  this->cellWidth = this->screenWidth / this->cellsInWidth;
  this->cellHeight = this->screenHeight / this->cellsInHeight;

  this->printDimensions();
}

void View :: printDimensions() {
  cout << "Current dimensions:\n";
  cout << "ww: " << this->screenWidth << "; wh: " << this->screenHeight;
  cout << "; cw: " << this->cellWidth << "; ch: " << this->cellHeight << endl;
}

void View :: handleMouseClick(int x, int y) 
{
  cout << "Catch left mouse button" << endl;
  cout << "x: " << x << endl;
  cout << "y: " << y << endl << endl;
}

void View :: handleKeypress(sf::Event* event) 
{
  cout << "Handling keyboard keypress"<<endl;
}

void View :: gentlyExit(sf::Window* window) 
{
  this->window->close();
  cout << "The application is closed. Come back asap!\n";
}

void View :: draw(sf::RenderWindow* window, int size, int* board) {
  for (int i = 0; i < size; i++) {
    if (board[i] == EMPTYCELL) continue;

    // define a rectangle
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(this->cellWidth, this->cellHeight));

    int offsetX = (i % this->cellsInWidth) * this->cellWidth;

    int height = i / this->cellsInWidth;
    int offsetY =  height * this->cellHeight;

    rectangle.setPosition(sf::Vector2f(offsetX, offsetY));

    if (board[i] == SNAKEBODY) {
      rectangle.setFillColor(sf::Color::Yellow);
    } else if (board[i] == SNAKEHEAD) {
      rectangle.setFillColor(sf::Color::Red);
    } else if (board[i] == APPLE) {
      rectangle.setFillColor(sf::Color::Green);
    }

    this->window->draw(rectangle);
  }
}

sf::RenderWindow* View :: start()
{
  sf::VideoMode videoMode = sf::VideoMode(this->screenWidth, this->screenHeight);
  this->window = new sf::RenderWindow(videoMode, "Lazy snake!");

  return window;
}
