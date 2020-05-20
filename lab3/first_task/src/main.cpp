#include <iostream>
#include <fstream>
#include <ctime>
#include "Sorts.hpp"

// values of N
// constexpr int n = 5000;
// constexpr int n = 10000;
// constexpr int n = 30000;
constexpr int n = 50000;

void reverse(int* arr, int length) {
  int tmp;
  for (int i = 0; i < length / 2; i++) {
    tmp = arr[i];
    arr[i] = arr[length - i - 1];
    arr[length - i - 1] = tmp;
  }
}

int main() {
  std::cout << "N = " << n << std::endl;

  // choose sorting algorithm
  // void (*sort)(int*, int, counter&) = heapSort;
  // void (*sort)(int*, int, counter&) = binaryInsertion;
  void (*sort)(int*, int, counter&) = bubbleSort;
  // void (*sort)(int*, int, counter&) = mergeSort;

  std::ifstream input("../../numbers.txt");
  int* arr = new int[n];
  counter c1;
  counter c2;
  counter c3;

  for (int i = 0; i < n; i++) {
    input >> arr[i];
  }

  std::cout << "##### disordered array #####" << std::endl;
  unsigned timeStart = clock(); 
  sort(arr, n, c1);
  std::cout << "Time                               : " << (clock() - timeStart) / 1000.0 << std::endl;
  std::cout << "Count of changing array assignments: " << c1.switches << std::endl;
  std::cout << "Count of other assignments         : " << c1.otherEq << std::endl;
  std::cout << "Sum of assignments                 : " << c1.getAllEq() << std::endl;
  std::cout << "############################" << std::endl << std::endl;

  std::cout << "##### ordered array #####" << std::endl;
  timeStart = clock();
  sort(arr, n, c2);
  std::cout << "Time                               : " << (clock() - timeStart) / 1000.0 << std::endl;
  std::cout << "Count of changing array assignments: " << c2.switches << std::endl;
  std::cout << "Count of other assignments         : " << c2.otherEq << std::endl;
  std::cout << "Sum of assignments                 : " << c2.getAllEq() << std::endl;
  std::cout << "#########################" << std::endl << std::endl;

  reverse(arr, n);
  std::cout << "##### reversed array #####" << std::endl;
  timeStart = clock();
  sort(arr, n, c3);
  std::cout << "Time                               : " << (clock() - timeStart) / 1000.0 << std::endl;
  std::cout << "Count of changing array assignments: " << c3.switches << std::endl;
  std::cout << "Count of other assignments         : " << c3.otherEq << std::endl;
  std::cout << "Sum of assignments                 : " << c3.getAllEq() << std::endl;
  std::cout << "##########################" << std::endl << std::endl;

  delete[] arr;
}