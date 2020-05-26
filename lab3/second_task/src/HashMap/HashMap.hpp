#pragma once
#include "LinkedList.hpp"
#include "Data.hpp"

class HashMap {
private:
  LinkedList* table;
  unsigned size;

  unsigned hash(unsigned);

public:
  explicit HashMap(unsigned);
  ~HashMap();
  Data* get(unsigned);
  void put(int, const char *);

  void print();
};