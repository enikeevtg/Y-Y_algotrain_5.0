/**
 * g++ e_simple.cc
 * gcc -lstdc++ e_simple.cc
 **/

#include <iostream>
#include <string>


int main() {
  int initial_profit, founders, days;
  std::cin >> initial_profit >> founders >> days;

  int result = 0;
  for (int i = 0; i < 10; ++i) {
    if ((initial_profit * 10 + i) % founders == 0) {
      result = initial_profit * 10 + i;
      break;
    }
  }

  if (result == 0) {
    std::cout << -1;
  } else {
    std::string nills = std::string(days - 1, '0');
    std::cout << result << nills;
  }

  return 0;
}
