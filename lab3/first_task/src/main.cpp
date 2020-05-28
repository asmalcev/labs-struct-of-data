#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "Sorts.hpp"

void reverse(int* arr, int length) {
  int tmp;
  for (int i = 0; i < length / 2; i++) {
    tmp = arr[i];
    arr[i] = arr[length - i - 1];
    arr[length - i - 1] = tmp;
  }
}

void test(char const * name, void (*sort)(int *, int, counter&), int * arr, int n) {
  counter c;
  unsigned timeStart;

  std::cout << std::setw(30) << name << ", N = " << n << std::endl
    << "Time (ms) | Element assignments | Other assignments | Sum of assignments" << std::endl
    << std::setfill('-') << std::setw(72) << "-" << std::endl << std::setfill(' ');
  timeStart = clock();
  sort(arr, n, c);
  std::cout << std::setw(9) << std::setprecision(5) << (clock() - timeStart) / 1000.0 << " | "
    << std::setw(19) << c.switches << " | "
    << std::setw(17) << c.otherEq << " | "
    << std::setw(18) << c.getAllEq() << " <- disordered array" << std::endl;

  timeStart = clock();
  sort(arr, n, c);
  std::cout << std::setw(9) << std::setprecision(5) << (clock() - timeStart) / 1000.0 << " | "
    << std::setw(19) << c.switches << " | "
    << std::setw(17) << c.otherEq << " | "
    << std::setw(18) << c.getAllEq() << " <- ordered array" << std::endl;

  reverse(arr, n);
  timeStart = clock();
  sort(arr, n, c);
  std::cout << std::setw(9) << std::setprecision(5) << (clock() - timeStart) / 1000.0 << " | "
    << std::setw(19) << c.switches << " | "
    << std::setw(17) << c.otherEq << " | "
    << std::setw(18) << c.getAllEq() << " <- reversed array" << std::endl << std::endl;

}

int main() {
  std::ifstream input("../../numbers.txt");
  int ns[] = {5000, 10000, 30000, 50000};
  int * arr = new int[ns[3]];

  for (int k = 0; k < 4; k++) {
    for (int i = 0; i < ns[k]; i++) { input >> arr[i]; }
    test("HeapSort", heapSort, arr, ns[k]);
    input.seekg (0, input.beg);
    for (int i = 0; i < ns[k]; i++) { input >> arr[i]; }
    test("BinaryInsertion", binaryInsertion, arr, ns[k]);
    input.seekg (0, input.beg);
    for (int i = 0; i < ns[k]; i++) { input >> arr[i]; }
    test("BubbleSort", bubbleSort, arr, ns[k]);
    input.seekg (0, input.beg);
    for (int i = 0; i < ns[k]; i++) { input >> arr[i]; }
    test("MergeSort", mergeSort, arr, ns[k]);
    input.seekg (0, input.beg);
  }
  


  delete[] arr;
}