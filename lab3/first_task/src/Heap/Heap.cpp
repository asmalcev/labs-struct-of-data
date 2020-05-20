#include "Heap.hpp"
#include <iostream>

Heap::Heap(unsigned capacity, int* arr, counter& c)
  : size(0), capacity(capacity), arr(arr), c(c)
  {}

Heap::~Heap() {}

int Heap::getMin() {
  if (size == 0) {
    throw std::out_of_range("Heap is empty");
  }
  if (size == 1) {
    return arr[--size];
  }

  int root = arr[0];
  arr[0] = arr[--size];
  c.switches++;
  c.otherEq++;
  heapify(0);
  return root;
}

void Heap::insert(int value) {
  if (size == capacity) {
    throw std::out_of_range("Heap is full");
  }

  size++;
  int i = size - 1;
  c.otherEq++;
  arr[i] = value;
  c.switches++;

  int tmp;
  while (i != 0 && arr[i] > arr[(i - 1) / 2]) {
    tmp = arr[i];
    arr[i] = arr[(i - 1) / 2];
    arr[(i - 1) / 2] = tmp;
    c.switches += 3;
    i = (i - 1) / 2;
    c.otherEq++;
  }
}

void Heap::heapify(unsigned i) {
  int j, tmp;
  while (2 * i + 1 < size) {
    j = i;
    c.otherEq++;
    if (arr[2 * i + 1] > arr[i]) {
      j = 2 * i + 1;
      c.otherEq++;
    }
    if (2 * i + 2 < size && arr[2 * i + 2] > arr[j]) {
      j = 2 * i + 2;
      c.otherEq++;
    }
    if (i == j) {
      break;
    }
    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    c.switches += 3;
    i = j;
    c.otherEq++;
  }
}