#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cstring>

struct note {
	int id;
	int deposit;
	char name[12];
	char category[5];
	char date[9];
};

std::ostream& operator << (std::ostream &out, const struct note memo) {
	out << memo.id << " " << memo.name << " " << memo.category << " " << memo.deposit << " " << memo.date;
  return out;
}

int main(int argc, char *argv[]) {
	char file_name[30] = "";
  if (argc == 1) {
  	std::cout << "Enter file name: ";
    std::cin >> file_name;
  } else {
    strcat(file_name, argv[1]);
  }

	char names[][30] = {"alex", "mikle", "alexey", "danil", "kirill", "artem"};
	char categories[][5] = {"fast", "slow"};

	srand(time(0));
	note tmp;
	size_t times;

	std::cout << "Enter count of notes: ";
  std::cin >> times;

	FILE* f = fopen(file_name, "wb");
	for (size_t i = 0; i < times; i++) {
		tmp.id = i;
		tmp.deposit = 1000 + rand() % 50 * 100;
		sprintf(tmp.name, "%s", names[rand() % 6]);
		sprintf(tmp.category, "%s", categories[rand() % 2]);
		sprintf(tmp.date, "%02d.%02d.%02d", rand() % 29, rand() % 13, rand() % 100);
		std::cout << tmp << std::endl;
		fwrite(&tmp, sizeof(tmp), 1, f);
	}

	fclose(f);
}