#include <iostream>
#include <fstream>
#include "Sorts.hpp"

constexpr int n1 = 5000;
constexpr int n2 = 10000;
constexpr int n3 = 30000;
constexpr int n4 = 50000;

int main() {
  // std::ifstream input("../../numbers.txt");
  // int* arr1 = new int[n1];
  // int countOfEq = 0;

  // for (int i = 0; i < n1; i++) {
  //   input >> arr1[i];
  // }

  // delete[] arr1;

  int* arr1 = new int[10];
  int countOfEq = 0;

  arr1[0] = 9;
  arr1[1] = 0;
  arr1[2] = -15;
  arr1[3] = 7;
  arr1[4] = 51;
  arr1[5] = 91;
  arr1[6] = 2;
  arr1[7] = 14;
  arr1[8] = 9;
  arr1[9] = -11;

  heapSort(arr1, 10, countOfEq);

  for (int i = 0; i < 10; i++) {
    std::cout << arr1[i] << " ";
  }
  std::cout << std::endl;

  delete[] arr1;
}