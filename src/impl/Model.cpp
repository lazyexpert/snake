#include <iostream>
#include <cstdlib>
#include <vector>
#include "stdio.h"


#include "../headers/Model.hpp"
#include "../headers/DataTypes.hpp"

using namespace std;

Model :: Model (int width, int height) 
{
  this->width = width;
  this->height = height;
  this->size = width * height;
  this->board = (int*) malloc(sizeof(int) * width * height);
  
  this->snakebody = {};

  cout<< "Model instance created!\n";
  
  this->init();
}

/**
 * Initialize board
 * Add snake on the basic position 
 * Add apples on random positions 
 */
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

  vector<int> empty = this->getEmptyCells();
  // cout << empty->size();
  // cout << empty->at(0) << endl;
  for (int val: empty) {
    cout << val << endl;
  }
  // for( int i = 0; i < empty->size(); i++) {
  //   printf("%d\n", empty->at(i));
  // }  

  cout << "Model instance initialized!\n";
}

vector<int> Model :: getEmptyCells() {
  vector<int> emptyCells = {};  
  for (int i = 0; i < this->size; i++) {
    if (this->board[i] == EMPTYCELL)
      emptyCells.push_back(i);
  }  

  return emptyCells;
} 