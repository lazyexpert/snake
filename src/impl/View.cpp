#include <iostream>
#include <SFML/Graphics.hpp>

#include "../headers/View.hpp"
#include "../headers/Model.hpp"

using namespace std;
View :: View() 
{    
  cout<< "View instance created\n";        
  
  this->cellsInWidth = 30;
  this->cellsInHeight = 20;

  const int width = sf::VideoMode::getDesktopMode().width;
  const int height = sf::VideoMode::getDesktopMode().height;
  this->calculateDimensions(width, height);

  this->model = new Model(this->cellsInWidth, this->cellsInHeight);
}

void View :: calculateDimensions(int width, int height) 
{
  this->screenWidth = width;
  this->screenHeight = height;

  this->cellWidth = this->screenWidth / this->cellsInWidth;
  this->cellHeight = this->screenHeight / this->cellsInHeight;

  this->printDimensions();
}

void View :: printDimensions() {
  cout<<"Current dimensions:\n";
  cout<<"ww: "<< this->screenWidth<<"; wh: "<< this->screenHeight;    
  cout<<"; cw: "<< this->cellWidth<<"; ch: "<< this->cellHeight<<endl;
}

void View :: handleMouseClick(int x, int y) 
{
  cout<<"Catch left mouse button"<<endl;
  cout<<"x: "<<x<<endl;
  cout<<"y: "<<y<<endl<<endl;
}

void View :: handleKeypress(sf::Event* event) 
{
  cout<<"Handling keyboard keypress"<<endl;
}

void View :: gentlyExit(sf::Window* window) 
{
  window->close();
  cout<<"The application is closed. Come back asap!\n";
}

void View :: routeEvents(sf::Event* event, sf::Window* window) 
{
  while (window->pollEvent(*event)) {
    // check the type of the event...
    switch (event->type)
    {
      // window closed
      case sf::Event::Closed:
        this->gentlyExit(window);
        break;
      
      // catch window resize                
      case sf::Event::Resized:
        this->calculateDimensions(event->size.width, event->size.height);
        break;
      
      // Mouse button click
      case sf::Event::MouseButtonPressed:
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
          this->handleMouseClick(event->mouseButton.x, event->mouseButton.y);
        }                    
        break;

      // key up
      case sf::Event::KeyReleased:
        if (event->key.code == sf::Keyboard::Escape) 
          this->gentlyExit(window);                    
        else 
          this->handleKeypress(event);                                                
        break;

      // we don't process other types of events
      default:
        break;
    }
  }
}

void View :: start()
{
  sf::VideoMode videoMode = sf::VideoMode(this->screenWidth, this->screenHeight);
  sf::RenderWindow window(videoMode, "Lazy snake!");

  // gameloop
  while (window.isOpen())
  {    
    sf::Event event;

    // fetch events    
    this->routeEvents(&event, &window);
    window.setVerticalSyncEnabled(true);
    window.clear();    
    window.display();
  }
}