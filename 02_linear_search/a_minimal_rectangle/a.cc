/**
 * g++ a.cc
 * gcc -lstdc++ a.cc
 **/

#include <iostream>

int main() {
  int k;
  std::cin >> k;
  int x, y;
  std::cin >> x >> y;

  int x_left, y_bot, x_right, y_top;
  x_left = x_right = x;
  y_bot = y_top = y;

  for (int i = 1; i < k; ++i) {
    std::cin >> x >> y;
    x_right = std::max(x, x_right);
    x_left = std::min(x, x_left);
    y_top = std::max(y, y_top);
    y_bot = std::min(y, y_bot);
  }

  std::cout << x_left << ' ' << y_bot << ' ' << x_right << ' ' << y_top;

  return 0;
}
