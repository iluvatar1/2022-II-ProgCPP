#include <iostream>

int    suma(int    a, int    b);
float  suma(float  a, float  b);
double suma(double a, double b);

int main(int argc, char **argv) {

  std::cout << suma(1, 2) << "\n";
  std::cout << suma(1.3f, 2.5f) << "\n";
  std::cout << suma(1.5, 2.7) << "\n";

  return 0;
}

int suma(int a, int b)
{
  return a + b;
}
float suma(float a, float b)
{
  return a + b;
}
double suma(double a, double b)
{
  return a + b;
}
