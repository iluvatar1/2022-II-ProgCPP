// Applies the euler algorithm to model an harmonic oscillator
#include <iostream>
#include <valarray>
#include <cmath>
#include <cstdlib>

typedef std::valarray<double> state_t; // alias for state type

void print(const state_t & y, double time);
void fderiv(const state_t & y, state_t & dydt, double t);
template <class deriv_t, class system_t, class printer_t>
void integrate_euler(deriv_t deriv, system_t & y, double tinit, double tend, double dt, printer_t writer);


int main(int argc, char **argv)
{
  if (argc != 5) {
    std::cerr << "ERROR. Usage:\n" << argv[0] << " T0 TF DT W" << std::endl;
    std::exit(1);
  }
  const double T0 = std::atof(argv[1]);
  const double TF = std::atof(argv[2]);
  const double DT = std::atof(argv[3]);
  const double W  = std::atof(argv[4]);

  const int N = 2;
  state_t y(N);

  // initial conditions
  y[0] = 0.9876; // x(0)
  y[1] = 0.0; // v(0)

  // actual derivatives: this is the system model
  auto fderiv = [W](const state_t & y, state_t & dydt, double t){
    dydt[0] = y[1];
    dydt[1] = -W*W*y[0];
  };

  // perform the actual integration
  integrate_euler(fderiv, y, T0, TF, DT, print);

  return 0;
}

void print(const state_t & y, double time)
{
  std::cout << time << "\t" << y[0] << "\t" << y[1] << std::endl;
}

// Assumption: system_t is a valarray or eigen array
// coefficient wise operation
template <class deriv_t, class system_t, class printer_t>
void integrate_euler(deriv_t deriv, system_t & y, double tinit, double tend, double dt, printer_t writer)
{
  system_t dydt;
  dydt.resize(y.size());
  double time = tinit;
  int nsteps = (tend - tinit)/dt;
  writer(y, time); // write inirial conditions
  for(int ii = 0; ii < nsteps; ++ii) {
    time = tinit + ii*dt;
    deriv(y, dydt, time);
    y = y + dt*dydt; // coefficient wise (assumption)
    writer(y, time);
  }
}
// // by component: std::vector<double> or std::array<double>
// // works for all types of arrays
// for (int ii = 0; ii < N; ++ii) {
//   y[ii] = y[ii] + dt*dydt[ii];
// }
