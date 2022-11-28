#include "Particle.h"
#include "Integrator.h"
#include "Collider.h"
#include <vector>
#include <string>
#include <fstream>

void print_to_csv(int step, const std::vector<Particle> & bodies);

int main(int argc, char **argv) {
  std::vector<Particle> bodies;
  bodies.resize(1); // only one particle for now

  // parameters
  std::map<std::string, double> p;
  p["T0"] = 0.0;
  p["TF"] = 10.8767;
  p["DT"] = 0.01;
  p["K"] = 207.76;
  p["G"] = 9.81;
  p["B"] = 0.671;

  // Force collider
  Collider collider(p);

  // Time initialization
  TimeIntegrator integrator(p["DT"]);

  // initial conditions and properties
  bodies[0].R[2] = 0.987;
  bodies[0].rad  = 0.103;
  bodies[0].mass = 0.337;
  collider.computeForces(bodies); // force at t = 0
  integrator.startIntegration(bodies); // start integration algorithm
  std::cout << p["T0"] << "\t" << bodies[0] << "\n";
  print_to_csv(0, bodies);

  // Time iteration
  const int niter = int((p["TF"] - p["T0"])/p["DT"]);
  for(int ii = 1; ii < niter; ++ii) {
    collider.computeForces(bodies);
    integrator.timeStep(bodies);
    double time = p["T0"] + ii*p["DT"];
    std::cout << time << "\t" << bodies[0] << "\n";
    print_to_csv(ii, bodies);
  }

  return 0;
}

void print_to_csv(int step, const std::vector<Particle> & bodies)
{
  std::string fname = "particles_" + std::to_string(step) + ".csv";
  std::ofstream fout(fname);
  fout << "x, y, z, speed, rad" << "\n";
  for(auto & p : bodies) {
    double speed = std::sqrt((p.V*p.V).sum());
    fout << p.R[0] << ", " << p.R[1] << ", " << p.R[2] << ", " << speed << ", " << p.rad << "\n";
  }
  fout.close();
}
