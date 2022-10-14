#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <cmath>

void fill(std::vector<double> & vec);
void deriv(const std::vector<double> & vec);

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

  // derivar
  deriv(data);

  return 0;
}

void fill(std::vector<double> & vec)
{
  // a_i = 2i + 1
  int ii = 0;
  auto faux = [&ii](double & x){ x = 2*ii + 1; ii++; };
  std::for_each(vec.begin(), vec.end(), faux);
}

void deriv(const std::vector<double> & vec)
{
  auto fprint = [](double x){ std::cout << x << "  "; };
  std::cout << "original data: \n";
  std::for_each(vec.begin(), vec.end(), fprint);
  std::cout << "\n";

  std::vector<double> vec_deriv;
  vec_deriv.resize(vec.size()-1);
  for(int ii = 0; ii < vec_deriv.size(); ++ii) {
    vec_deriv[ii] = vec[ii+1]*(ii+1);
  }
  std::cout << "deriv data: \n";
  std::for_each(vec_deriv.begin(), vec_deriv.end(), fprint);
  std::cout << "\n";
}
