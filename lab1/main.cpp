#include <iostream>

union contribution {
	long long int depositI; // 8 байт
	double depositD;        // 8 байт
};

struct note {
	size_t id;            // размер поля зависит от системы: в 32-х битной - 4 байта, в 64-х - 8 байт
	contribution deposit; // 8 байт
	char name[15];        // 15 байт
	char category[5];     // 5 байт
	char date[11];        // 11 байт
	bool isDepositDouble; // 1 байт
};

int main() {
  std::cout << sizeof(note) << std::endl;
}
