#ifndef View_H
#define View_H

#include "Model.hpp"

class View 
{
    int screenWidth;
    int screenHeight;

    int cellWidth;
    int cellHeight;

    int cellsInWidth;
    int cellsInHeight;

    void calculateDimensions();
    
    void handleMouseClick(int ,int);

    Model* model;

public:
    View();

    void start();
};

#endif