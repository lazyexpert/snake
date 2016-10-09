#include <iostream>

#include "../headers/Model.hpp"

using namespace std;

Model :: Model (int width, int height) {
    this->width = width;
    this->height = height;

    cout<< "Model instance created!\n";
}