#include "BinaryTree.hpp"
#include <iostream>

BinaryTree::BinaryTree(int length) {
  tree = new int[length];
  maxLength = length;
  this->length = 0;
}

BinaryTree::~BinaryTree() {
  delete tree;
}

void BinaryTree::pushNode(int value) {
  tree[length++] = value;
}

int BinaryTree::popNode() {
  return tree[length--];
}

void BinaryTree::symmetricWay(int index) {
  if (index < length) {
      symmetricWay(index * 2 + 1);
      std::cout << tree[index] << " ";
      symmetricWay(index * 2 + 2);
  }
}