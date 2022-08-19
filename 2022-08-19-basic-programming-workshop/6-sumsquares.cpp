#include <iostream>
#include <cstdlib>

// declaration
int sum_squares(int n);

int main(int argc, char *argv[]) {
  int m = std::atoi(argv[1]);

  std::cout << "La suma de los cuadrados de los numeros menores o iguales a "
            << m << " es: " << sum_squares(m) << "\n";

  return 0;
}

// implementation
int sum_squares(int n)
{
  int result = 0;
  for(int ii = 1; ii <= n; ++ii) {
    result = result + ii*ii;
  }
  return result;
}
