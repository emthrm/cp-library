/*
 * @brief グラフ/木/最小共通祖先 オイラーツアー版
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667"

#include <iostream>
#include <vector>
#include "../../../graph/edge.hpp"
#include "../../../graph/tree/lca_euler_tour.hpp"
#include "../../../data_structure/segment_tree/lazy_segment_tree.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::vector<Edge<long long>>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[a].emplace_back(a, b, 0);
    graph[b].emplace_back(b, a, 0);
  }
  LCA<long long> lca(graph, 0);
  struct Node {
    using Monoid = struct {
      int cnt;
      long long sum;
    };
    using OperatorMonoid = int;
    static constexpr Monoid m_unity() { return Monoid{0, 0}; }
    static constexpr OperatorMonoid o_unity() { return 0; }
    static Monoid m_merge(const Monoid &a, const Monoid &b) { return Monoid{a.cnt + b.cnt, a.sum + b.sum}; }
    static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid &b) { return a + b; }
    static Monoid apply(Monoid a, const OperatorMonoid &b) {
      a.sum += b * a.cnt;
      return a;
    }
  };
  std::vector<Node::Monoid> init(lca.cost.size(), Node::Monoid{0, 0});
  for (int i = 1; i < n; ++i) {
    init[lca.down[i]].cnt = 1;
    init[lca.up[i]].cnt = -1;
  }
  LazySegmentTree<Node> seg(init);
  auto fn = [&seg](int a, int b) -> long long { return seg.get(a, b).sum; };
  while (q--) {
    int query;
    std::cin >> query;
    if (query == 0) {
      int u, v;
      std::cin >> u >> v;
      int l = lca.query(u, v);
      std::cout << lca.e_query<long long>(l, u, fn) + lca.e_query<long long>(l, v, fn) << '\n';
    } else if (query == 1) {
      int v, x;
      std::cin >> v >> x;
      lca.subtree_e_update(v, [&seg, x](int a, int b) { seg.apply(a, b, x); });
    }
  }
  return 0;
}
