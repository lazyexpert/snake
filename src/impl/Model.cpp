#include <iostream>
#include "time.h"

#include "../headers/Model.hpp"
#include "../headers/CellTypes.hpp"
#include "../headers/Directions.hpp"

using namespace std;

Model :: Model (int width, int height) 
{
  this->width = width;
  this->height = height;
  this->size = width * height;
  this->board = new int [ this->size ];
  this->snakebody = {};

  srand(time(0));

  cout << "Model instance created\n";

  this->init();
  this->setDirection(RIGHT);
}

void Model :: init() {
  for (int i = 0; i < this->size; i++) {
    if (i <= 5) {
      this->board[i] = SNAKEBODY;
      this->snakebody.push_back(i);
    } else if (i == 6) {
      this->board[i] = SNAKEHEAD;
    } else {
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

void Model :: setDirection(int direction) {
  cout << "Snake direction changed\n";
  this->direction = direction;
}

void Model :: makeMove() {
  int index = this->getNewCellIndex();

  cout << index;
}

bool Model :: canMove() {
  if (this->direction == UP ) {
    return this->snakehead < this->width;
  } else if (this->direction == RIGHT) {
    return this->snakehead % this->width < this->width; 
  } else if (this->direction == DOWN) {
    int currentPosY = this->snakehead / this->width;
    return currentPosY != this->height;
  } else {
    return this->snakehead % this->width != 0;
  }
}

int Model :: getNewCellIndex() {
  if (this->direction == UP ) {
    return this->snakehead - this->width;
  } else if (this->direction == RIGHT) {
    return this->snakehead + 1; 
  } else if (this->direction == DOWN) {
    return this->snakehead + this->width;
  } else {
    return this->snakehead - 1;
  }
}