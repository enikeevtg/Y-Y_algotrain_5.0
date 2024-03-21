/**
 * g++ f.cc
 * gcc -lstdc++ f.cc
 **/

#include <iostream>
#include <vector>

int main() {
  int16_t n = 0;
  std::cin >> n;
  std::vector<int16_t> v = std::vector<int16_t>(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }
  int a, b, k;
  std::cin >> a >> b >> k;

  int closer = (a - 1) / k;
  int delta = (closer / n) * n;
  int far = (b - 1) / k;
  int16_t max_prize = 0;
  for (int i = 0; i < n; ++i) {
    int sector = i + delta;
    while (sector <= far) {
      if (sector >= closer && sector <= far) {
        max_prize = std::max(max_prize, std::max(v[i], v[n - i]));
        break;
      }
      sector += n;
    }
  }

  std::cout << max_prize;

  return 0;
}
