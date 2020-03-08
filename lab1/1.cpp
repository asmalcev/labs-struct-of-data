#include <iostream>
#include <string.h>
#include <limits>
#include <cmath>
#include "linkedlist.cpp"

void clear() {
  while(std::cin.get() != '\n');
}

int rankOfNumber(int number) {
  int rank = 10;
  while ((number /= 10) > 0) {
    rank *= 10;
  }

  return rank;
}

struct note getNote() {
  struct note memo;
  int control = 0, iPart, fPart;

  while (!control) {
    std::cout << "Enter id" << std::endl;
    control = scanf("%d", &memo.id);
    clear();
  }
  control = 0;
  while (!control) {
    std::cout << "Enter name" << std::endl;
    control = scanf("%11s", memo.name);
    clear();
  }
  control = 0;
  while (!control) {
    std::cout << "Enter category (slow/fast)" << std::endl;
    control = scanf("%4s", memo.category);
    control = !(strcmp(memo.category, "fast") && strcmp(memo.category, "slow"));
    clear();
  }
  control = 0;
  while (!control) {
    std::cout << "Enter sum of deposit" << std::endl;
    control = scanf("%d.%d", &iPart, &fPart);
    clear();
    switch(control) {
      case 2:
        memo.deposit.depositD = (double) iPart + (double) fPart / rankOfNumber(fPart);
        memo.isDepositDouble = true;
        break;

      case 1:
        memo.deposit.depositI = iPart;
        memo.isDepositDouble = false;
        break;

      default:
        break;
    }
  }
  control = 0;
  while (!control) {
    std::cout << "Enter date of last operation in format DD.MM.YY" << std::endl;
    control = scanf("%8s", memo.date);
    clear();
  }

  return memo;
}

void help() {
  std::cout << ">> COMMAND - DESCRIPTION\n   c [FILENAME] - create or make clear if exists file [FILENAME]\n   o [FILENAME] - open file [FILENAME]\n   r [FILENAME] - remove file [FILENAME]\n   q - quit\n";
}

void fileHelp() {
  std::cout << ">> COMMAND - DESCRIPTION\n   c - create new note\n   e [ID] - edit [ID] note\n   s - see all notes in casual format\n   l - see notes in listing mode\n   p - print the bigest deposit\n   + [ID] [SUM] - get [SUM] from [ID] account\n   - [ID] [SUM] - put [SUM] on [ID] account\n   d [ID] - delete note [ID]\n   w - clear console\n   q - quit\n";
}

LinkedList readFileToList(FILE* f) {
  LinkedList list;
  struct note memo;

  while (fread(&memo, sizeof(memo), 1, f)) {
    list.pushNode(memo);
  }

	fseek(f, 0, SEEK_SET);

  return list;
}

void printListToFile(LinkedList &list, FILE* f) {
  struct note memo;
  for (int i = 0; i < list.getLength(); i++) {
    memo = list.next();
    fwrite(&memo, sizeof(memo), 1, f);
  }
}

void deleteById(LinkedList &list, int id) {
  if (list.getLength() == 0) {
    std::cout << ">> The list is empty" << std::endl;
    return;
  }
  struct note memo; 

  for (int i = 0; i < list.getLength(); i++) {
    memo = list.next();
    if (memo.id == id) {
      list.remove(i);
      list.clearIterator();
      std::cout << ">> " << id << " note deleted" << std::endl;
      return;
    }
  }

  std::cout << ">> There are not any notes with " << id << " id" << std::endl;
}


void editById(LinkedList &list, int id) {
  if (list.getLength() == 0) {
    std::cout << ">> The list is empty" << std::endl;
    return;
  }
  struct note memo;
  std::cout << "warning: ID field is const" << std::endl;

  for (int i = 0; i < list.getLength(); i++) {
    memo = list.next();
    if (memo.id == id) {
      memo = getNote();
      memo.id = id;
      list[i] = memo;
      list.clearIterator();
      return;
    }
  }

  std::cout << ">> There are not any notes with " << id << " id" << std::endl;
}

void changeDepositById(LinkedList &list, int id, double difDeposit, char command) {
  if (list.getLength() == 0) {
    std::cout << ">> The list is empty" << std::endl;
    return;
  }
  struct note memo;

  for (int i = 0; i < list.getLength(); i++) {
    memo = list.next();
    if (memo.id == id) {
      if (memo.isDepositDouble) {
        list[i].deposit.depositD += difDeposit * (command == '+' ? 1 : -1);
      } else {
        list[i].deposit.depositI = (double) memo.deposit.depositI + (double) difDeposit * (command == '+' ? 1 : -1);
        list[i].isDepositDouble = true;
      }
      
      list.clearIterator();
      return;
    }
  }

  std::cout << ">> There are not any notes with " << id << " id" << std::endl;
}

