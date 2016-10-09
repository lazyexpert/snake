#include "../headers/Controller.hpp"
#include "../headers/Logger.hpp"

#include "../headers/Model.hpp"
#include "../headers/View.hpp"

Controller :: Controller(Model* model, View* view){
    this->model = model;
    this->view = view;
    
    Logger::write("Controller instance created!");
}
