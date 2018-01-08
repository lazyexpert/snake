#ifndef Model_H
#define Model_H

#include <vector>

class Model 
{
  int width;
  int height;    
  int snakehead;
  int direction;
  
  std::vector<int> snakebody;

public:
  int size;
  int* board;
  Model(int, int);
  
  /**
   * Set direction of the snake from outside world
   */
  void setDirection(int direction);
  
  /**
   * Method checks if we can make next move
   */
  bool canMove();

  /**
   * Method to make snake move 
   */
  void makeMove();
  
   
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

  /**
   * Helper method to get next cell index when making a move
   */
  int getNewCellIndex();
};

#endif