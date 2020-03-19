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
  int id;
};

std::ostream& operator << (std::ostream &out, const struct wagon w) {
	out << "{id: " << w.id << "; " << "weight: " << w.weight << "; type: " << (!w.type ? "PASSANGER" : "CARGO") << "}";

  return out;
}

int main() {
  StackVector<wagon> wagons(27);
  StackVector<wagon> passangers(7);
  StackVector<wagon> cargos(20);
  wagon tmp;

  int countOfWagons, type, control;
  std::cout << "Enter the count of wagons: ";
  scanf("%d", &countOfWagons);
  if (countOfWagons > 27) {
    std::cout << "error: Too many wagons!" << std::endl;
    return 1;
  }

  std::cout << "Enter the weights of wagons: ";
  for (int i = 0; i < countOfWagons; i++) {
    std::cin >> tmp.weight;
    tmp.type = (tmp.weight < 50) ? PASSANGER : CARGO;
    tmp.id = i;

    wagons.push(tmp);
  }

  while (!wagons.isEmpty()) {
    tmp = wagons.pull();
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