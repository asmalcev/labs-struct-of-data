#include "ListGraph.hpp"

ListGraph::ListGraph(unsigned char length) {
  lists = new LinkedList[length];
  this->length = length;
}

ListGraph::~ListGraph() {
  delete[] lists;
}

void ListGraph::addEdge(int i, int j) {
  lists[i].pushNode(j);
}

void ListGraph::removeEdge(int i, int j) {
  lists[i].remove(j);
}

Array* ListGraph::findAllStocks() {
  Array* stocks = new Array(0);

  for (unsigned char i = 0; i < length; i++) {
    if (lists[i].empty()) stocks->push((int) i + 1);
  }

  return stocks;
}

Array* ListGraph::findAllRises() {
  Array* rises = new Array(0);

  bool isRise;
  for (unsigned char i = 0; i < length; i++) {
    isRise = true;
    for (unsigned char j = 0; j < length; j++) {
      for (unsigned char k = 0; k < lists[j].getLength(); k++) {
        if (lists[j].next() == i) {
          isRise = false;
          break;
        }
      }
      lists[j].clearIterator();
    }
    if (isRise) rises->push((int) i + 1);
  }
  
  return rises;
}

void ListGraph::dfs(int v, Array used, int& count) {
  int i,j;
  used[v] = 1;
  if (used.every([] (int value) { return (bool) value; })) {
    count++;
  } else {
    for (i = 0; i < lists[v].getLength(); i++) {
      int index = lists[v].next();
      if (!used[index]) {
        dfs(index, used, count);
      }
    }
    lists[j].clearIterator();
  }
}

int ListGraph::countOfTrees() {
  Array used(length, 0);
  int count = 0;
  for (int i = 0; i < length; i++) {
    dfs(i, used, count);
  }

  return count;
}