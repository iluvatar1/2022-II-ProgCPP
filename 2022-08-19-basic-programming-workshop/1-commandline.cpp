#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
  int m = std::atoi(argv[1]);
  std::cout << "The numbers less than " << m
            << " and divisible by 3 are: \n";
  for(int ii = 3; ii <= m; ++ii) {
    if (ii%3 == 0) {
      std::cout << ii << " ";
    }
  }
  std::cout << "\n";

  return 0;
}
