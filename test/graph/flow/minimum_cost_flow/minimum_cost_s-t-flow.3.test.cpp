/*
 * @title グラフ/フロー/最小費用流/最小費用 $s$-$t$-フロー 最短路反復法版（最小費用最大流）
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1088
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

#include "emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp"

int main() {
  struct Train { int x, y, c; };
  while (true) {
    int n;
    std::cin >> n;
    if (n == 0) break;
    int num = 0;
    std::vector<std::vector<Train>> trains(n - 1);
    std::vector<std::vector<int>> times(n - 1);
    for (int i = 0; i < n - 1; ++i) {
      int m;
      std::cin >> m;
      num += m;
      while (m--) {
        int x, y, c;
        std::cin >> x >> y >> c;
        trains[i].emplace_back(Train{x, y, c});
        times[i].emplace_back(y);
      }
      std::sort(times[i].begin(), times[i].end());
      times[i].erase(std::unique(times[i].begin(), times[i].end()),
                     times[i].end());
      num += times[i].size() * 2;
    }
    emthrm::MinimumCostSTFlow<int, long long> minimum_cost_flow(num + 2);
    const int s = num, t = num + 1;
    for (int i = 0; std::cmp_less(i, trains.front().size()); ++i) {
      minimum_cost_flow.add_edge(s, i, 1, 0);
    }
    int w = 0;
    for (int i = 0; i < n - 1; ++i) {
      int m = trains[i].size();
      for (int j = 0; j < m; ++j) {
        const int idx = std::distance(
            times[i].begin(),
            std::lower_bound(times[i].begin(), times[i].end(), trains[i][j].y));
        minimum_cost_flow.add_edge(j + w, idx + w + m, 1, trains[i][j].c);
      }
      w += m;
      m = times[i].size();
      for (int j = 0; j < m; ++j) {
        minimum_cost_flow.add_edge(j + w, j + w + m, 1, 0);
      }
      w += m;
      if (i + 1 < n - 1) {
        for (int j = 0; j < m; ++j) {
          for (int k = 0; std::cmp_less(k, trains[i + 1].size()); ++k) {
            if (times[i][j] <= trains[i + 1][k].x) {
              minimum_cost_flow.add_edge(j + w, k + w + m, 1, 0);
            }
          }
        }
        w += m;
      }
    }
    for (int i = num - times.back().size(); i < num; ++i) {
      minimum_cost_flow.add_edge(i, t, 1, 0);
    }
    int g;
    std::cin >> g;
    const auto [ans_class, ans_fare] =
        minimum_cost_flow.minimum_cost_maximum_flow(s, t, g);
    std::cout << ans_class << ' ' << ans_fare << '\n';
  }
  return 0;
}
