/**
 * g++ h_done.cc
 * gcc -lstdc++ h_done.cc
 **/

#include <iostream>

int main() {
  int16_t n, m;
  std::cin >> n >> m;
  int** a = new int*[n]{0};
  for (int i = 0; i < n; ++i) {
    a[i] = new int[m]{0};
    for (int j = 0; j < m; ++j) {
      std::cin >> a[i][j];
    }
  }

  int max = 0;
  int16_t max_i, max_j;
  for (int16_t i = 0; i < n; ++i) {
    for (int16_t j = 0; j < m; ++j) {
      if (a[i][j] > max) {
        max = a[i][j];
        max_i = i;
        max_j = j;
      }
    }
  }
  // std::cout << max << std::endl;

  int max2 = 0;
  int16_t max2_1_i, max2_1_j;
  for (int16_t i = 0; i < n; ++i) {
    if (i == max_i) continue;
    for (int16_t j = 0; j < m; ++j) {
      if (a[i][j] > max2) {
        max2 = a[i][j];
        max2_1_i = i;
        max2_1_j = j;
      }
    }
  }
  // std::cout << max2 << std::endl;

  int max3_1 = 0;
  for (int16_t i = 0; i < n; ++i) {
    if (i == max_i) continue;
    for (int16_t j = 0; j < m; ++j) {
      if (j == max2_1_j) continue;
      max3_1 = std::max(a[i][j], max3_1);
    }
  }
  // std::cout << max3_1 << std::endl;

  max2 = 0;
  int16_t max2_2_i, max2_2_j;
  for (int16_t i = 0; i < n; ++i) {
    for (int16_t j = 0; j < m; ++j) {
      if (j == max_j) continue;
      if (a[i][j] > max2) {
        max2 = a[i][j];
        max2_2_i = i;
        max2_2_j = j;
      }
    }
  }
  // std::cout << max2 << std::endl;

  int max3_2 = 0;
  for (int16_t i = 0; i < n; ++i) {
    if (i == max2_2_i) continue;
    for (int16_t j = 0; j < m; ++j) {
      if (j == max_j) continue;
      max3_2 = std::max(a[i][j], max3_2);
    }
  }
  // std::cout << max3_2 << std::endl;

  int row = max_i + 1;
  int col = max2_1_j + 1;
  if (max3_1 > max3_2) {
    row = max2_2_i + 1;
    col = max_j + 1;
  }

  std::cout << row <<  " " << col;

  for (int16_t i = 0; i < n; ++i) {
    delete[] a[i];
  }
  delete[] a;
  return 0;
}
