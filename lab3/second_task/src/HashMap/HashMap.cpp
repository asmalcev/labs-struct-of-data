#include "HashMap.hpp"

HashMap::HashMap(unsigned size)
  : size(size), table(new LinkedList[size]) {

}

HashMap::~HashMap() {
  delete[] table;
}

unsigned HashMap::hash(const char* key) const {
  int h = 0;
  while (key) {
    h += (int) *key++;
  }
  return h % size;
}

Data& HashMap::get() {

}

void HashMap::put(Data tmp) {
  table[hash(tmp.key)].pushNode(tmp);
}

void HashMap::print() {
  for (int i = 0; i < size; i++) {
    std::cout << "I = " << i << std::endl;
    LinkedList& ls = table[i];
    for (int j = 0; j < ls.getLength(); j++) {
      Data& d = ls.next();
      std::cout << "key: " << d.key << " value: " << d.value << "\t";
    }
    table[i].clearIterator();
    std::cout << i << std::endl;
  }
}