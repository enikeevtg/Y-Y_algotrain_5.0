/**
 * g++ d.cc
 * gcc -lstdc++ d.cc
 **/

#include <iostream>
#include <string>

class ChessBoard {
public:
  ChessBoard() {
    board_ = new std::string[board_size_];
  }

  ~ChessBoard() {
    delete[] board_;
  }

  void FillBoard() {
    for (int i = 0; i < board_size_; ++i) {
      std::cin >> board_[i];
    }
  }

  int get_fields_count() { return board_size_ * board_size_; }

  int RookBeatingFieldsReplace(int row, int col) {
    int count = 0;
    for (int i = row - 1; i >= 0; --i) {
      if (board_[i][col] == 'R' || board_[i][col] == 'B') {
        break;
      }
      if (board_[i][col] == '*') {
        board_[i][col] = '#';
        ++count;
      }
    }
    for (int i = row + 1; i < board_size_; ++i) {
      if (board_[i][col] == 'R' || board_[i][col] == 'B') {
        break;
      }
      if (board_[i][col] == '*') {
        board_[i][col] = '#';
        ++count;
      }
    }
    for (int j = col - 1; j >= 0; --j) {
      if (board_[row][j] == 'R' || board_[row][j] == 'B') {
        break;
      }
      if (board_[row][j] == '*') {
        board_[row][j] = '#';
        ++count;
      }
    }
    for (int j = col + 1; j < board_size_; ++j) {
      if (board_[row][j] == 'R' || board_[row][j] == 'B') {
        break;
      }
      if (board_[row][j] == '*') {
        board_[row][j] = '#';
        ++count;
      }
    }
    return count;
  }

  int BishopBeatingFieldsReplace(int row, int col) {
    int count = 0;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (board_[i][j] == 'R' || board_[i][j] == 'B') {
        break;
      }
      if (board_[i][j] == '*') {
        board_[i][j] = '#';
        ++count;
      }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < board_size_; --i, ++j) {
      if (board_[i][j] == 'R' || board_[i][j] == 'B') {
        break;
      }
      if (board_[i][j] == '*') {
        board_[i][j] = '#';
        ++count;
      }
    }
    for (int i = row + 1, j = col + 1; i < board_size_ && j < board_size_;
         ++i, ++j) {
      if (board_[i][j] == 'R' || board_[i][j] == 'B') {
        break;
      }
      if (board_[i][j] == '*') {
        board_[i][j] = '#';
        ++count;
      }
    }
    for (int i = row + 1, j = col - 1; i < board_size_ && j >= 0; ++i, --j) {
      if (board_[i][j] == 'R' || board_[i][j] == 'B') {
        break;
      }
      if (board_[i][j] == '*') {
        board_[i][j] = '#';
        ++count;
      }
    }
    return count;
  }

  int CountUnbreakableFields() {
    int breakable_fields_counter = 0;
    for (int i = 0; i < board_size_; ++i) {
      for (int j = 0; j < board_size_; ++j) {
        if (board_[i][j] == 'R') {
          breakable_fields_counter += 1 + RookBeatingFieldsReplace(i, j);
        } else if (board_[i][j] == 'B') {
          breakable_fields_counter += 1 + BishopBeatingFieldsReplace(i, j);
        }
      }
    }
    return breakable_fields_counter;
  }

  void PrintBoard() {
    for (int i = 0; i < board_size_; ++i)
      std::cout << board_[i] << '\n';
  }

private:
  const int board_size_{8};
  std::string* board_{nullptr};
};

int main() {
  ChessBoard board;
  board.FillBoard();
  std::cout << board.get_fields_count() - board.CountUnbreakableFields();
  // board.PrintBoard();
  return 0;
}


// input:
// ********
// ********
// *R******
// ********
// ********
// ********
// ********
// ********
// output:
// 49

// input:
// ********
// ********
// ******B*
// ********
// ********
// ********
// ********
// ********
// output:
// 54

// input:
// ********
// *R******
// ********
// *****B**
// ********
// ********
// ********
// ********
// output:
// 40
