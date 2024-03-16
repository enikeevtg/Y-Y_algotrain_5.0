/**
 * g++ e_vector.cc
 * gcc -lstdc++ e_vector.cc
 * Ошибочное решение. Нужно разделять на блоки?
 **/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n = 0;
  std::cin >> n;

  vector<std::pair<int64_t, int64_t>> berries = vector<std::pair<int64_t, int64_t>>(n);

  for (int i = 0; i < n; ++i) {
    cin >> berries[i].first >> berries[i].second;
  }

  int64_t max_height = 0;
  int64_t after_night_height = 0;
  vector<int> berries_seq = vector<int>(n);
  for (int i = 0; i < n; ++i) {
    // Поиск первой неиспользованной ягоды
    int k = 0;
    while (berries[k].first == -1) {
      ++k;
    }
    pair<int64_t, int64_t> best_berry = berries[k];
    berries_seq[i] = k;

    // Поиск следующей ягоды
    int max_diff = best_berry.first - best_berry.second;
    for (; k < n; ++k) {
      while (berries[k].first == -1 && k < n - 1) {
        ++k;
      }
      int cur_diff = berries[k].first - berries[k].second;
      if (berries[k].first != -1 &&
          ((max_diff < cur_diff) ||
           (max_diff == cur_diff && best_berry.first > berries[k].first))) {
        best_berry = berries[k];
        max_diff = best_berry.first - best_berry.second;
        berries_seq[i] = k;
      }
    }

    // Вычисление новой максимальной высоты и высоты на утро следующего дня
    max_height = max(after_night_height + best_berry.first, max_height);
    after_night_height += best_berry.first - best_berry.second;

    // Заплатка для искючения элемента из дальнейшего рассмотрения
    berries[berries_seq[i]].first = -1;
  }

  std::cout << max_height << '\n';
  for (auto el : berries_seq) {
    cout << el + 1 << ' ';
  }

  return 0;
}
