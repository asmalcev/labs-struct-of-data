#include <iostream>
#include <string.h>
#include "linkedlist.cpp"

struct note getNote() {
  struct note memo;

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

std::ostream& operator << (std::ostream &out, const struct note memo) {
	out << memo.id << " " << memo.name << " " << memo.category << " " << memo.deposit << " " << memo.date;
  return out;
}

void clear() {
  while(std::cin.get() != '\n');
}

void help() {
  std::cout << ">> COMMAND - DESCRIPTION\n   c [FILENAME] - create or make clear if exists file [FILENAME]\n   o [FILENAME] - open file [FILENAME]\n   r [FILENAME] - remove file [FILENAME]\n   q - quit\n";
}

void fileHelp() {
  std::cout << ">> COMMAND - DESCRIPTION\n   c - create new note\n   p - print the bigest deposit\n   + [ID] [SUM] - get [SUM] from [ID] account\n   - [ID] [SUM] - put [SUM] on [ID] account\n   d [ID] - delete note [ID]\n   q - quit\n";
}

LinkedList readFileToList(FILE* f) {
  LinkedList list;
  struct note memo;

  while (fread(&memo, sizeof(memo), 1, f))
    list.pushNode(memo);

	fseek(f, 0, SEEK_SET);

  return list;
}

void printListToFile(LinkedList list, FILE* f) {
  struct note memo;
  for (int i = 0; i < list.getLength(); i++) {
    memo = list.next();
    fwrite(&memo, sizeof(memo), 1, f);
  }
}

void printList(LinkedList list) {
  struct note memo;
  for (int i = 0; i < list.getLength(); i++) {
    memo = list.next();
    std::cout << memo << std::endl;
  }
  list.clearIterator();
}

int getTheBigestDeposit(LinkedList list) {
  int maxDeposit;
  struct note memo;
  for (int i = 0; i < list.getLength(); i++) {
    memo = list.next();
    if(!strcmp(memo.category, "fast")) {
      memo.deposit = memo.deposit;
      if (maxDeposit < memo.deposit)
        maxDeposit = memo.deposit;
    }
  }
  return maxDeposit;
}

void fileWork(FILE* f, char* fileName) {
  system("clear");
  std::cout << ">> Working with " << fileName << std::endl;
  fileHelp();
  int flag = 1, difference;

  LinkedList list = readFileToList(f);
  freopen(fileName, "wb", f);

  char command;
  while (flag) {
    std::cout << "<< ";
    std::cin >> command;

    switch (command) {
      case 'c':
        list.pushNode(getNote());
        clear();
        break;

      case 'e':
        clear();
        break;
      
      case 'd':
        clear();
        break;
      
      case 'p':
        clear();
        std::cout << ">> The bigest deposit is " << getTheBigestDeposit(list) << std::endl;
        break;
      
      case '+':
      case '-':
        break;

      case 's':
        printList(list);
        break;

      case 'q':
        flag = 0;
        clear();
        printListToFile(list, f);
        system("clear");
        help();
        break;

      default:
        clear();
        printf("error: unknown command\n");
    }
  }
}

int main() {
  system("clear");
  help();
  char fileName[30];
  char command;
  FILE *f;
	while (true) {
		std::cout << "<< ";
		std::cin >> command;
		switch (command) {
			case 'c':
        std::cin >> fileName;
        clear();

        f = fopen(fileName, "wb");
        if (f == NULL) {
          std::cout << "error: could't create " << fileName << std::endl;
        } else {
          std::cout << ">> " << fileName << " is cleared and exists now" << std::endl;
        }
        
        fclose(f);
				break;

			case 'o':
        std::cin >> fileName;
        clear();

        f = fopen(fileName, "rb+");
        if (f == NULL) {
          std::cout << "error: could't open " << fileName << std::endl;
        } else {
          fileWork(f, fileName);
        }

        fclose(f);
        std::cout << ">> " << fileName << " closed" << std::endl;
				break;

			case 'r':
        std::cin >> fileName;
        clear();
        remove(fileName);
        std::cout << ">> " << fileName << " doesn't exist now" << std::endl;
				break;
			
			case 'q':
        std::cout << "See you soon!" << std::endl;
        return 0;

			default:
        clear();
        std::cout << "error: unknown command" << std::endl;
				break;
		}
	}
}