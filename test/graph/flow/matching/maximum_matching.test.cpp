/*
 * @brief グラフ/フロー/マッチング/一般グラフの最大マッチング
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3032"

#include <cmath>
#include <iostream>
#include <vector>
#include "../../../../graph/flow/matching/maximum_matching.hpp"

int main() {
  int n, A, B;
  std::cin >> n >> A >> B;
  int ans = 0;
  std::vector<int> a, b;
  while (n--) {
    int a_i, b_i;
    std::cin >> a_i >> b_i;
    const int x = std::abs(a_i - b_i);
    if (x <= A || (B <= x && x <= 2 * A)) {
      ++ans;
    } else {
      a.emplace_back(a_i);
      b.emplace_back(b_i);
    }
  }
  n = a.size();
  if (n > 0) {
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        const int x = std::abs((a[i] + a[j]) - (b[i] + b[j]));
        if (x <= A || (B <= x && x <= 2 * A)) {
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
