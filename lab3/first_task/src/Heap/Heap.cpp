#include "Heap.hpp"
#include <iostream>

Heap::Heap(unsigned capacity)
  : size(0), capacity(capacity), arr(new int[capacity]) 
  {}

Heap::~Heap() {
  delete [] arr;
}

int Heap::getMin() {
  if (size == 0) {
    throw std::out_of_range("Heap is empty");
  }
  if (size == 1) {
    return arr[--size];
  }

  int root = arr[0];
  arr[0] = arr[--size];
  heapify(0);
  return root;
}

void Heap::insert(int value) {
  if (size == capacity) {
    throw std::out_of_range("Heap is full");
  }

  size++;
  int i = size - 1;
  arr[i] = value;

  int tmp;
  while (i != 0 && arr[i] < arr[(i - 1) / 2]) {
    tmp = arr[i];
    arr[i] = arr[(i - 1) / 2];
    arr[(i - 1) / 2] = tmp;
    i = (i - 1) / 2;
  }
}

void Heap::heapify(unsigned i) {
  int j, tmp;
  while (2 * i + 1 < size) {
    j = i;
    if (arr[2 * i + 1] < arr[i]) {
      j = 2 * i + 1;
    }
    if (2 * i + 2 < size && arr[2 * i + 2] < arr[j]) {
      j = 2 * i + 2;
    }
    if (i == j) {
        break;
    }
    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    i = j;
  }
}