#include <iostream>

int main(int arg, char **argv) {

  double a = 10.9;
  double data[20] = {0.0};
  double b = 11.987;
  std::cout << "data[0] = " << data[0] << std::endl;
  std::cout << "&data[0] = " << &data[0] << std::endl;
  std::cout << "&data[1] = " << &data[1] << std::endl;
  std::cout << "data = " << data << std::endl; // this is the same as &data[0]
  std::cout << "data[20] = " << data[20] << std::endl; // copilot
  std::cout << "data[-1] = " << data[-1] << std::endl; //

  return 0;
}

// data[5] -> data + 5 * sizeof(double)
// data[20] -> data + 20 * sizeof(double)
// data[-1] -> data - 1 * sizeof(double)
