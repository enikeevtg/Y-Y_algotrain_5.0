/**
 * g++ j.cc
 * gcc -lstdc++ j.cc
 **/

#include <iostream>

const char empty_cell = '.';

bool is_rect(std::string* field, int row0, int col0, int row1, int col1,
             char fill) {
  int cnt = 0;
  int row_max = -1;
  int row_min = row1;
  int col_max = -1;
  int col_min = col1;
  for (int i = row0; i < row1; ++i) {
    for (int j = col0; j < col1; ++j) {
      if (field[i][j] != empty_cell) {
        row_max = std::max(i, row_max);
        row_min = std::min(i, row_min);
        col_max = std::max(j, col_max);
        col_min = std::min(j, col_min);
        field[i][j] = fill;
        ++cnt;
      }
    }
  }
  return (row_max - row_min + 1) * (col_max - col_min + 1) == cnt;
}

bool solve(std::string* f, int rows, int cols) {
  for (int i = 1; i < rows; ++i) {
    if (is_rect(f, 0, 0, i, cols, 'a') && is_rect(f, i, 0, rows, cols, 'b')) {
      return true;
    }
  }
  for (int j = 1; j < cols; ++j) {
    if (is_rect(f, 0, 0, rows, j, 'a') && is_rect(f, 0, j, rows, cols, 'b')) {
      return true;
    }
  }
  return false;
}

int main() {
  int m, n;
  std::cin >> m >> n;

  std::string* field = new std::string[m];
  for (int i = 0; i < m; ++i) {
    std::cin >> field[i];
  }

  if (solve(field, m, n)) {
    std::cout << "YES\n";
    for (int i = 0; i < m; ++i) {
      std::cout << field[i] << std::endl;
    }
  } else {
    std::cout << "NO";
  }

  return 0;
}
