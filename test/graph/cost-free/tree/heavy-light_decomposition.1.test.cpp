#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667"

#include <iostream>
#include <vector>

#include "emthrm/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp"
#include "emthrm/graph/cost-free/tree/heavy-light_decomposition.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  HeavyLightDecomposition heavy_light_decomposition(graph, 0);
  FenwickTreeSupportingRangeAddQuery<long long> bit(n - 1);
  const auto f = [&bit](const int l, const int r) -> long long {
    return bit.sum(l, r);
  };
  const auto g = [](const long long a, const long long b) -> long long {
    return a + b;
  };
  while (q--) {
    int type;
    std::cin >> type;
    if (type == 0) {
      int u, v;
      std::cin >> u >> v;
      std::cout << heavy_light_decomposition.query_e(u, v, f, g, 0LL) << '\n';
    } else if (type == 1) {
      int v, x;
      std::cin >> v >> x;
      heavy_light_decomposition.update_subtree_e(
          v,
          [&bit, x](const int l, const int r) -> void {
            return bit.add(l, r, x);
          });
    }
  }
  return 0;
}
