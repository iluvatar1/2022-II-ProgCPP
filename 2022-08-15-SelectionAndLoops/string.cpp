// Mi primer programa

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  std::string name;
  std::cout << "Escriba su nombre:\n";
  std::getline(std::cin, name);
  std::cout << name << "\n";
  std::cout << name + " Otra cadena" << "\n";

  return 0;
}
