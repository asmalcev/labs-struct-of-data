#include <iostream>
#include <fstream>
#include "MatrixGraph/MatrixGraph.hpp"
#include "ListGraph/ListGraph.hpp"
#include "Array/Array.hpp"

int main() {
  std::fstream input;
  input.open("../src/inputFiles/input1.txt");

  unsigned int sizeOfGraph = 0;
  input >> sizeOfGraph;

  MatrixGraph m_graph(sizeOfGraph);

  int tmp = 0;
  for (unsigned char i = 0; i < sizeOfGraph; i++) {
    for (unsigned char j = 0; j < sizeOfGraph; j++) {
      input >> tmp;
      if (tmp != 0) {
        m_graph.addEdge(i, j);
      }
    }
  }


  std::cout << m_graph.findAllStocks() << std::endl;
  std::cout << m_graph.findAllRises() << std::endl;

  input.close();
}