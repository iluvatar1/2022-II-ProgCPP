#pragma once
class TimeIntegrator{
  double dt{0.0};

  public:
    TimeIntegrator(double DT) { dt = DT; }
    template <class particle_array_t>
    void startIntegration(particle_array_t & parray) {
      for(auto & p : parray) {
        p.V = p.V - 0.5*dt*p.F/p.mass;
      }
    }
    template <class particle_array_t>
    void timeStep(particle_array_t & parray) {
      for (auto & p : parray) {
        p.V = p.V + dt*p.F/p.mass;
        p.R = p.R + dt*p.V;
      }
    }
};
