/*
 * @brief グラフ/木/木の直径 全方位木 DP 版
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include <iostream>
#include <vector>
#include "../../../graph/edge.hpp"
#include "../../../graph/tree/rerooting.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<Edge<long long>>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int s, t, w;
    std::cin >> s >> t >> w;
    graph[s].emplace_back(s, t, w);
    graph[t].emplace_back(t, s, w);
  }
  std::cout << rerooting(graph) << '\n';
  return 0;
}
