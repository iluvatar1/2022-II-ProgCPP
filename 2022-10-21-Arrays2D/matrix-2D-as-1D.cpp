#include <iostream>
#include <vector>
#include <cstdlib>

void fill_matrix(std::vector<double> & data, int m, int n);
void print_matrix(const std::vector<double> & data, int m, int n);
void transpose_matrix(const std::vector<double> & indata, int m, int n,
                      std::vector<double> & outdata);

int main(int argc, char **argv)
{
  const int M = std::atoi(argv[1]);
  const int N = std::atoi(argv[2]);

  std::vector<double> array2d(M*N, 0.0);

  fill_matrix(array2d, M, N);
  print_matrix(array2d, M, N);

  std::vector<double> array2d_T(M*N, 0.0);
  transpose_matrix(array2d, M, N, array2d_T);
  print_matrix(array2d_T, M, N);

  return 0;
}

void fill_matrix(std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      data[ii*n + jj] = ii*n+jj; // A_(i, j) = i*n + j = id
    }
  }
}

void print_matrix(const std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      std::cout << data[ii*n + jj] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void transpose_matrix(const std::vector<double> & datain, int m, int n,
                      std::vector<double> & dataout)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      dataout[jj*n + ii] = datain[ii*n + jj]; // Error here
    }
  }
}
