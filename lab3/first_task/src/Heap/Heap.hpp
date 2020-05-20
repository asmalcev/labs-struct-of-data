#pragma once
#include "Counter.hpp"

class Heap {
private:
  unsigned size;
  unsigned capacity;
  int* arr;
  counter& c;
  void heapify(unsigned);

public:
  Heap(unsigned, int*, counter&);
  ~Heap();
  int getMin();
  void insert(int);

};