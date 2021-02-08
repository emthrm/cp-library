/*
 * @brief グラフ/巡回セールスマン問題
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A"

#include <iostream>
#include <vector>
#include "../../graph/tsp.hpp"

int main() {
  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
  int v, e;
  std::cin >> v >> e;
  std::vector<std::vector<long long>> g(v, std::vector<long long>(v, LINF));
  while (e--) {
    int s, t, d;
    std::cin >> s >> t >> d;
    g[s][t] = d;
  }
  long long ans = tsp(g, LINF);
  std::cout << (ans == LINF ? -1 : ans) << '\n';
  return 0;
}
