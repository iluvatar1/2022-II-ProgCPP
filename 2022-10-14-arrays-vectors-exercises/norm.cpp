#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <cmath>

void fill(std::vector<double> & vec);
double norm(const std::vector<double> & vec);

int main(int argc, char **argv)
{
  // leer el tamano
  if (argc < 2) {
    std::cerr << "Por favor indicar el tamanho del vector:\n" << argv[0] << " VECTORSIZE\n";
    exit(1);
  }
  const int N = std::atoi(argv[1]);
  auto fprint = [](double x){ std::cout << x << "  "; };

  // declara el vector con ese tamanho
  std::vector<double> data;
  data.resize(N);

  // llenar el vector de alguna manera
  fill(data);
  //std::for_each(data.begin(), data.end(), fprint);
  //std::cout << "\n";

  // calcular la norma
  std::cout << "norm: " << norm(data) << "\n";

  return 0;
}

void fill(std::vector<double> & vec)
{
  // a_i = 2i + 1
  int ii = 0;
  auto faux = [&ii](double & x){ x = 2*ii + 1; ii++; };
  std::for_each(vec.begin(), vec.end(), faux);
}

double norm(const std::vector<double> & vec)
{
  return std::sqrt(std::inner_product(vec.begin(), vec.end(), vec.begin(), 0.0));
}
