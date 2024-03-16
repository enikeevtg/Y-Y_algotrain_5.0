/**
 * g++ d.cc
 * gcc -lstdc++ d.cc
 **/

#include <iostream>
#include <string>
#include <vector>


int main() {
  int n = 0;
  std::cin >> n;

  int board_size = 10;
  std::vector<std::string> board(board_size);
  for (int i = 0; i < board_size; ++i) {
    board[i] = std::string(board_size, '0');
  }

  for (int i = 0; i < n; ++i) {
    int row = 0;
    int col = 0;
    std::cin >> row >> col;
    board[row][col] = '#';
  }

  // for (int i = 0; i < board_size; ++i) {
  //   std::cout << board[i] << '\n';
  // }

  int perimeter = n * 4;
  int row_offset[4] = {0, 1, 0, -1};
  int col_offset[4] = {1, 0, -1, 0};
  for (int i = 0; i < board_size; ++i) {
    for (int j = 0; j < board_size; ++j) {

      if (board[i][j] == '#') {
        for (int k = 0; k < 4; ++k) {
          if (board[i + row_offset[k]][j + col_offset[k]] == '#') {
            --perimeter;
          }
        }
      }

    }
  }

  std::cout << perimeter;

  return 0;
}
