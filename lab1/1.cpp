#include <iostream>

struct note {
  int id;
  char name[30];
  char category[5];
  int deposit;
  char date[9];
};

note getNote() {
  note memo;

  std::cout << "Enter id" << std::endl;
  std::cin >> memo.id;
  std::cout << "Enter name" << std::endl;
  std::cin >> memo.name;
  std::cout << "Enter category (slow/fast)" << std::endl;
  std::cin >> memo.category;
  std::cout << "Enter sum of deposit" << std::endl;
  std::cin >> memo.deposit;
  std::cout << "Enter date of last operation in format DD.MM.YY" << std::endl;
  std::cin >> memo.date;

  return memo;
}

void help() {
  std::cout << ">> COMMAND - DESCRIPTION\n   c [FILENAME] - create or make clear if exists file [FILENAME]\n   o [FILENAME] - open file [FILENAME]\n   r [FILENAME] - remove file [FILENAME]\n   p [FILENAME] - print [FILENAME]\n   q - quit\n";
}

int main() {
  system("clear");
  char command;
  help();
	while (true) {
		std::cout << "<< ";
		std::cin >> command;
		switch (command) {
			case 'c':
				break;

			case 'o':
				break;

			case 'r':
				break;

			case 'p':
				break;
			
			case 'q':
        std::cout << "See you soon!\n";
        return 0;
			
			default:
				break;
		}
	}
}