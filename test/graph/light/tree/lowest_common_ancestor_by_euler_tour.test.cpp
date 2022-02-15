#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667"

#include <iostream>
#include <vector>

#include "../../../../data_structure/lazy_segment_tree.hpp"
#include "../../../../graph/light/tree/lowest_common_ancestor_by_euler_tour.hpp"

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
  LowestCommonAncestor lowest_common_ancestor(graph, 0);
  struct M {
    using Monoid = struct { int num; long long sum; };
    using OperatorMonoid = int;
    static constexpr Monoid m_id() { return Monoid{0, 0}; }
    static constexpr OperatorMonoid o_id() { return 0; }
    static Monoid m_merge(const Monoid& a, const Monoid& b) {
      return Monoid{a.num + b.num, a.sum + b.sum};
    }
    static OperatorMonoid o_merge(const OperatorMonoid& a,
                                  const OperatorMonoid& b) {
      return a + b;
    }
    static Monoid apply(Monoid a, const OperatorMonoid& b) {
      a.sum += b * a.num;
      return a;
    }
  };
  std::vector<M::Monoid> init((n - 1) * 2, M::Monoid{0, 0});
  for (int i = 1; i < n; ++i) {
    init[lowest_common_ancestor.down[i]].num = 1;
    init[lowest_common_ancestor.up[i]].num = -1;
  }
  LazySegmentTree<M> seg(init);
  const auto fn = [&seg](const int a, const int b) -> long long {
    return seg.get(a, b).sum;
  };
  while (q--) {
    int type;
    std::cin >> type;
    if (type == 0) {
      int u, v;
      std::cin >> u >> v;
      const int lca = lowest_common_ancestor.query(u, v);
      std::cout << lowest_common_ancestor.query_e<long long>(lca, u, fn) +
                   lowest_common_ancestor.query_e<long long>(lca, v, fn)
                << '\n';
    } else if (type == 1) {
      int v, x;
      std::cin >> v >> x;
      lowest_common_ancestor.update_subtree_e(
          v, [&seg, x](const int a, const int b) { seg.apply(a, b, x); });
    }
  }
  return 0;
}
