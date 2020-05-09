#include <cstring>
#include "Array.hpp"

Array::Array(int len) {
  fulledSize = realSize = 0;
  arr = new int[len];
}

Array::~Array() {
  delete[] arr;
}

void Array::push(int elem) {
  if (realSize == fulledSize) {
    realSize = (int) 1.3 * realSize + 1;
    int *additionalArray = new int[realSize];
    memcpy(additionalArray, arr, fulledSize * sizeof *additionalArray);
    additionalArray[fulledSize] = elem;
    delete[] arr;
    arr = additionalArray;
    fulledSize++;
  } else {
    arr[fulledSize] = elem;
    fulledSize++;
  }
}

void Array::remove(int index) {
  if (index < fulledSize && index > 0) {
    memcpy(arr + index, arr + index + 1, (fulledSize - index) * sizeof *arr);
    fulledSize--;
  }
}

int Array::find(int elem) {
  for (int i = 0; i < fulledSize; i++) {
    if (arr[i] == elem) {
      return i;
    }
  }
  return -1;
}

int Array::getSize() const {
  return fulledSize;
}

int Array::get(int index) const {
  return arr[index];
}

void Array::set(int index, int value) const {
  arr[index] = value;
}

int &Array::operator [] (int index) {
  if(index >= fulledSize || index < 0) {
    return arr[0];
  }
  return arr[index];
}

void Array::map(int (*foo)(int)) {
  for (int i = 0; i < fulledSize; i++) {
    arr[i] = foo(arr[i]);
  }
}

void Array::insert(Array right, int position) {
  realSize += right.getSize();
  int *additionalArray = new int[realSize];
  memcpy(additionalArray, arr, fulledSize * sizeof *additionalArray);
  if (position < 0 || position > fulledSize) {
    position = fulledSize;
  }
  memcpy(additionalArray + position, right.arr, right.getSize() * sizeof *additionalArray);
  delete[] arr;
  arr = additionalArray;
  fulledSize += right.getSize() - fulledSize + position;
}

void Array::insert(int* right, int position) {
  int size = sizeof(right) / sizeof(right[0]);
  realSize += size;
  int *additionalArray = new int[realSize];
  memcpy(additionalArray, arr, fulledSize * sizeof *additionalArray);
  if (position < 0 || position > fulledSize) {
    position = fulledSize;
  }
  memcpy(additionalArray + position, right, size * sizeof *additionalArray);
  delete[] arr;
  arr = additionalArray;
  fulledSize += size - fulledSize + position;
}

std::ostream& operator << (std::ostream &out, const Array &array) {
  int length = array.getSize();
  out << "[";
  for (int i = 0; i < length - 1; i++) {
    out << array.get(i) << ", ";
  }
  out << array.get(length - 1) << "]";
  return out;
}

std::ostream& operator << (std::ostream &out, const Array* array) {
  int length = array->getSize();
  out << "[";
  for (int i = 0; i < length - 1; i++) {
    out << array->get(i) << ", ";
  }
  out << array->get(length - 1) << "]";
  return out;
}

Array operator + (Array& left, const Array& right) {
  Array result;
  result.insert(left);
  result.insert(right);
  return result;
}

inline Array& operator+= (Array& leftList, Array& rightList) {
  leftList.insert(rightList);
}