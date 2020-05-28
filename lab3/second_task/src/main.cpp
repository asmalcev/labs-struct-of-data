#include <iostream>
#include <fstream>
#include <ctime>
#include "HashMap.hpp"
#include "RedBlackTree.hpp"

int main() {
  HashMap a(1000);
  RedBlackTree b;
  unsigned counterHashMap, sumCounterHashMap = 0;
  unsigned counterRBTree, sumCounterRBTree = 0;
  
  std::ifstream input("../../numbers.txt");
  int key;
  while (input >> key) {
    a.put(key);
    b.insert(key);
  }

  unsigned keys[] = {90727868, 94762659, 99175204, 71560899, 25677895, 68558446, 16563532, 60498734, 84741409, 35122557, 74141511, 88420884, 43019829, 53117196, 80698844, 83897405, 78444457, 78810776, 72147658, 20233563, 95837331, 74735637, 54982655, 66152231, 91301875, 95038412, 68762604, 28460093, 43726093, 85508805, 61568934, 22701229, 76197466, 51984102, 32895524, 26779460, 85287383, 96832676, 18126076, 89164497, 30191249, 24801190, 58162320, 80105405, 53198855, 66122633, 97775620, 82976314, 93745086, 65878730, 78560516, 54008370, 43281929, 53805047, 59662051, 78689079, 74797834, 71691191, 95173492, 88182128, 47789032, 10080795, 19877378, 29025071, 85346534, 76316945, 33772109, 54898789, 39774938, 10100938, 64412277, 80092670, 66633491, 51622091, 91293766, 43874689, 56714704, 32793622, 33333196, 61507721, 44007671, 38971619, 47902181, 36004257, 57130764, 58992503, 40915371, 59213891, 50538291, 17197443, 69601589, 23800551, 35018162, 74777416, 27217891, 22955763, 60379187, 35790440, 45251063, 22368047};

  for (unsigned i = 0; i < 100; i++) {
    counterHashMap = 0;
    counterRBTree = 0;
    a.get(keys[i], counterHashMap);
    b.find(keys[i], counterRBTree);
    sumCounterHashMap += counterHashMap;
    sumCounterRBTree += counterRBTree;
    std::cout << "Testing: " << keys[i]
      << " HashMap: " << counterHashMap
      << " RBTree: " << counterRBTree << std::endl;
  }
  std::cout << "Sum of HashMap: " << sumCounterHashMap << " Average value: " << sumCounterHashMap / 100 << std::endl;
  std::cout << "Sum of RBTree: " << sumCounterRBTree << " Average value: " << sumCounterRBTree / 100 << std::endl;
}