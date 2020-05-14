#pragma once
#include "LinkedList.hpp"
#include "Array/Array.hpp"

class ListGraph {
private:
  LinkedList* lists;
  unsigned char length;
  void dfs(int, Array, int&);
  void dfs1(int, Array&);
  int countOfTrees();

public:
  ListGraph(unsigned char);
  ~ListGraph();
  void addEdge(int, int);
  void removeEdge(int, int);
  Array* findAllStocks();
  Array* findAllRises();
  int minCountOfTrees();

};