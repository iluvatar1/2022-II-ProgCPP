#include <iostream>
#include <cstdio>
#include <cmath>

double f(double x);
double forward_deriv(double x, double h);
double central_deriv(double x, double h);
double richardson_central_deriv(double x, double h);

int main(void)
{
  std::cout.setf(std::ios::scientific);
  std::cout.precision(15);
  double h, x, df, dc, drc, dexact;

  x = 3.7;
  for (int ii = 1; ii <= 18; ii++) {
    h = std::pow(10.0, -ii);
    df = forward_deriv(x, h);
    dc = central_deriv(x, h);
    drc = richardson_central_deriv(x, h);
    dexact = 2*std::cos(2*x);
    std::cout << h << "\t"
              << std::fabs(1.0 - df/dexact) << "\t"
              << std::fabs(1.0 - dc/dexact) << "\t"
              << std::fabs(1.0 - drc/dexact) << "\n";

    // std::printf("%25.16e%25.16e%25.16e%25.16e\n", h,
    //             std::fabs(df-dexact)/dexact,
    //             std::fabs(dc-dexact)/dexact,
    //             std::fabs(dr-dexact)/dexact);
  }

  return 0;
}

double f(double x)
{
  return std::sin(2*x);
}

double forward_deriv(double x, double h)
{
  return (f(x+h) - f(x))/h;
}

double central_deriv(double x, double h)
{
  return (f(x + h/2) - f(x - h/2))/h;
}

double richardson_central_deriv(double x, double h)
{
  double f1, f2;
  f1 = central_deriv(x, h);
  f2 = central_deriv(x, h/2);
  return (4*f2 - f1)/3.0;
}
