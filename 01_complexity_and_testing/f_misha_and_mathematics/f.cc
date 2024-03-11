/**
 * g++ f.cc
 * gcc -lstdc++ f.cc
 **/

#include <iostream>
#include <string>
#include <vector>


int main() {
  int n;
  std::cin >> n;
  std::vector<int> v = std::vector<int>(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }

  std::string signs = std::string(n - 1, '0');
  for (int i = 1; i < n; ++i) {
    if ((v[i - 1] + v[i]) % 2 == 0) {
      signs[i - 1] = (char)120;
    }
  }

  if (v[0] % 2 == 0) {
    signs[signs.find('0')] = (char)43;
  }
  bool plus = true;
  while (true) {
    if (signs.find('0') != std::string::npos) {
      if (plus) {
        signs[signs.find('0')] = (char)43;
      } else {
        signs[signs.find('0')] = (char)120;
      }
      plus = !plus;
    } else {
      break;
    }
  }

  std::cout << signs;
  return 0;
}
