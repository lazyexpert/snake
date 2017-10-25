#include <iostream>

#include "../headers/View.hpp"
#include "../headers/Model.hpp"
#include "../headers/Controller.hpp"

#include <SFML/Graphics.hpp>

Controller :: Controller(Model* model, View* view) 
{
  this->view = view;
  this->model = model;

  this->score = 0;
  this->isDefeated = false;
}

void Controller :: start() {
  this->window = this->view->start();

  // gameloop
  while (this->window->isOpen())
  {    
    sf::Event event;

    // fetch events    
    this->routeEvents(&event);
    this->window->setVerticalSyncEnabled(true);
    this->window->clear(sf::Color::Black);

    this->view->draw(this->window, this->model->size, this->model->board);
    
    if (this->model->canMove()) {
      this->model->makeMove();
    } else {
      this->defeat();
    }

    // finish draw
    this->window->display();
  }
} 

void Controller :: defeat() {
  this->isDefeated = true;
  std::cout << "DEFEAT!\n";
}

void Controller :: routeEvents(sf::Event* event) 
{
  while (this->window->pollEvent(*event)) {
    // check the type of the event...
    switch (event->type)
    {
      // window closed
      case sf::Event::Closed:
        this->view->gentlyExit(this->window);
        break;
      
      // catch window resize                
      case sf::Event::Resized:
        this->view->calculateDimensions(event->size.width, event->size.height);
        break;
      
      // Mouse button click
      case sf::Event::MouseButtonPressed:
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
          // FIXME
          this->view->handleMouseClick(event->mouseButton.x, event->mouseButton.y);
        }                    
        break;

      // key up
      case sf::Event::KeyReleased:
        if (event->key.code == sf::Keyboard::Escape) 
          this->view->gentlyExit(this->window);                    
        else 
          this->view->handleKeypress(event);                                                
        break;

      // we don't process other types of events
      default:
        break;
    }
  }
}
