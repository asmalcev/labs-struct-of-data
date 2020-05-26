#include <iostream>
#include <fstream>
#include <ctime>
#include "HashMap.hpp"
#include "RedBlackTree.hpp"

int main() {
  HashMap a(11);
  RedBlackTree b;
  
  std::ifstream input("../../key_value.txt");
  int key;
  std::string value;
  while (input >> key >> value) {
    a.put(key, value.c_str());
    b.insert(key, value.c_str());
  }

  // ways to print the structs of data
  // a.print();
  // b.symTracePrint();

  unsigned keys[] = {22, 54, 123, 553};
  unsigned timeStart = 0;
  Data * data;

  for (unsigned i = 0; i < 4; i++) {
    timeStart = clock();
    data = a.get(keys[i]);
    if (data == nullptr) {
      std::cout << "Note with key " << keys[i] << " didn't found" << std::endl;
    } else {
      std::cout << "key: " << data->key << " value: " << data->value << std::endl;
    }
    std::cout << (clock() - timeStart) / 1000.0 << " - Time spent to find in HashMap" << std::endl;

    timeStart = clock();
    data = b.find(keys[i]);
    if (data == nullptr) {
      std::cout << "Note with key " << keys[i] << " didn't found" << std::endl;
    } else {
      std::cout << "key: " << data->key << " value: " << data->value << std::endl;
    }
    std::cout << (clock() - timeStart) / 1000.0 << " - Time spent to find in RedBlackTree" << std::endl;
  }
}