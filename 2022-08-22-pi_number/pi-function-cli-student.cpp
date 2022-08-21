// pi-function-cli-student.cpp
// suma para calcular el numero pi: std::sqrt(6*result)
// result = sum 1/n^2
#include <iostream> // incluye utilidades para imprimir y leer de pantalla
#include <cmath> // incluye funciones matematicas
#include <cstdlib>

// function declaration
TODO

int main(int argc, char **argv)
{
  std::cout.setf(std::ios::scientific);
  std::cout.precision(15);

  const int nmax = std::atoi(argv[1]);

  std::cout << "The value of pi is: " << sum_pi(nmax) << "\n";
  return 0;
}

// function implementation
TODO
