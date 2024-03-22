/**
 * g++ h.cc
 * gcc -lstdc++ h.cc
 * 
 * Общий код вынесен в структуры и функцию
 * У автора подобный подход (но без использования структур) занял 25 строк
 **/

#include <iostream>

struct Matrix {
  int rows = 0;
  int cols = 0;
  int** matrix = nullptr;

  Matrix(int n, int m) : rows(n), cols(m) {
    matrix = new int*[rows]{0};
    for (int i = 0; i < n; ++i) {
      matrix[i] = new int[cols]{0};
      for (int j = 0; j < m; ++j) {
        std::cin >> matrix[i][j];
      }
    }
  }
  ~Matrix() {
    for (int16_t i = 0; i < rows; ++i) {
      delete[] matrix[i];
    }
    delete[] matrix;
  }

  int operator()(int row, int col) {
    return matrix[row][col];
  }
};

struct MatrixMax {
  int row = 0;
  int col = 0;
  int val = 0;
};

// Функция поиска максимума в матрице с вычеркнутыми строкой и столбцом
MatrixMax matrix_max(Matrix& m, int ex_row, int ex_col) {
  MatrixMax max;
  for (int i = 0; i < m.rows; ++i) {
    if (i == ex_row) continue;
    for (int j = 0; j < m.cols; ++j) {
      if (j == ex_col) continue;
      if (m(i, j) > max.val) {
        max.row = i;
        max.col = j;
        max.val = m(i, j);
      }
    }
  }
  return max;
}


int main() {
  int16_t n, m;
  std::cin >> n >> m;
  Matrix matrix = Matrix(n, m);

  MatrixMax max = matrix_max(matrix, -1, -1);
  MatrixMax max2_row_except = matrix_max(matrix, max.row, -1);
  MatrixMax max3_row_except = matrix_max(matrix, max.row, max2_row_except.col);
  MatrixMax max2_col_except = matrix_max(matrix, -1, max.col);
  MatrixMax max3_col_except = matrix_max(matrix, max2_col_except.row, max.col);

  if (max3_row_except.val > max3_col_except.val) {
    std::cout << max2_col_except.row + 1 <<  " " << max.col + 1;
  } else {
    std::cout << max.row + 1 <<  " " << max2_row_except.col + 1;
  }
  return 0;
}
