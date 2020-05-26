#pragma once
#include "Data.hpp"

enum Color {
  Red,
  Black
};

struct Node {
  Data* value;
  Node* right; 
  Node* left;
  Node* parent;
  Color c;

  Node(Data* value)
    : value(value),
      left(nullptr),
      right(nullptr),
      parent(nullptr),
      c(Red) {}
};

class RedBlackTree {
private:
  Node * root;
  void rotateLeft(Node *); 
  void rotateRight(Node *); 
  void fixInsertion(Node *);
  Node * BSTInsert(Node *, Node *);
  void symTracePrintRec(Node *);
  void deleteSubTree(Node *);

public:
  RedBlackTree();
  ~RedBlackTree();
  void insert(unsigned, char const *);
  void symTracePrint();
  Data * find(unsigned);

};