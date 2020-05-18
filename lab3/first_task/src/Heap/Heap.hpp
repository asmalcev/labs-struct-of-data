#pragma once

class Heap {
private:
  unsigned size;
  unsigned capacity;
  int* arr;
  void heapify(unsigned);

public:
  Heap(unsigned);
  ~Heap();
  int getMin();
  void insert(int);

};