#ifndef Controller_H
#define Controller_H

#include "Model.hpp"
#include "View.hpp"

class Controller {
    Model* model;
    View* view;
public:
    Controller(Model*, View*);
};

#endif