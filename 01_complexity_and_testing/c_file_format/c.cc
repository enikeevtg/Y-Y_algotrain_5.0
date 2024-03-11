/**
 * g++ c.cc
 * gcc -lstdc++ c.cc
 **/

#include <iostream>

int main() {
  int n = 0;
  size_t counter = 0;
  std::cin >> n;
  while (n) {
    int i;
    std::cin >> i;
    counter += i / 4;
    i % 4 == 3 ? counter += 2 : counter += i % 4;
    --n;
  }
  std::cout << counter;

  return 0;
}

// input:
// 5
// 1
// 4
// 12
// 9
// 0
// output:
// 8

// Примечание: нужно учитывать возможное переполнение счётчика
