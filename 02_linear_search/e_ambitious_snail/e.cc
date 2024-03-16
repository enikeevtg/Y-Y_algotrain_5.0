/**
 * g++ e.cc
 * gcc -lstdc++ e.cc
 **/

#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;

  // Загрузка всех ягод в массив и поиск особых ягод
  std::vector<std::pair<int, int>> berries = std::vector<std::pair<int, int>>(n);
  int spec_pos_berry = 0;
  int spec_neg_berry = 0;
  int neg_pos = 0;
  for (int i = 0; i < n; ++i) {
    int up = 0, down = 0;
    std::cin >> up >> down;
    berries[i] = {up, down};
    if (up > down) ++neg_pos;
    if (up > down) {
      if (berries[spec_pos_berry].first - berries[spec_pos_berry].second <= 0)
        spec_pos_berry = i;
      if (down > berries[spec_pos_berry].second) spec_pos_berry = i;
    } else {
      if (berries[spec_neg_berry].first - berries[spec_neg_berry].second > 0)
        spec_neg_berry = i; 
      if (up > berries[spec_neg_berry].first) spec_neg_berry = i;
    }
  }

  // Выбор граничной ягоды
  int bound_berry = spec_pos_berry;
  if (berries[spec_neg_berry].first > berries[spec_pos_berry].second) {
    bound_berry = spec_neg_berry;
    ++neg_pos;
  }

  // Подсчёт последовательности ягод и максимальной высоты
  std::vector<int> berries_seq = std::vector<int>(n);
  int pos_pos = 0;
  size_t max_height = 0;
  for (int i = 0; i < n; ++i) {
    if (i == bound_berry) continue;

    if (berries[i].first > berries[i].second) {
      berries_seq[pos_pos] = i;
      ++pos_pos;
      max_height += berries[i].first - berries[i].second;
    } else {
      berries_seq[neg_pos] = i;
      ++neg_pos;
    }
  }
  berries_seq[pos_pos] = bound_berry;
  max_height += berries[bound_berry].first;

  std::cout << max_height << '\n';
  for (auto i: berries_seq) {
    std::cout << i + 1 << ' ';
  }

  return 0;
}
