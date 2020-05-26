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

Data* HashMap::get(unsigned key) {
  LinkedList& ls = table[hash(key)];
  if (ls.empty()) {
    return nullptr; 
  } else {
    for (size_t i = 0; i < ls.getLength(); i++) {
      Data * result = ls.next();
      if (result->key == key) {
        ls.clearIterator();
        return result;
      }
    }
    return nullptr;
  }
}

void HashMap::put(int key, const char * value) {
  table[hash(key)].pushNode(new Data(value, key));
}

void HashMap::print() {
  for (int i = 0; i < size; i++) {
    std::cout << "I = " << i << std::endl;
    LinkedList& ls = table[i];
    for (int j = 0; j < ls.getLength(); j++) {
      Data* d = ls.next();
      std::cout << "key: " << d->key << " value: " << d->value << "\t";
    }
    table[i].clearIterator();
    std::cout << std::endl;
  }
}