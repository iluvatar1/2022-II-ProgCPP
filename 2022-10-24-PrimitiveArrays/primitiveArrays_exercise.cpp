#include <iostream>
#include <cstdlib>

void fill(double * array, int size);
double average(double * array, int size);


int main(int arg, char **argv) {

  int N = std::atoi(argv[1]);

  double * data;
  data = new double [N]; // ask for memory

  fill(data, N);
  double avg = average(data, N);
  std::cout << "The average is " << avg << std::endl;

  delete [] data; // free memory

  return 0;
}

void fill(double * array, int size) {
  for (int ii = 0; ii < size; ii++) {
    array[ii] = ii;
  }
}

double average(double * array, int size) {
  double suma = 0.0;
  for (int ii = 0; ii < size; ii++) {
    suma += array[ii];
  }
  return suma/size;
}
