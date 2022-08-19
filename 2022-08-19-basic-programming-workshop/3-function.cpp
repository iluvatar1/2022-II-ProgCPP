#include <iostream>
#include <cstdlib>

void printsquare(int m) {
  // print first row
  for (int ii = 0; ii < m; ++ii) {
    std::cout << "= ";
  }
  std::cout << "\n";
  // print intermediate rows
  for (int irow = 1; irow < m-1; ++irow) {
    std::cout << "= ";
    for (int icol = 1; icol < m-1; ++icol) {
      std::cout << "- "; // this to easy the local visualization
    }
    std::cout << "=\n";
  }
  // print last row
  for (int ii = 0; ii < m; ++ii) {
    std::cout << "= ";
  }
  std::cout << "\n";

}

int main(int argc, char **argv) {
  int m  = std::atoi(argv[1]);

  printsquare(m);
  printsquare(m+1);

  return 0;
}
