#pragma once
#include "LinkedList.hpp"
#include "Data.hpp"

class HashMap {
private:
  LinkedList* table;
  unsigned size;

  unsigned hash(const char*) const;

public:
  explicit HashMap(unsigned);
  ~HashMap();
  Data& get();
  void put(Data);

  void print();
};