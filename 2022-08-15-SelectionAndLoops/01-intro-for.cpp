// imprima los numeros del 1 al 10 usando for

// for(start ; cond ; change)

#include <iostream>

int main(int argc, char **argv)
{
  for(int n = 1; n <= 10; n = n+1) {
    std::cout << n << " ";
    //++n;
  }
  std::cout << "\n";

  return 0;
}
