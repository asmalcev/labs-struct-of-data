#pragma once
#include "Array/Array.hpp"

class MatrixGraph {
private:
  int* matrix;
  unsigned int length;
  void dfs(int, Array, int&);
  void dfs1(int, Array&);
  int countOfTrees();

public:
  MatrixGraph(unsigned int);
  ~MatrixGraph();
  void addEdge(int, int);
  void removeEdge(int, int);
  Array* findAllStocks();
  Array* findAllRises();
  int minCountOfTrees();

};