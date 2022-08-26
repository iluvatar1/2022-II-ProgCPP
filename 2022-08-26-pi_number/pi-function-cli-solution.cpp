// pi-function-cli-solution.cpp
// suma para calcular el numero pi: std::sqrt(6*result)
// result = sum 1/n^2
#include <iostream> // incluye utilidades para imprimir y leer de pantalla
#include <cmath> // incluye funciones matematicas
#include <cstdlib>

// function declaration
double sum_pi(int N);

int main(int argc, char **argv)
{
  std::cout.setf(std::ios::scientific);
  std::cout.precision(15);

  const int nmax = std::atoi(argv[1]);

  std::cout << "The value of pi is: " << sum_pi(nmax) << "\n";
  return 0;
}

// function implementation
double sum_pi(int N)
{
  double result = 0.0; // must be double to store floating point values
  int n = 0;

  for(n = 1; n <= N ; n = n+1) {
    result = result + 1.0/(n*n);
  }
  return std::sqrt(6*result);
}
