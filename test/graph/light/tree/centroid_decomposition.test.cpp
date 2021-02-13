#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include <cmath>
#include <functional>
#include <iostream>
#include <vector>
#include "../../../../graph/light/tree/centroid_decomposition.hpp"
#include "../../../../math/convolution/fft.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  CentroidDecomposition cd(graph);
  std::vector<bool> visited(n, false);
  std::vector<long long> x(n, 0);
  std::function<void(int)> rec = [n, &graph, &cd, &visited, &x, &rec](int root) -> void {
    visited[root] = true;
    std::vector<int> cnt{1};
    for (int child : graph[root]) {
      if (visited[child]) continue;
      std::vector<int> sub_cnt{0};
      std::function<void(int, int, int)> dfs = [&graph, &visited, &cnt, &sub_cnt, &dfs](int par, int ver, int dist) -> void {
        if (cnt.size() <= dist) cnt.resize(dist + 1, 0);
        ++cnt[dist];
        if (sub_cnt.size() <= dist) sub_cnt.resize(dist + 1, 0);
        ++sub_cnt[dist];
        for (int e : graph[ver]) {
          if (!visited[e] && e != par) dfs(ver, e, dist + 1);
        }
      };
      dfs(root, child, 1);
      std::vector<fft::Real> f = fft::convolution(sub_cnt, sub_cnt);
      for (int i = 0; i < f.size() && i < n; ++i) x[i] -= std::round(f[i]);
    }
    std::vector<fft::Real> f = fft::convolution(cnt, cnt);
    for (int i = 0; i < f.size() && i < n; ++i) x[i] += std::round(f[i]);
    for (int e : cd.comp[root]) rec(e);
  };
  rec(cd.root);
  for (int i = 1; i < n; ++i) std::cout << x[i] / 2 << " \n"[i + 1 == n];
  return 0;
}
