/**
 * g++ e_map.cc
 * gcc -lstdc++ e_map.cc
 * Попробовал решить через словарь
 **/

#include <iostream>
#include <map>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;

  std::map<int, std::pair<int, int>> map_;

  for (int i = 0; i < n; ++i) {
    std::cin >> map_[i + 1].first >> map_[i + 1].second;
  }

  int max_height = 0;
  int cur_height = 0;
  std::vector<int> indices_seq = std::vector<int>(n);
  for (int i = 0; i < n; ++i) {
    int max_index = 1;
    while (map_[max_index].first == -1) {
      ++max_index;
    }
    std::pair<int, int> max = map_[max_index];
    for (int j = 1; j <= n; ++j) {
      if (map_[j].first != -1 &&
          max.first - max.second > map_[j].first - map_[j].second &&
          max.first < map_[j].first) {
        max = map_[j];
        max_index = j;
      }
    }
    max_height = std::max(cur_height + max.first, max_height);
    cur_height += max.first - max.second;
    indices_seq.push_back(max_index);
    map_.erase(max_index);
  }

  std::cout << max_height;
  // std::cout << map_[n + 200].first;
  return 0;
}
