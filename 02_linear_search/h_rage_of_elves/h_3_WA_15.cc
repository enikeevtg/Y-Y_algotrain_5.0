/**
 * g++ h.cc
 * gcc -lstdc++ h.cc
 **/

#include <iostream>
#include <vector>

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

  // Поиск пар двух максимальных элементов для каждой строки
  // std::pair<int, int>* two_max_elements = new std::pair<int, int>[n];
  // for (int i = 0; i < n; ++i) {
  //   two_max_elements[i] = {0, 0};
  //   for (int j = 0; j < m; ++j) {
  //     if (a[i][j] >= two_max_elements[i].first) {
  //       two_max_elements[i].second = two_max_elements[i].first;
  //       two_max_elements[i].first = a[i][j];
  //     }
  //   }
  // }

  int sum_of_two_hor = 0;
  int16_t row = 0;
  for (int16_t i = 0; i < n; ++i) {
    int max_i = 0;
    int max_i2 = 0;
    for (int16_t j = 0; j < m; ++j) {
      if (a[i][j] >= max_i) {
        max_i2 = max_i;
        max_i = a[i][j];
      } else if (a[i][j] > max_i2) {
        max_i2 = a[i][j];
      }
    }
    if (max_i + max_i2 > sum_of_two_hor) {
      sum_of_two_hor = max_i + max_i2;
      row = i + 1;
    }
  }

  int sum_of_two_vert = 0;
  int16_t col = 0;
  for (int16_t j = 0; j < m; ++j) {
    int max_j = 0;
    int max_j2 = 0;
    for (int16_t i = 0; i < n; ++i) {
      if (a[i][j] >= max_j) {
        max_j2 = max_j;
        max_j = a[i][j];
      } else if (a[i][j] > max_j2) {
        max_j2 = a[i][j];
      }
    }
    if (max_j + max_j2 > sum_of_two_vert) {
      sum_of_two_vert = max_j + max_j2;
      col = j + 1;
    }
  }
  // std::cout << row <<  " " << col;

  int max2 = 0;
  if (sum_of_two_hor >= sum_of_two_vert) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i == row - 1) continue;

        if (a[i][j] > max2) {
          max2 = a[i][j];
          col = j + 1;
        }
      }
    }
  } else {
    for (int j = 0; j < m; ++j) {
      for (int i = 0; i < n; ++i) {
        if (j == col - 1) continue;

        if (a[i][j] > max2) {
          max2 = a[i][j];
          row = i + 1;
        }
      }
    }
  }

  std::cout << row <<  " " << col;


  for (int16_t i = 0; i < n; ++i) {
    delete[] a[i];
  }
  delete[] a;
  return 0;
}
