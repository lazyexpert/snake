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
  
  void init();

  std::vector<int> getEmptyCells();
};

#endif