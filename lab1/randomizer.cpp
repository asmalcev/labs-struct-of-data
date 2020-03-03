#include <fstream>
#include <iostream>

struct note {
	int id;
	int deposit;
	char name[30];
	char category[5];
	char date[9];
};

int main() {
  note InputStruct;

	std::ifstream is;
  is.open("table.bin", std::ios::binary);
  is.read(&InputStruct, sizeof(InputStruct));
  is.close();
}