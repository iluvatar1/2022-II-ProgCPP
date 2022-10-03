#include <iostream>
#include <cmath>

double f(double x) {return std::sin(std::sqrt(x));}
double iexact(double x) { return 2*std::sin(std::sqrt(x)) - 2*std::sqrt(x)*std::cos(std::sqrt(x));}

class Gauss_7{
  const double x0 = -0.949107912342759;
  const double x1 = -0.741531185599394;
  const double x2 = -0.405845151377397;
  const double x3 = 0.0;
  const double x4 = -x2;
  const double x5 = -x1;
  const double x6 = -x0;
  const double w0 = 0.129484966168870;
  const double w1 = 0.279705391489277;
  const double w2 = 0.381830050505119;
  const double w3 = 0.417959183673469;
  const double w4 = w2;
  const double w5 = w1;
  const double w6 = w0;

  public:
  template <class T>
  double operator()(double a, double b, T fun) {
    auto scale = [a, b](double x){return (b-a)*x/2 + (a+b)/2; };
    double suma = 0.0;
    suma += w0*f(scale(x0));
    suma += w1*f(scale(x1));
    suma += w2*f(scale(x2));
    suma += w3*f(scale(x3));
    suma += w4*f(scale(x4));
    suma += w5*f(scale(x5));
    suma += w6*f(scale(x6));
    return (b-a)*suma/2;
  }
};


int main(int argc, char **argv) {
  std::cout.setf(std::ios::scientific);
  std::cout.precision(15);

  Gauss_7 g7;

  std::cout << "G7: " <<  g7(2.0, 8.7, f) << std::endl;
  std::cout << "Exact: " << iexact(8.7) - iexact(2.0) << std::endl;

  return 0;
}
