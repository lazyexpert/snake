#ifndef Controller_H
#define Controller_H

#include "Model.hpp"
#include "View.hpp"
#include <SFML/Graphics.hpp>

class Controller
{
  Model* model;
  View* view;

  int score;
  bool isDefeated;

  public:
    Controller(Model*, View*);
    
    void start();
};

#endif