#include "Sorts.hpp"

void heapSort(int* arr, int size, counter& c) {
  Heap a(size, arr, c);
  for (int i = 0; i < size; i++) {
    a.insert(arr[i]);
  }
  for (int i = 0; i < size; i++) {
    arr[size - i - 1] = a.getMin();
  }
  c.switches += size;
}

void binaryInsertion (int* arr, int n, counter& c) {
  int i, j, m, left, right, x;

  for (i = 1; i < n; i++) {
    x = arr[i]; left = 0; right = i;

    while (left < right) {
        m = (left + right) / 2;
        c.otherEq++;
      if (arr[m] <= x) {
        left = m + 1;
        c.otherEq++;
      } else {
        right = m;
        c.otherEq++;
      }
    }

    for (j = i; j > right; arr[j--] = arr[j-1]);
    arr[right] = x;
    c.switches += i - right + 2;
  }
  c.otherEq += 3 * (n - 1);
}

void bubbleSort (int* arr, int n, counter& c) {
  int i = 1, j, tmp, pos;
  c.otherEq++;
  do {
    pos = 0;
    c.otherEq++;
    for (j = n - 1; j >= i; j--) {
      if (arr[j - 1] > arr[j]) {
        tmp        = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j]     = tmp;
        pos        = j;

        c.switches += 3;
      }
    }
    i = pos;
    c.otherEq++;
  } while (pos);
}

void merge(int a[], int split, int n, counter& c) {
  int pos1 = 0;
  int pos2 = split;
  int pos3 = 0;

  int *tmp = new int[n];
  c.otherEq += 4;
  while (pos1 < split && pos2 < n) {
    if (a[pos1] < a[pos2]) {
      tmp[pos3++] = a[pos1++];
    } else {
      tmp[pos3++] = a[pos2++];
    }
  }

  while (pos2 < n) {
    tmp[pos3++] = a[pos2++];
  }

  while (pos1 < split) {
    tmp[pos3++] = a[pos1++];
  }

  for (pos3 = 0; pos3 < n; pos3++) {
    a[pos3] = tmp[pos3];
  }
  c.switches += n*2;

  delete[] tmp;
}

void mergeSort(int *a, int n, counter& c) {
  int split;

  if (n > 1)  {             
    split = n / 2;
    mergeSort(a, split, c);
    mergeSort(a + split, n - split, c);
    merge(a, split, n, c);
  }
}