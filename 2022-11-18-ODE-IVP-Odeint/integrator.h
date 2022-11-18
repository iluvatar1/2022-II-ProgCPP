#pragma once // avoids multiple inclusion
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

template <class deriv_t, class system_t, class printer_t>
void integrate_rk4(deriv_t deriv, system_t & y, double tinit, double tend, double dt, printer_t writer)
{
  system_t dydt;
  system_t k1, k2, k3, k4, aux;
  dydt.resize(y.size());
  k1.resize(y.size());
  k2.resize(y.size());
  k3.resize(y.size());
  k4.resize(y.size());
  aux.resize(y.size());

  double time = tinit;
  int nsteps = (tend - tinit)/dt;
  writer(y, time); // write initial conditions
  for(int ii = 0; ii < nsteps; ++ii) {
    time = tinit + ii*dt;
    // k1
    deriv(y, dydt, time);
    k1 = dydt*dt;
    // k2 aux
    aux = y + k1/2;
    //k2
    deriv(aux, dydt, time + dt/2);
    k2 = dydt*dt;
    // k3 aux
    aux = y + k2/2;
    //k3
    deriv(aux, dydt, time + dt/2);
    k3 = dydt*dt;
    // k4 aux
    aux = y + k3;
    //k4
    deriv(aux, dydt, time + dt);
    k4 = dydt*dt;
    // write new data
    y = y + (k1 + 2*k2 + 2*k3 + k4)/6.0;
    // call writer
    writer(y, time);
  }
}
