#pragma once
#include "Array/Array.hpp"

class MatrixGraph {
private:
  int* matrix;
  unsigned char length;
  void dfs(int, Array, int&);

public:
  MatrixGraph(unsigned char);
  ~MatrixGraph();
  void addEdge(int, int);
  void removeEdge(int, int);
  Array* findAllStocks();
  Array* findAllRises();
  int countOfTrees();

};