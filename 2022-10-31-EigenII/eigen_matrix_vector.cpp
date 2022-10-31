#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int argc, char **argv)
{
  srand(20); // controls the random seed for eigen
  Eigen::MatrixXd m = Eigen::MatrixXd::Random(3,3);
  std::cout << "m =" << std::endl << m << std::endl;  
  m = (m + Eigen::MatrixXd::Constant(3,3,1.2)) * 50;
  std::cout << "m =" << std::endl << m << std::endl;
  Eigen::VectorXd v(3);
  v << 1, 2, 3;
  std::cout << "m * v =" << std::endl << m * v << std::endl;

  return 0;
}
