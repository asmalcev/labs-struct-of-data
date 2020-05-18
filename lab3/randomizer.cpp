#include <fstream>
#include <ctime>
#include <cmath>

constexpr int count = 50000;
constexpr int rank = 100 * 1000 * 1000;

int main() {
  srand(time(0));
  std::ofstream targetFile("numbers.txt");

  for (int i = 0; i < count; i++) {
    targetFile << rand() % rank << " ";
  }

  targetFile.close();
}