#include "Counter.hpp"

counter::counter() {
  switches = 0;
  otherEq = 0;
}

unsigned counter::getAllEq() {
  return switches + otherEq;
}
