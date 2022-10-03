// Mi primer programa

#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  char name[20];
  std::cout << "Escriba su nombre:\n";
  std::cin >> name;
  std::cout << name << "\n";

  std::vector<double> data(10);
  data.reserve(100);
  data[1]=10;

  return 0;
}
