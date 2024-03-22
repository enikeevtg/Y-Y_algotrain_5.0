/**
 * g++ i.cc
 * gcc -lstdc++ i.cc
 **/

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> v = std::vector<std::pair<int, int>>(n);

  int target_col = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i].first >> v[i].second;
  }
  std::sort(v.begin(), v.end());

  int steps = 10001;
  for (int col = 1; col <= n; ++col) {
    int tmp_steps = 0;
    for (int i = 0; i < n; ++i) {
      tmp_steps += std::abs(v[i].second - col) + std::abs(v[i].first - (i + 1));
    }
    steps = std::min(steps, tmp_steps);
  }

  std::cout << steps;

  return 0;
}
