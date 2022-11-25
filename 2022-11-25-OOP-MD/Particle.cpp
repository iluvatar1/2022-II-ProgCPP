#include "Particle.h"

Particle::Particle(){
  R = {0, 0, 0}; V = {0, 0, 0}; F = {0, 0, 0};
  mass = 0.0;
  rad = 0.0;
}

void Particle::print(void) {
  std::cout << R[0] << "\t";
}
