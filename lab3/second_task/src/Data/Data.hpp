#pragma once
#include <cstring>

struct Data {
  char* value;
  unsigned key;

  explicit Data(const char* strValue, unsigned key)
    : key(key) {
      unsigned len = strlen(strValue);
      value = new char[len];
      strncpy(value, strValue, len); 
    }
  ~Data() {
    delete value;
  }
};