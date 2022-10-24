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

// data[5] -> data + 5 * sizeof(double)
// data[20] -> data + 20 * sizeof(double)
// data[-1] -> data - 1 * sizeof(double)
