/*
 * @brief グラフ/フロー/マッチング/一般グラフの最大マッチング
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3032"

#include <cmath>
#include <iostream>
#include <vector>
#include "../../../../graph/flow/matching/maximum_matching.hpp"

int main() {
  int n, a, b;
  std::cin >> n >> a >> b;
  int ans = 0;
  std::vector<int> as, bs;
  while (n--) {
    int a_i, b_i;
    std::cin >> a_i >> b_i;
    const int x = std::abs(a_i - b_i);
    if (x <= a || (b <= x && x <= 2 * a)) {
      ++ans;
    } else {
      as.emplace_back(a_i);
      bs.emplace_back(b_i);
    }
  }
  n = as.size();
  if (n > 0) {
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        const int x = std::abs((as[i] + as[j]) - (bs[i] + bs[j]));
        if (x <= a || (b <= x && x <= 2 * a)) {
          graph[i].emplace_back(j);
          graph[j].emplace_back(i);
        }
      }
    }
    ans += maximum_matching(graph);
  }
  std::cout << ans << '\n';
  return 0;
}
