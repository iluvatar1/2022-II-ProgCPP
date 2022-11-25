#include "Particle.h"
Particle::Particle(){
  R = {0, 0, 0}; V = {0, 0, 0}; F = {0, 0, 0};
  mass = 0.0;
  rad = 0.0;
}

void Particle::print(void) {
  std::cout << R[0] << "\t" << R[1] << "\t" << R[2] << "\t"
            << V[0] << "\t" << V[1] << "\t" << V[2] << "\t"
            << F[0] << "\t" << F[1] << "\t" << F[2] << "\t"
            << mass << "\t" << rad;
}

std::ostream& operator<< (std::ostream& out, const Particle& p)
{
  // Since operator<< is a friend of the Particle class, we can access particles's members directly.
  out << p.R[0] << "\t" << p.R[1] << "\t" << p.R[2] << "\t"
      << p.V[0] << "\t" << p.V[1] << "\t" << p.V[2] << "\t"
      << p.F[0] << "\t" << p.F[1] << "\t" << p.F[2] << "\t"
      << p.mass << "\t" << p.rad;
  return out; // return std::ostream so we can chain calls to operator<<
}
