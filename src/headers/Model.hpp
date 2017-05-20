#ifndef Model_H
#define Model_H

#include <vector>

class Model 
{
  int width;
  int height;    
  int size;
  
  int snakehead;
  std::vector<int> snakebody;

  int* board;

public:
  Model(int, int);
  
private:
  /**
   * Initialize board
   * Add snake on the basic position 
   * Add apples on random positions 
   */
  void init();

  /**
   * Method finds all empty cells int the board
   * Picks random one 
   * Returns its index 
   */ 
  int getRandomEmptyCell();
  
};

#endif