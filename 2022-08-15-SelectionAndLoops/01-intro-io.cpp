#include <iostream>

int main(int argc, char **argv)
{
  //cout << "Hola mundo de cout" << endl; // sal estandar
  //clog << "Hola mundo de clog" << endl; // error estandar

  int edad = 0;
  std::cout << "Por favor escriba su edad y presione enter: \n";
  //std::cout << std::endl;
  std::cin >> edad;
  std::cout << "Usted tiene " << edad << " anhos \n";

  // si su edad es mayor o igual a 18, imprimir
  // usted puede votar
  // si no, imprimir usted no puede votar
  if (edad >= 18) {
    std::cout << "Usted SI puede votar\n";
  } else {
    std::cout << "Usted NO puede votar\n";
  }

  return 0;
}
