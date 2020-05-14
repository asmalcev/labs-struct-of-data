#include "MatrixGraph.hpp"

MatrixGraph::MatrixGraph(unsigned int length) {
  matrix = new int[length * length];
  this->length = length;
}

MatrixGraph::~MatrixGraph() {
  delete[] matrix;
}

void MatrixGraph::addEdge(int i, int j) {
  matrix[i * length + j] = 1;
}

void MatrixGraph::removeEdge(int i, int j) {
  matrix[i * length + j] = 0;
}

Array* MatrixGraph::findAllStocks() {
  Array* stocks = new Array(0);

  bool isStock;
  for (unsigned char i = 0; i < length; i++) {
    isStock = true;
    for (unsigned char j = 0; j < length; j++) {
      if (matrix[i * length + j] != 0) {
        isStock = false;
        break;
      }
    }
    if (isStock) stocks->push((int) i + 1);
  }

  return stocks;
}

Array* MatrixGraph::findAllRises() {
  Array* rises = new Array(0);

  bool isRise;
  for (unsigned char i = 0; i < length; i++) {
    isRise = true;
    for (unsigned char j = 0; j < length; j++) {
      if (matrix[j * length + i] != 0) {
        isRise = false;
        break;
      }
    }
    if (isRise) rises->push((int) i + 1);
  }
  
  return rises;
}

void MatrixGraph::dfs(int v, Array used, int& count) {
  int i,j;
  used[v] = 1;
  if (used.every([] (int value) { return (bool) value; })) {
    count++;
  } else {
    for (i = 0; i < length; i++) {
      j = i + v * length;
      if (!used[i] && matrix[j] != 0) {
        dfs(i, used, count);
      }
    }
  }
}

int MatrixGraph::countOfTrees() {
  Array used(length, 0);
  int count = 0;

  for (int i = 0; i < length && !count; i++) {
    dfs(i, used, count);
  }

  return count;
}

void MatrixGraph::dfs1(int v, Array& used) {
  int i, j;
  used[v] = 1;

  for (i = 0; i < length; i++) {
    j = i + v * length;
    if (!used[i] && matrix[j] != 0) {
      dfs1(i, used);
    }
  }
}

int MatrixGraph::minCountOfTrees() {
  if (countOfTrees()) {
    return 1;
  }
  Array used(length, 0);
  int cNum = 0;

  for (int i = 0; i < length; i++) {
    if (!used[i]) {
      dfs1(i, used);
      cNum++;
    }
  }

  return cNum;
}

