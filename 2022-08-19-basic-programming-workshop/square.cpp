#include <iostream>

int main(void) {
  int m{0};

  std::cout << "Write the amount of '#' per side:\n";
  std::cin >> m;
  // print first row
  for (int ii = 0; ii < m; ++ii) {
    std::cout << "# ";
  }
  std::cout << "\n";
  // print intermediate rows
  for (int irow = 1; irow < m-1; ++irow) {
    std::cout << "# ";
    for (int icol = 1; icol < m-1; ++icol) {
      std::cout << "  "; // this to easy the local visualization
    }
    std::cout << "#\n";
  }
  // print last row
  for (int ii = 0; ii < m; ++ii) {
    std::cout << "# ";
  }
  std::cout << "\n";

  return 0;
}
