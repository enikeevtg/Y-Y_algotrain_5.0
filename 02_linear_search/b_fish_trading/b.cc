/**
 * g++ b.cc
 * gcc -lstdc++ b.cc
 **/

#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> prices(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> prices[i];
  }

  int profit = 0;
  for (int purchase = 0; purchase < n - 1; ++purchase) {
    for (int delta = 1; delta <= k; ++delta) {
      if (purchase + delta >= n) {
        break;
      }
      profit = std::max(profit, prices[purchase + delta] - prices[purchase]);
    }
  }
  std::cout << profit;

  return 0;
}
