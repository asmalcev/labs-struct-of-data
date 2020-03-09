#include <iostream>
#include "stack.cpp"
#include "stackVector.cpp"

enum typeOfWagon {
  PASSANGER,
  CARGO
};

struct wagon {
  typeOfWagon type;
  int weight;
};

std::ostream& operator << (std::ostream &out, const struct wagon w) {
	out << "{weight: " << w.weight << "; type: " << (!w.type ? "PASSANGER" : "CARGO") << "}";

  return out;
}

int main() {
  Stack<wagon> passangers(11);
  Stack<wagon> cargos(20);

  int countOfWagons, type, control;
  std::cout << "Enter the count of wagons: ";
  scanf("%d", &countOfWagons);

  std::cout << "Enter the wights of wagons: ";
  for (int i = 0; i < countOfWagons; i++) {
    wagon tmp;
    std::cin >> tmp.weight;
    tmp.type = (tmp.weight < 50) ? PASSANGER : CARGO;

    if (tmp.type == PASSANGER) {
      if (!passangers.isFull()) {
        passangers.push(tmp);
      } else {
        std::cout << "Passanger stack is full" << std::endl;
      }
    } else {
      if (!cargos.isFull()) {
        cargos.push(tmp);
      } else {
        std::cout << "Passanger stack is full" << std::endl;
      }
    }
  }

  while (!passangers.isEmpty()) {
    std::cout << passangers.pull() << " ";
  }
  std::cout << std::endl;

  while (!cargos.isEmpty()) {
    std::cout << cargos.pull() << " ";
  }
  std::cout << std::endl;
}