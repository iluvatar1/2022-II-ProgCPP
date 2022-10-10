#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
  std::vector<double> data;
  data.resize(4);
  data[0] = 0.987;
  data[1] = 1.987;
  data[0] = -10.987;
  data[1] = -21.987;

  auto print = [](double x){std::cout << x << " "; };
  auto printaddress = [](const double & x){std::cout << &x << " "; };

  std::for_each(data.cbegin(), data.cend(), print);
  std::cout << "\n";
  std::for_each(data.begin(), data.end(), printaddress);
  std::cout << "\n";

  std::for_each(data.begin(), data.end(), [](double & val){ val /= 2; });

  std::for_each(data.cbegin(), data.cend(), print);
  std::cout << "\n";

  std::for_each(data.begin(), data.end(), printaddress);
  std::cout << "\n";

  return 0;
}
