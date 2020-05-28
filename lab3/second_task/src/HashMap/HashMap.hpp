#pragma once
#include "LinkedList.hpp"

class HashMap {
private:
  LinkedList* table;
  unsigned size;

  unsigned hash(unsigned);

public:
  explicit HashMap(unsigned);
  ~HashMap();
  int get(unsigned, unsigned&);
  void put(unsigned);

  void print();
};