/*
 * @brief 動的計画法/convex full trick (monotone_dec_query(x))
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c"

#include <iostream>
#include <vector>
#include "../../dp/cht.hpp"

int main() {
  int n;
  std::cin >> n;
  CHT<long long> cht;
  for (int j = 1; j <= n; ++j) {
    long long a;
    std::cin >> a;
    cht.add(-2 * j, a + static_cast<long long>(j) * j);
  }
  std::vector<long long> ans(n);
  for (int i = n; i >= 1; --i) {
    ans[i - 1] = cht.monotone_dec_query(i) + static_cast<long long>(i) * i;
  }
  for (int i = 0; i < n; ++i) std::cout << ans[i] << '\n';
  return 0;
}
