#include <iostream>
#include <eigen3/Eigen/Dense>
#include <cstdlib>

int main(int argc, char **argv)
{
  // X = Dynamic size
  // d = double
  const int NROWS = std::atoi(argv[1]);
  const int NCOLS = std::atoi(argv[2]);
  
  Eigen::MatrixXd m(NROWS, NCOLS);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;

  return 0; 
}
