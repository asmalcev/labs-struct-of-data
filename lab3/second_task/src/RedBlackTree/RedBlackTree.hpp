#pragma once

enum Color {
  Red,
  Black
};

struct Node {
  int value;
  Node* right; 
  Node* left;
  Node* parent;
  Color c;

  Node(int value)
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
  void insert(unsigned);
  void symTracePrint();
  int find(unsigned, unsigned&);

};