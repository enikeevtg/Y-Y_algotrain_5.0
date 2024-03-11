/**
 * g++ e.cc
 * gcc -lstdc++ e.cc
 **/

#include <iostream>
#include <string>
#include <vector>


void print_vector(std::vector<size_t>& v) {
  for (auto element: v) {
    std::cout << element << ' ';
  }
  std::cout << '\n';
}

std::string algorithm(size_t initial_profit, int founders, int days) {
  std::string result;
  std::vector<size_t> queue = {initial_profit};

  for (int day = 0; day < days; ++day) {
    if (day > 0 && queue[0] % 10 == 0) {
      result = std::to_string(queue[0]);
      std::string nills = std::string(days - day, '0');
      result += nills;
      break;
    }
    std::vector<size_t> new_queue = {};
    for (auto element: queue) {
      for (size_t i = 0; i < 10; ++i) {
        size_t new_element = element * 10 + i;
        if (new_element % founders == 0) new_queue.push_back(new_element);
      }
    }
    if (new_queue.size() == 0) {
      throw "-1";
    }
    queue = new_queue;
    result = std::to_string(queue[0]);
  }

  return result;
}


int main() {
  size_t initial_profit;
  int founders, days;
  std::cin >> initial_profit >> founders >> days;

  try {
    std::cout << algorithm(initial_profit, founders, days);
  }    
  catch (const char* err_msg) {
    std::cout << err_msg;
  }

  return 0;
}
