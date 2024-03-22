/**
 * g++ h_2_TL_18.cc
 * gcc -lstdc++ h_2_TL_18.cc
 * 
 * Ломается на 18 тесте из-за превышения времени (TL)
 * Проблема в отработке одинаковых максимальных элементов. Из-за этого
 * сложность O(n^3). При n = 1000 это порядка 10^9 элементарных операций
 * Нужен более простой алгоритм.
 **/

#include <iostream>
#include <vector>

int main() {
  // Исходные данные
  int16_t n, m;
  std::cin >> n >> m;
  int** a = new int*[n]{0};
  for (int i = 0; i < n; ++i) {
    a[i] = new int[m]{0};
    for (int j = 0; j < m; ++j) {
      std::cin >> a[i][j];
    }
  }

  // Находим максимальный элемент. Если встречаем равный элемент, то выбираем
  // тот, у которого на линиях находися наибольший элемент
  int max = 0;
  int max_i, max_j;
  for (int16_t i = 0; i < n; ++i) {
    for (int16_t j = 0; j < m; ++j) {
      if (max < a[i][j]) {
        max = a[i][j];
        max_i = i;
        max_j = j;
      } else if (max == a[i][j]) {
        int max_current_ij = 0;
        int max_max_ij = 0;
        for (int16_t row_ = 0; row_ < n; ++row_) {
          if (row_ != i) max_current_ij = std::max(max_current_ij, a[row_][j]);
          if (row_ != max_i) max_max_ij = std::max(max_max_ij, a[row_][max_j]);
        }
        for (int16_t col_ = 0; col_ < m; ++col_) {
          if (col_ != j) max_current_ij = std::max(max_current_ij, a[i][col_]);
          if (col_ != max_j) max_max_ij = std::max(max_max_ij, a[max_i][col_]);
        }
        if (max_current_ij > max_max_ij) {
          max_i = i;
          max_j = j;
        }
      }
    }
  }

  // Находим второй по величине элемент в линиях с максимальным элементом
  int max2 = 0;
  int max2_i, max2_j;
  for (int16_t i = 0; i < n; ++i) {
    if (i == max_i) continue;
    if (max2 < a[i][max_j]) {
      max2 = a[i][max_j];
      max2_i = i;
      max2_j = max_j;
    }
  }
  for (int16_t j = 0; j < m; ++j) {
    if (j == max_j) continue;
    if (max2 < a[max_i][j]) {
      max2 = a[max_i][j];
      max2_i = max_i;
      max2_j = j;
    }
  }

  int result_row, result_col;
  // Заменяем нулями выбранную линию
  bool hor_direction = false;
  if (max2_i == max_i) {
    hor_direction = true;
    result_row = max_i + 1;
    for (int j = 0; j < m; ++j) {
      a[max_i][j] = 0;
    }
  } else if (max2_j == max_j) {
    result_col = max_j + 1;
    for (int i = 0; i < n; ++i) {
      a[i][max_j] = 0;
    }
  }

  // Ищем перепендикулярную линию для выреза
  max = 0;
  for (int16_t i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (max < a[i][j]) {
        max_i = i;
        max_j = j;
        max = a[i][j];
      } else if (max == a[i][j]) {
        int max_current_ij = 0;
        int max_max_ij = 0;
        for (int16_t row_ = 0; row_ < n && hor_direction == false; ++row_) {
          if (row_ != i) max_current_ij = std::max(max_current_ij, a[row_][j]);
          if (row_ != max_i) max_max_ij = std::max(max_max_ij, a[row_][max_j]);
        }
        for (int16_t col_ = 0; col_ < m && hor_direction == false; ++col_) {
          if (col_ != j) max_current_ij = std::max(max_current_ij, a[i][col_]);
          if (col_ != max_j) max_max_ij = std::max(max_max_ij, a[max_i][col_]);
        }
        if (max_current_ij > max_max_ij) {
          max_i = i;
          max_j = j;
        }
      }
    }
  }

  if (hor_direction == true) {
    result_col = max_j + 1;
  } else {
    result_row = max_i + 1;
  }

  std::cout << result_row << ' ' << result_col;

  // for (int16_t i = 0; i < n; ++i) {
  //   for (int16_t j = 0; j < m; ++j) {
  //     std::cout << a[i][j] << ' ';
  //   }
  //   std::cout << std::endl;
  // }


  // std::cout << max_i + 1 <<  " " << max_j + 1 << " : " << max << '\n';
  // std::cout << max2_i + 1 <<  " " << max2_j + 1 << " : " << max2 << '\n';

  for (int16_t i = 0; i < n; ++i) {
    delete[] a[i];
  }
  delete[] a;
  return 0;
}