void printTheBigestDeposit(LinkedList &list) {
  if (list.getLength() == 0) {
    std::cout << ">> The list is empty" << std::endl;
    return;
  }

  double maxDeposit = list.findTheBigestDeposit();

	if (abs(maxDeposit + 1) < __DBL_EPSILON__) {
  	std::cout << ">> There are not any notes in 'fast' category" << std::endl;
	} else {
  	std::cout << ">> The bigest deposit is " << maxDeposit << std::endl;
	}
}

void listingMode(LinkedList &list) {
  char command;
  struct note memo;
  int i = 0, len;
	bool errCommand = false;
  while (true) {
    system("clear");
    std::cout << " ID |  DEPOSIT  |     NAME    | CATEGORY |   DATE   " << std::endl;
    std::cout << "----+-----------+-------------+----------+----------" << std::endl;

    for (int j = 0; j < 10 && i < list.getLength(); j++, i++) {
      memo = list.next();
      if (memo.isDepositDouble) {
        printf("%4d|%11.2G|%13s|%10s|%10s\n", memo.id, memo.deposit.depositD, memo.name, memo.category, memo.date);
      } else {
        printf("%4d|%11lld|%13s|%10s|%10s\n", memo.id, memo.deposit.depositI, memo.name, memo.category, memo.date);
      }
    }
    std::cout << "----+-----------+-------------+----------+----------" << std::endl;
    std::cout << "                < - prev; next - >" << std::endl;
    std::cout << "                     q - quit" << std::endl;

		if (errCommand) {
      std::cout << "error: unknown command" << std::endl;
			errCommand = false;
		}
    std::cout << "<< ";
    std::cin >> command;

    len = list.getLength();
    switch (command) {
      case '<':
        clear();
        if (i - 20 < 0) {
          i = 0;
          list.clearIterator();
        } else {
          if (i % 10 != 0) {
            i = (i / 10) * 10 - 10;
          } else {
            i -= 20;
          }
          list.setIterator(i);
        }
        break;

      case '>':
        clear();
        if (i == len) {
          i = len - (len % 10);
					list.setIterator(i);
        }
        break;

      case 'q':
        list.clearIterator();
        return;
      
      default:
        clear();
				errCommand = true;
        break;
    }
  }
}

void fileWork(FILE* f, char* fileName) {
  system("clear");
  std::cout << ">> Working with " << fileName << std::endl;
  fileHelp();

  LinkedList list = readFileToList(f);

  char command;
  int id;
  double sumToChange;
  while (true) {
    std::cout << "<< ";
    std::cin >> command;

    switch (command) {
      case 'c':
        clear();
        list.pushNode(getNote());
        break;

      case 'e':
        std::cin >> id;
        clear();
        editById(list, id);
        break;
      
      case 'd':
        std::cin >> id;
        deleteById(list, id);
        clear();
        break;
      
      case 'p':
        clear();
        printTheBigestDeposit(list);
        break;
      
      case '+':
      case '-':
        std::cin >> id >> sumToChange;
        clear();
        changeDepositById(list, id, sumToChange, command);
        break;

      case 's':
        if (list.getLength() == 0) {
          std::cout << ">> The list is empty" << std::endl;
        } else {
          list.print();
        }
        clear();
        break;

      case 'l':
        if (list.getLength() == 0) {
          std::cout << ">> The list is empty" << std::endl;
        } else {
          listingMode(list);
          clear();
          system("clear");
          std::cout << ">> Working with " << fileName << std::endl;
          fileHelp();
        }
        break;

      case 'w':
        system("clear");
        std::cout << ">> Working with " << fileName << std::endl;
        fileHelp();
        break;

      case 'q':
        clear();
        freopen(fileName, "wb", f);
        printListToFile(list, f);
				list.clear();
        return;

      default:
        clear();
        std::cout << "error: unknown command" << std::endl;
    }
  }
}

int main(int argc, char *argv[]) {
	char fileName[30] = "";
	char command;
	bool didGetFileName = false;
  FILE *f;

  if (argc != 1) {
    strcat(fileName, argv[1]);
		didGetFileName = true;
  }
  system("clear");

  help();
  
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
          break;
        } else {
          fileWork(f, fileName);
          system("clear");
          help();
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