#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <boost/numeric/odeint.hpp>

typedef std::vector<double> state_t; // alias for state type

void initial_conditions(state_t & y);
void print(const state_t & y, double time);
void fderiv(const state_t & y, state_t & dydt, double t);

int main(int argc, char **argv)
{
    if (argc != 7) {
      std::cerr << "ERROR. Usage:\n" << argv[0] << " T0 TF DT RAD MASS K" << std::endl;
      std::exit(1);
    }
    const double T0 = std::atof(argv[1]);
    const double TF = std::atof(argv[2]);
    const double DT = std::atof(argv[3]);
    const double RAD  = std::atof(argv[4]);
    const double MASS  = std::atof(argv[5]);
    const double K  = std::atof(argv[6]);
    const double G = 9.81;

    const int N = 2;

    auto fderiv = [RAD, MASS, K, G](const state_t & y, state_t & dydt, double t){
      dydt[0] = y[1];
      // Floor force
      double Ffloor = 0.0;
      double delta = RAD - y[0];
      if (delta > 0) {
        Ffloor = K*delta;
      }
      dydt[1] = -G + Ffloor/MASS;
    };

  state_t y(N);
  initial_conditions(y);
  boost::numeric::odeint::integrate(fderiv, y, T0, TF, DT, print);

  return 0;
}

void initial_conditions(state_t & y)
{
  y[0] = 0.9876;
  y[1] = 0.0;
}

void print(const state_t & y, double time)
{
  std::cout << time << "\t" << y[0] << "\t" << y[1] << std::endl;
}
