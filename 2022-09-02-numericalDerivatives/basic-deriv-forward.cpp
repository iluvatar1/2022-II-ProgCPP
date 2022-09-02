#include <cstdio> // to use std::printf
#include <cmath> // to use std::sin

double f(double x);
double fderivforward(double x, double h);

int main(void)
{
  double x = M_PI/3;
  double h = 0.1;
  std::printf("HOLA %25.16e\n", fderivforward(x, h));

  return 0;
}

double f(double x)
{
  double result = std::sin(x);
  return result;
}

double fderivforward(double x, double h)
{
  double result = (f(x + h) - f(x))/h;
  return result;
}
