#pragma once

struct Data {
  const char* value;
  const char* key;

  explicit Data(const char* value, const char* key)
    : value(value), key(key) {}
};