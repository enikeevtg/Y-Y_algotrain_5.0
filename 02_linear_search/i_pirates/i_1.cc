/**
 * g++ i.cc
 * gcc -lstdc++ i.cc
 **/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int main() {
  int n;
  std::cin >> n;
  int** a = new int*[n]{0};
  for (int i = 0; i < n; ++i) {
    a[i] = new int[n]{0};
  }

  int av_col = 0;
  for (int i = 0; i < n; ++i) {
    int row, col;
    std::cin >> row >> col;
    a[row - 1][col - 1] = 1;
    av_col += int(std::round(float(col - 1) / n));
  }
  std::cout << "av_col = " << av_col << '\n';

  std::cout << '\n';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << a[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';

  int steps = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j == av_col) continue;

      // std::cout << "#i = " << i << " #j = " << j << '\n';
      if (a[i][j] == 1) {
        // std::cout << "ship\n";
        a[i][j] = 0;
        int delta = av_col - j;
        steps += std::abs(delta);
        if (a[i][j + delta] == 1) {
          // std::cout << "ship on " << i << ' ' << j + delta << '\n';
          int min = n;
          int min_row = 0;
          for (int k = 0; k < n; ++k) {
            // std::cout << "a[k][av_col] = " << a[k][av_col] << '\n';
            if (a[k][av_col] == 0 && min > std::abs(k - i)) {
              // std::cout << "k = " << k << '\n';
              min = std::abs(k - i);
              min_row = k;
            }
          }
          steps += min;
          a[min_row][av_col] = 1;
        } else {
          a[i][av_col] = 1;
        }
      }
    }
  }

  // std::cout << '\n';
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     std::cout << a[i][j] << ' ';
  //   }
  //   std::cout << '\n';
  // }
  // std::cout << '\n';

  // std::cout << "ans = " << steps << '\n';
  std::cout << steps << '\n';

  for (int i = 0; i < n; ++i) {
    delete[] a[i];
  }
  delete[] a;

  return 0;
}
