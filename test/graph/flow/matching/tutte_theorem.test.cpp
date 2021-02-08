/*
 * @brief グラフ/フロー/マッチング/タットの定理
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3032"

#include <cmath>
#include <iostream>
#include <vector>
#include "../../../../graph/flow/matching/tutte_theorem.hpp"

int main() {
  int n, A, B;
  std::cin >> n >> A >> B;
  int ans = 0;
  std::vector<int> a, b;
  while (n--) {
    int ai, bi;
    std::cin >> ai >> bi;
    int val = std::abs(ai - bi);
    if (val <= A || (B <= val && val <= 2 * A)) {
      ++ans;
    } else {
      a.emplace_back(ai);
      b.emplace_back(bi);
    }
  }
  n = a.size();
  if (n > 0) {
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
      int val = std::abs((a[i] + a[j]) - (b[i] + b[j]));
      if (val <= A || (B <= val && val <= 2 * A)) {
        graph[i].emplace_back(j);
        graph[j].emplace_back(i);
      }
    }
    ans += tutte_theorem(graph);
  }
  std::cout << ans << '\n';
  return 0;
}
