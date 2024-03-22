/**
 * g++ h_1_WA_08.cc
 * gcc -lstdc++ h_1_WA_08.cc
 **/

#include <iostream>
#include <vector>

int main() {
  int16_t n, m;
  std::cin >> n >> m;
  int** arr2D = new int*[n]{0};
  for (int i = 0; i < n; ++i) {
    arr2D[i] = new int[m]{0};
    for (int j = 0; j < m; ++j) {
      std::cin >> arr2D[i][j];
    }
  }

  // Поиск пар двух максимальных элементов для каждой строки
  // std::pair<int, int>* two_max_elements = new std::pair<int, int>[n];
  // for (int i = 0; i < n; ++i) {
  //   two_max_elements[i] = {0, 0};
  //   for (int j = 0; j < m; ++j) {
  //     if (arr2D[i][j] >= two_max_elements[i].first) {
  //       two_max_elements[i].second = two_max_elements[i].first;
  //       two_max_elements[i].first = arr2D[i][j];
  //     }
  //   }
  // }

  int sum_of_two = 0;
  int16_t row = 0;
  for (int16_t i = 0; i < n; ++i) {
    int max_i = 0;
    int max_i2 = 0;
    for (int16_t j = 0; j < m; ++j) {
      if (arr2D[i][j] >= max_i) {
        max_i2 = max_i;
        max_i = arr2D[i][j];
      } else if (arr2D[i][j] > max_i2) {
        max_i2 = arr2D[i][j];
      }
    }
    if (max_i + max_i2 > sum_of_two) {
      sum_of_two = max_i + max_i2;
      row = i + 1;
    }
  }

  int max = 0;
  int16_t col = 0;
  for (int16_t i = 0; i < n; ++i) {
    if (i == row - 1) continue;

    for (int j = 0; j < m; ++j) {
      if (arr2D[i][j] > max) {
        max = arr2D[i][j];
        col = j + 1;
      }
    }
  }

  std::cout << row <<  " " << col;


  for (int16_t i = 0; i < n; ++i) {
    delete[] arr2D[i];
  }
  delete[] arr2D;
  return 0;
}
