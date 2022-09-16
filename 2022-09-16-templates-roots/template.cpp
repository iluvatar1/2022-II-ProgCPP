#include <iostream>

template <class T>
T suma(T a, T b);

int main(int argc, char **argv) {

  std::cout << suma(1, 2) << "\n";
  std::cout << suma(1.3f, 2.5f) << "\n";
  std::cout << suma(1.5, 2.7) << "\n";
  //std::cout << suma(1, 2.7) << "\n"; // error, this template does not exist

  return 0;
}

template <class T>
T suma(T a, T b)
{
  return a + b;
}
