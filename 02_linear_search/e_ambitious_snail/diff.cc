#include <iostream>


int main() {
  int n;
  std::cin >> n;
  int up[100], down[100];
  for (int i = 0; i < n; ++i) {
    std::cin >> up[i] >> down[i];
  }

  for (int i = 0; i < n; ++i) {
    std::cout << up[i] << " - " << down[i] << " = " << up[i] - down[i] << '\n';
  }


  return 0;
}
