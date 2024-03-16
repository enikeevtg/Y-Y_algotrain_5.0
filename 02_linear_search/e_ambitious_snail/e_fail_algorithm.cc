/**
 * g++ e.cc
 * gcc -lstdc++ e.cc
 **/

#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;

  // Загрузка всех ягод в массив
  std::vector<std::pair<int, int>> berries = std::vector<std::pair<int, int>>(n);
  int eq_pos = 0;
  int neg_pos = 0;
  bool negative_moving = false;
  for (int i = 0; i < n; ++i) {
    int up, down;
    std::cin >> up >> down;
    berries[i] = {up, down};
    if (up > down) {
      ++eq_pos;
    }
    if (up >= down) {
      ++neg_pos;
    } else {
      negative_moving = true;
    }
  }

  // Поиск граничной ягоды
  std::pair<int, int> bound_berry = berries[0];
  int bound = 0;
  for (int i = 1; i < n; ++i) {
    if (berries[i].first != berries[i].second &&
        (bound_berry.first < berries[i].first ||
        bound_berry.first == berries[i].first &&
        bound_berry.second < berries[i].second)) {
      bound_berry = berries[i];
      bound = i;
    }
  }
  int i = 0;
  while (berries[i].first >= berries[i].second) {
    ++i;
  }
  int neg_bound = 0;
  bound_berry = berries[i];
  for (; i < n; ++i) {
    if (berries[i].first < berries[i].second &&
        bound_berry.first < berries[i].first) {
      bound_berry = berries[i];
      neg_bound = i;
    }
  }
  if (berries[bound].first < berries[neg_bound].first) {
    bound = neg_bound;
  }

  // std::cout << bound << ' ' << neg_bound;

  // bound = 11;
  // Запись последовательности ягод
  std::vector<int> berries_seq = std::vector<int>(n);
  if (negative_moving == true) {
    berries_seq[neg_pos] = bound;
    ++neg_pos;
  }
  int pos_pos = 0;
  for (int i = 0; i < n; ++i) {
    if (i != bound && berries[i].first - berries[i].second > 0) {
      berries_seq[pos_pos] = i;
      ++pos_pos;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (berries[i].first == berries[i].second) {
      berries_seq[eq_pos] = i;
      ++eq_pos;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i != bound && berries[i].first < berries[i].second) {
        berries_seq[neg_pos] = i;
        ++neg_pos;
    }
  }
  if (negative_moving == false) {
    berries_seq[pos_pos] = bound;
  }
  
  // Поиск наибольшей высоты
  int64_t max_height = 0;
  int64_t after_night_height = 0;
  for (int i = 0; i < n; ++i) {
    if (max_height < after_night_height + berries[berries_seq[i]].first) {
      max_height = after_night_height + berries[berries_seq[i]].first;
    }
    after_night_height += berries[berries_seq[i]].first - berries[berries_seq[i]].second;
  }

  // for (int i = 0; i < n; ++i) {
  //   std::cout << berries[berries_seq[i]].first << " - " << berries[berries_seq[i]].second << " = " << berries[berries_seq[i]].first - berries[berries_seq[i]].second << '\n';
  // }

  // for (int i = 0; i < n; ++i) {
  //   std::cout << berries[i].first << " - " << berries[i].second << " = " << berries[i].first - berries[i].second << '\n';
  // }

  // Вывод результатов
  std::cout << max_height << '\n';
  for (auto el: berries_seq) {
    std::cout << el + 1 << ' ';
  }

  return 0;
}
