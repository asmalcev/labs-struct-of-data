#include "RedBlackTree.hpp"

#include <iostream>

RedBlackTree::RedBlackTree() {
  root = nullptr;
}

RedBlackTree::~RedBlackTree() {
  deleteSubTree(root);
}

void RedBlackTree::deleteSubTree(Node * pt) {
  if (pt->left != nullptr) deleteSubTree(pt->left);
  if (pt->right != nullptr) deleteSubTree(pt->right);
  delete pt->value;
  delete pt;
}

Node * RedBlackTree::BSTInsert(Node * root, Node * pt) {
  if (root == NULL) {
    return pt;
  }

  if (pt->value->key < root->value->key) {
    root->left = BSTInsert(root->left, pt);
    root->left->parent = root;
  } else {
    root->right = BSTInsert(root->right, pt);
    root->right->parent = root;
  }
  
  return root;
} 

void RedBlackTree::insert(unsigned key, char const * value) {
  Node* pt = new Node(new Data(value, key));

  root = BSTInsert(root, pt);
  
  fixInsertion(pt);
}

void RedBlackTree::rotateLeft(Node * pt) {
  Node * r = root;
  Node * pt_right = pt->right; 
  
  pt->right = pt_right->left; 
  
  if (pt->right != nullptr) {
    pt->right->parent = pt; 
  }
  
  pt_right->parent = pt->parent;
  
  if (pt->parent == nullptr) {
    r = pt_right;
  } else if (pt == pt->parent->left) {
    pt->parent->left = pt_right;
  } else {
    pt->parent->right = pt_right;
  }
  
  pt_right->left = pt;
  pt->parent = pt_right;
}

void RedBlackTree::rotateRight(Node * pt) {
  Node * r = root;
  Node *pt_left = pt->left;
  
  pt->left = pt_left->right;
  
  if (pt->left != nullptr) {
    pt->left->parent = pt;
  } 
  
  pt_left->parent = pt->parent;
  
  if (pt->parent == nullptr) {
    r = pt_left;
  } else if (pt == pt->parent->left) {
    pt->parent->left = pt_left;
  } else {
    pt->parent->right = pt_left;
  }
  
  pt_left->right = pt;
  pt->parent = pt_left;
}

void RedBlackTree::fixInsertion(Node * pt) {
  Node * r = root;
  Node *parent_pt = nullptr;
  Node *grand_parent_pt = nullptr;
  
  while (
    (pt != r) && (pt->c != Black)
    && (pt->parent->c == Red)
  ) { 
    parent_pt = pt->parent;
    grand_parent_pt = pt->parent->parent;
    if (parent_pt == grand_parent_pt->left) {
      Node *uncle_pt = grand_parent_pt->right; 
      if (uncle_pt != nullptr && uncle_pt->c == Red) { 
        grand_parent_pt->c = Red;
        parent_pt->c = Black;
        uncle_pt->c = Black;
        pt = grand_parent_pt;
      } else { 
        if (pt == parent_pt->right) {
          rotateLeft(parent_pt);
          pt = parent_pt;
          parent_pt = pt->parent;
        }
        rotateRight(grand_parent_pt);

        Color ctmp = parent_pt->c;
        parent_pt->c = grand_parent_pt->c;
        grand_parent_pt->c = ctmp; 

        pt = parent_pt;
      }
    } else {
      Node *uncle_pt = grand_parent_pt->left; 
      if ((uncle_pt != nullptr) && (uncle_pt->c == Red)) { 
        grand_parent_pt->c = Red;
        parent_pt->c = Black;
        uncle_pt->c = Black;
        pt = grand_parent_pt;
      } else {
        if (pt == parent_pt->left) {
          rotateRight(parent_pt);
          pt = parent_pt;
          parent_pt = pt->parent;
        }
        rotateLeft(grand_parent_pt);
        
        Color ctmp = parent_pt->c;
        parent_pt->c = grand_parent_pt->c;
        grand_parent_pt->c = ctmp; 

        pt = parent_pt;
      }
    } 
  } 
  
  root->c = Black; 
}

void RedBlackTree::symTracePrint() {
  symTracePrintRec(root);
  std::cout << std::endl;
}

void RedBlackTree::symTracePrintRec(Node * pt) {
  if (pt == nullptr) {
    return;
  }
  symTracePrintRec(pt->left);
  std::cout << pt->value->key << " - " << pt->value->value << " ";
  symTracePrintRec(pt->right);
}

Data * RedBlackTree::find(unsigned key) {
  Node * p = root;

  while (p != nullptr) {
    if (p->value->key == key) {
      return p->value;
    } else if (p->value->key < key) {
      p = p->right;
    } else {
      p = p->left;
    }
  }

  return nullptr;
}
