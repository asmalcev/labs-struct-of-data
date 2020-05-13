#pragma once

class BinaryTree {
private:
  int* tree;
  int length;
  int maxLength;

public:
  BinaryTree(int);
  ~BinaryTree();
  void pushNode(int);
  int popNode();
  void symmetricWay(int = 0);

};