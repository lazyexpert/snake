#include "../headers/View.hpp"
#include "../headers/Model.hpp"
#include "../headers/Controller.hpp"

Controller :: Controller(Model* model, View* view) 
{
    this->view = view;
    this->model = model;

    this->score = 0;
    this->isDefeated = false;
}

void Controller :: start() {
    this->view->start();
} 

// game loop
// renderer call
// event handlers call
