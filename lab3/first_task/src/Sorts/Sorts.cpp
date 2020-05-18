#include "Sorts.hpp"
#include "Heap.hpp"

void heapSort(int* arr, int size, int& countOfEq) {
  Heap a(size);
  for (int i = 0; i < size; i++) {
    a.insert(arr[i]);
  }
  for (int i = 0; i < size; i++) {
    arr[i] = a.getMin();
  }
}