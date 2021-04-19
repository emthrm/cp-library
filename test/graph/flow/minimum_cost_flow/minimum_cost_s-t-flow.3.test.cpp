/*
 * @brief グラフ/フロー/最小費用流/最小費用 $s$-$t$-フロー 最短路反復法版 (minimum_cost_maximum_flow(s, t, flow))
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1088"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <tuple>
#include <vector>
#include "../../../../graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp"

int main() {
  struct Train {
    int x, y, c;
  };

  while (true) {
    int n;
    std::cin >> n;
    if (n == 0) break;
    int ver = 0;
    std::vector<std::vector<Train>> m(n - 1);
    std::vector<std::vector<int>> arrive(n - 1);
    for (int i = 0; i < n - 1; ++i) {
      int mi;
      std::cin >> mi;
      while (mi--) {
        int x, y, c;
        std::cin >> x >> y >> c;
        m[i].emplace_back(Train{x, y, c});
        arrive[i].emplace_back(y);
        ++ver;
      }
      std::sort(arrive[i].begin(), arrive[i].end());
      arrive[i].erase(std::unique(arrive[i].begin(), arrive[i].end()), arrive[i].end());
      ver += arrive[i].size() * 2;
    }
    MinimumCostSTFlow<int, long long> mcf(ver + 2);
    const int s = ver, t = ver + 1;
    for (int i = 0; i < m.front().size(); ++i) mcf.add_edge(s, i, 1, 0);
    int cur = 0;
    for (int i = 0; i < n - 1; ++i) {
      int sz = m[i].size();
      for (int j = 0; j < sz; ++j) {
        int idx = std::distance(arrive[i].begin(), std::lower_bound(arrive[i].begin(), arrive[i].end(), m[i][j].y));
        mcf.add_edge(cur + j, cur + sz + idx, 1, m[i][j].c);
      }
      cur += sz;
      sz = arrive[i].size();
      for (int j = 0; j < sz; ++j) mcf.add_edge(cur + j, cur + sz + j, 1, 0);
      cur += sz;
      if (i + 1 < n - 1) {
        for (int j = 0; j < sz; ++j) for (int k = 0; k < m[i + 1].size(); ++k) {
          if (arrive[i][j] <= m[i + 1][k].x) mcf.add_edge(cur + j, cur + sz + k, 1, 0);
        }
        cur += sz;
      }
    }
    for (int i = ver - arrive.back().size(); i < ver; ++i) mcf.add_edge(i, ver + 1, 1, 0);
    int g;
    std::cin >> g;
    int ans_class;
    long long ans_fare;
    std::tie(ans_class, ans_fare) = mcf.minimum_cost_maximum_flow(ver, ver + 1, g);
    std::cout << ans_class << ' ' << ans_fare << '\n';
  }
  return 0;
}
