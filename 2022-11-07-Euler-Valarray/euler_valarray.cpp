#include <fstream>
#include <iostream>
#include <cmath>
#include <valarray>
#include <numeric>
#include <string>

typedef std::valarray<double> state_t;

void simulate(state_t & R, state_t & V, double dt, double t0, double tf, double mass,
              const std::string & fname);

int main(int argc, char **argv) {
  if (argc != 5) {
    std::cerr << "Error. Usage:\n" << argv[0] << " dt t0 tf mass\n";
    return 1;
  }
  const double DT = std::atof(argv[1]);
  const double T0 = std::atof(argv[2]);
  const double TF = std::atof(argv[3]);
  const double M  = std::atof(argv[4]);


  // initial conditions
  state_t R = {0, 0, 4.3}, V = {0.123, 0.0, 0.98};

  // perform simulation
  simulate(R, V, DT, T0, TF, M, "datos.txt");

  return 0;
}

void simulate(state_t & R, state_t & V, double dt, double t0, double tf, double mass,
              const std::string & fname)
{
  state_t F = {0, 0, 0};
  const state_t G = {0, 0, -9.81};

  std::ofstream fout(fname);
  fout.setf(std::ios::scientific);
  fout.precision(15);

  const int nsteps = int((tf-t0)/dt);
  for (int ii = 0; ii < nsteps; ++ii) {
    // compute force
    F = 0;
    F += mass*G - 0.98*mass*V;
    // apply Euler
    R = R + V*dt;
    V = V + F*dt/mass;
    // print
    fout << t0+ii*dt << "\t" << R[0] << "\t" << R[1] << "\t" << R[2] << "\t"
         << V[0] << "\t" << V[1] << "\t" << V[2] << "\t"
         << F[0] << "\t" << F[1] << "\t" << F[2] << "\t"
         << "\n";
  }
  fout.close();
}
