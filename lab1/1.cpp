#include <iostream>
#include <string.h>
#include <limits>
#include <cmath>
#include "linkedlist.hpp"

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

struct note getNote(int id) {
  struct note memo;
  int control, iPart, fPart, day, month, year;
  control = iPart = fPart = day = month = year = 0;

  memo.id = id;
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
    std::cout << "Enter date of last operation in format DD.MM.YYYY" << std::endl;
    control = scanf("%2d.%2d.%4d", &day, &month, &year) == 3;
    control = day > 0 && day < 32 && month > 0 && month < 13 &&  year > 0;
    sprintf(memo.date, "%02d.%02d.%04d", day, month, year);
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
    list.push(memo);
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

void editById(LinkedList &list, int id) {
  if (list.getLength() == 0) {
    std::cout << ">> The list is empty" << std::endl;
    return;
  }
  struct note memo;

  for (int i = 0; i < list.getLength(); i++) {
    memo = list.next();
    if (memo.id == id) {
      memo = getNote(id);
      list.remove(id);
      list.push(memo);
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
  int i = 0, len, lastPosition;
	bool errCommand = false;
  while (true) {
    lastPosition = i;
    system("clear");
    std::cout << "   DATE    |   ID   |  DEPOSIT  |       NAME     | CATEGORY" << std::endl;
    std::cout << "-----------+--------+-----------+----------------+----------+" << std::endl;

    for (int j = 0; j < 10 && i < list.getLength(); j++, i++) {
      memo = list.next();
      if (memo.isDepositDouble) {
        printf("%-11s|%7lu |%11.2G|%16s|%10s\n", memo.date, memo.id, memo.deposit.depositD, memo.name, memo.category);
      } else {
        printf("%-11s|%7lu |%11lld|%16s|%10s\n", memo.date, memo.id, memo.deposit.depositI, memo.name, memo.category);
      }
    }
    std::cout << "-----------+--------+-----------+----------------+----------+" << std::endl;
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
        i = lastPosition;
        if (i == 0) {
          list.clearIterator();
        } else {
          i -= 10;
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
        i = lastPosition;
        if (i == 0) {
          list.clearIterator();
        } else {
          list.setIterator(i);
        }
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
        list.push(
          getNote(
            list.getId()
          )
        );
        break;

      case 'e':
        std::cin >> id;
        clear();
        editById(list, id);
        break;
      
      case 'd':
        std::cin >> id;
        switch (list.remove(id)) {
          case 1:
            std::cout << ">> The list is empty" << std::endl;
            break;
          case 2:
            std::cout << ">> There are not any notes with " << id << " id" << std::endl;
            break;
          default:
            std::cout << ">> " << id << " note deleted" << std::endl;
        };
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
  FILE *f;

  if (argc != 1) {
    f = fopen(argv[1], "rb+");
    if (f == NULL) {
      std::cout << "error: could't open " << argv[1] << std::endl;
    } else {
      fileWork(f, argv[1]);
      system("clear");
      help();
    }

    fclose(f);
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