#include "HashMap.hpp"

HashMap::HashMap(unsigned size)
  : size(size), table(new LinkedList[size]) {

}

HashMap::~HashMap() {
  delete[] table;
}

unsigned HashMap::hash(unsigned key) {
  return key % size;
}

int HashMap::get(unsigned key, unsigned& c) {
  LinkedList& ls = table[hash(key)];
  c++;
  if (ls.empty()) {
    return -1; 
  } else {
    for (size_t i = 0; i < ls.getLength(); i++) {
      int result = ls.next();
      if (result == key) {
        ls.clearIterator();
        return result;
      }
      c += 2;
    }
    return -1;
  }
}

void HashMap::put(unsigned key) {
  table[hash(key)].pushNode(key);
}

void HashMap::print() {
  for (int i = 0; i < size; i++) {
    std::cout << "I = " << i << std::endl;
    LinkedList& ls = table[i];
    for (int j = 0; j < ls.getLength(); j++) {
      int d = ls.next();
      std::cout << d << " ";
    }
    table[i].clearIterator();
    std::cout << std::endl;
  }
}