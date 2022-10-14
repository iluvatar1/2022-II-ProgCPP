#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <random>

void fill(std::vector<double> & vec);

int main(int argc, char **argv)
{
  // leer el tamano
  if (argc < 2) {
    std::cerr << "Por favor indicar el tamanho del vector:\n" << argv[0] << " VECTORSIZE\n";
    exit(1);
  }
  const int N = std::atoi(argv[1]);

  // declara el vector con ese tamanho
  std::vector<double> data;
  data.resize(N);

  // llenar el vector de alguna manera
  fill(data);

  for (auto val : data) {
    std::cout << val << "  ";
  }
  std::cout << "\n";

  return 0;
}

void fill(std::vector<double> & vec)
{
  std::mt19937 gen(2);  // generador the bits aleatorios
  std::uniform_real_distribution<double> dis(-1.0, 1.0);
  for (auto & val: vec) {
    val = dis(gen);
  }
}
