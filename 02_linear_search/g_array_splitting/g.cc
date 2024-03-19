/**
 * g++ g.cc
 * gcc -lstdc++ g.cc
 **/

#include <iostream>
#include <vector>

int main() {
  int tests = 0;
  std::cin >> tests;
  for (int test = 0; test < tests; ++test) {
    int n = 0;
    std::cin >> n;
    int cur_el = 0;
    std::vector<int> len = std::vector<int>(n);
    int count = 0;
    int cur_len = 0;
    for (int i = 0; i < n; ++i) {
      std::cin >> cur_el;
      ++cur_len;

      // Пришёл элемент меньше текущей длины
      if (cur_el < cur_len) {
        len[count] = cur_len - 1;
        ++count;
        cur_len = 1;
      }

      // Либо продолжаем обрабатываем элемент меньше текущей длины 
      if (len[count] == 0) {
        len[count] = cur_el;
      }

      if (cur_el == cur_len) {
        // std::cout << cur_el << "==" << cur_len << '\n';
        len[count] = cur_len;
        ++count;
        cur_len = 0;
      } else {
        len[count] = std::min(len[count], cur_el);
        // std::cout << "len[count]" << "==" << len[count] << '\n';
        if (cur_len == len[count] || i == n - 1) {
          // std::cout << "cur_len == len[count] || i < n - 1" << '\n';
          len[count] = cur_len;
          ++count;
          cur_len = 0;
        }
      }
    }

    std::cout << count << '\n';
    for (int i = 0; i < count; ++i) {
      std::cout << len[i] << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}