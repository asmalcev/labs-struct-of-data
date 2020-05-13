#pragma once
#include <iostream>

class Array {

private:
  int fulledSize, realSize;
  int *arr;

public:

  Array(int len = 0);
  Array(int len, int value);
  Array(const Array &other);
  ~Array();
  void push(int elem);
  void remove(int index);
  int find(int elem);
  int getSize() const;
  int get(int index) const;
  void set(int index, int value) const;
  int &operator [] (int index);
  void map(int (*foo)(int));
  bool some(bool (*foo)(int));
  bool every(bool (*foo)(int));
  void insert(Array right, int position = -1);
  void insert(int* right, int position = -1);
};

std::ostream& operator << (std::ostream &out, const Array &array);
std::ostream& operator << (std::ostream &out, const Array* array);
Array operator + (Array& left, const Array& right);
inline Array& operator+= (Array& leftList, Array& rightList);