#pragma once
#include <map>
#include <string>
#include <type_traits>

class Collider {
  std::map<std::string, double> params; // parameters to compute the forces
  public:
    Collider(const std::map<std::string, double> & PARAMS) {
      params = PARAMS;
    }
    template<class particle_array_t>
    void computeForces(particle_array_t & parray) {
      // reset forces
      for (auto & p : parray) {
        p.F = 0.0;
      }
      // individual forces
      for (auto & p : parray) {
        // gravity force
        p.F[2] -= p.mass*params["G"];
        // force with floor
        double delta = p.rad - p.R[2];
        if (delta > 0) {
          p.F[2] += params["K"]*delta;
          p.F[2] -= params["B"]*p.mass*p.V[2];
        }
        // force with left wall
        delta = p.rad - p.R[0] - params["L"]/2;
        if (delta > 0) {
          p.F[0] += params["K"]*delta;
          p.F[0] -= params["B"]*p.mass*p.V[0];
        }
        // force with right wall
        delta = p.rad + p.R[0] - params["L"]/2;
        if (delta > 0) {
          p.F[0] -= params["K"]*delta;
          p.F[0] -= params["B"]*p.mass*p.V[0];
        }
      }
      
      // interparticle forces
      const int N = parray.size();
      for (int ii = 0; ii < N; ++ii) {
        decltype(parray[0].R) Rij, nij;
        for (int jj = ii+1; jj < N; ++jj) {
          // assumes valarray
          Rij = parray[jj].R - parray[ii].R;
          double rij = std::sqrt((Rij*Rij).sum());
          double delta = parray[ii].rad + parray[jj].rad - rij;
          if (delta > 0) {
            nij = Rij/rij;
            parray[jj].F += params["K"]*delta*nij;
            parray[ii].F -= params["K"]*delta*nij;
          }
        }
      }
    }
};
