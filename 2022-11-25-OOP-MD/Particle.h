#pragma once
#include <valarray>
#include <iostream>
struct Particle {
  std::valarray<double> R{0, 0, 0}, V{0, 0, 0}, F{0, 0, 0};
  double mass{0.0}, rad{0.0};
  Particle();
  void print(void);
};
