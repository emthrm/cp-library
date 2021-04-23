#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667"

#include <iostream>
#include <vector>
#include "../../../../graph/light/tree/hld.hpp"
#include "../../../../data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp"

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
  HLD hld(graph, 0);
  FenwickTreeSupportingRangeAddQuery<long long> bit(n - 1);
  auto f = [&bit](int l, int r) -> long long { return bit.sum(l, r); };
  auto g = [](long long a, long long b) -> long long { return a + b; };
  while (q--) {
    int query;
    std::cin >> query;
    if (query == 0) {
      int u, v;
      std::cin >> u >> v;
      std::cout << hld.e_query(u, v, f, g, 0LL) << '\n';
    } else if (query == 1) {
      int v, x;
      std::cin >> v >> x;
      hld.subtree_e_update(v, [&bit, x](int l, int r) -> void { return bit.add(l, r, x); });
    }
  }
  return 0;
}
