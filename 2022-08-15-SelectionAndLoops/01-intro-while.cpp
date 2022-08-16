// imprima los numeros del 1 al 10 usando while

#include <iostream>

int main(int argc, char **argv)
{
  int n = 1; // start
  while (n <= 10) { // condition
    std::cout << n << " ";
    ++n; // change
  }
  std::cout << "\n";

  return 0;
}
