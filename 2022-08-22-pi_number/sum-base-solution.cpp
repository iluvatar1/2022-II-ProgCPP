// suma para calcular el numero pi: std::sqrt(6*result)
// result = sum 1/n^2
#include <iostream> // incluye utilidades para imprimir y leer de pantalla
#include <cmath> // incluye funciones matematicas

int main(int argc, char **argv)
{
  std::cout.setf(std::ios::scientific);
  std::cout.precision(15);
  double result = 0.0; // must be double to store floating point values
  int n = 0;
  const int nmax = 100; // make this variable a constant one

  // TODO: write a for loop performing the sum
  for(n = 1; n <= nmax ; n = n+1) {
    result = result + 1.0/(n*n);
  }

  std::cout << "The value of pi is: " << std::sqrt(6*result) << "\n";
  return 0;
}
