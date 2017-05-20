#include <iostream>

#include "../headers/Model.hpp"
#include "../headers/DataTypes.hpp"
#include "../headers/Directions.hpp"

using namespace std;

Model :: Model (int width, int height) 
{
  this->width = width;
  this->height = height;
  this->size = width * height;
  this->board = new int [ this->size ];
  this->direction = RIGHT;
  this->snakebody = {};

  srand(time(0));

  cout<< "Model instance created\n";

  this->init();
}

void Model :: init() {  
  for (int i = 0; i < this->size; i++) {
    if (i <= 5) {
      this->board[i] = SNAKEBODY;
      this->snakebody.push_back(i);
    }
    else if (i == 6) {
      this->board[i] = SNAKEHEAD;      
    }
    else {
      this->board[i] = EMPTYCELL;
    }
  }

  this->snakehead = 5;

  for (int i = 0; i < 3; i++) {
    int index = this->getRandomEmptyCell();
    this->board[index] = APPLE;
  }
  
  cout << "Model instance initialized\n";
}

int Model :: getRandomEmptyCell() {
  vector<int> emptyCells = {};

  for (int i = 0; i < this->size; i++)
    if (this->board[i] == EMPTYCELL)
      emptyCells.push_back(i);

  return rand() % emptyCells.size();
}

