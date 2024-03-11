/**
 * g++ b.cc
 * gcc -lstdc++ b.cc
 **/

#include <iostream>

int main() {
  char score1[4];
  char score2[4];

  int t1_guest_match;
  std::cin >> score1 >> score2 >> t1_guest_match;
  int m1_t1, m1_t2, m2_t1, m2_t2;
  std::sscanf(score1, "%d:%d", &m1_t1, &m1_t2);
  std::sscanf(score2, "%d:%d", &m2_t1, &m2_t2);

  int need_to_win = m1_t2 + m2_t2 - (m1_t1 + m2_t1);

  if (need_to_win >= 0) {
    if (t1_guest_match == 1) {
      if (m2_t1 + need_to_win <= m1_t2) ++need_to_win;
    } else {
      if (m1_t1 <= m2_t2) ++need_to_win;
    }
  } else {
    need_to_win = 0;
  }

  std::cout << need_to_win;

  return 0;
}

// input:
// 0:0
// 0:0
// 1
// output:
// 1

// input:
// 0:2
// 0:3
// 1
// output:
// 5

// input:
// 0:2
// 0:3
// 2
// output:
// 6
