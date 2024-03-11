/**
 * g++ a.cc
 * gcc -lstdc++ a.cc
 **/

#include <iostream>

int main() {
  int p, v, q, m;
  std::cin >> p >> v >> q >> m;
  std::pair<int, int> further{p - v, p + v};
  std::pair<int, int> closer{q - m, q + m};
  if (p < q) {
    std::swap(further, closer);
  }

  int result = std::max(further.second, closer.second) + 1 -
               std::min(closer.first, further.first);
  int correction = further.first - closer.second - 1;
  if (correction > 0) {
    result -= correction;
  }

  std::cout << result;

  return 0;
}


// input:
// 0 7
// 12 5
// output:
// 25

