/**
 * g++ c.cc
 * gcc -lstdc++ c.cc
 **/

#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;

  int sum_length = 0;
  int max_rope = 0;
  for (int i = 0; i < n; ++i) {
    int cur_rope_length;
    std::cin >> cur_rope_length;
    sum_length += cur_rope_length;
    if (cur_rope_length > max_rope) {
      max_rope = cur_rope_length;
    }
  }

  int result_rope = 0;
  if (sum_length - max_rope < max_rope) {
    result_rope = max_rope - (sum_length - max_rope);
  } else {
    result_rope = sum_length;
  }

  std::cout << result_rope;
  return 0;
}
