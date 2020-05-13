#include <iostream>
#include <fstream>
#include "BinaryTree.hpp"

int main() {
  std::cout << "Do you want to input (0) values or read from file (1)?" << std::endl;
  int inputFlag;
  std::cin >> inputFlag;
  
  BinaryTree* tree;
  int treeLength;
  if (!inputFlag) {    
    std::cout << "Input count of numbers:" << std::endl;
    std::cin >> treeLength;

    tree = new BinaryTree(treeLength);

    int tmp;
    for (int i = 0; i < treeLength; i++) {
      std::cin >> tmp;
      tree->pushNode(tmp); 
    }
  } else {
    std::fstream input;
    input.open("../src/inputFiles/input1.txt");
    // input.open("../src/inputFiles/input2.txt");

    input >> treeLength;
    tree = new BinaryTree(treeLength);

    int tmp;
    for (int i = 0; i < treeLength; i++) {
      input >> tmp;
      tree->pushNode(tmp); 
    }

    input.close();
  }

  std::cout << "Symmetric way: ";
  tree->symmetricWay();
  std::cout << std::endl;

  delete tree;
}