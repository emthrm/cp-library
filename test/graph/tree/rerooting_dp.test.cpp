/*
 * @brief グラフ/木/全方位木 DP
 */
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

#include "../../../graph/edge.hpp"
#include "../../../graph/tree/rerooting_dp.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<Edge<int>>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int s, t, w;
    std::cin >> s >> t >> w;
    graph[s].emplace_back(s, t, w);
    graph[t].emplace_back(t, s, w);
  }
  const std::vector<std::pair<int, int>> ans = rerooting_dp(
      graph, std::vector<std::pair<int, int>>(n, {0, 0}),
      [](const std::pair<int, int>& x, const std::pair<int, int>& y)
          -> std::pair<int, int> {
        int tmp[]{x.first, x.second, y.first, y.second};
        std::sort(tmp, tmp + 4, std::greater<int>());
        return {tmp[0], tmp[1]};
      },
      [](const std::pair<int, int>& x, const Edge<int>& e)
          -> std::pair<int, int> { return {x.first + e.cost, 0}; },
      [](const std::pair<int, int>& x, const int ver) -> std::pair<int, int> {
        return x;
      });
  int diameter = 0;
  for (int i = 0; i < n; ++i) {
    diameter = std::max(diameter, ans[i].first + ans[i].second);
  }
  std::cout << diameter << '\n';
  return 0;
}
