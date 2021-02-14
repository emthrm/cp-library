/*
 * @brief グラフ/行列木定理
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc018/tasks/arc018_4"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include "../../math/modint.hpp"
#include "../../graph/edge.hpp"
#include "../../data_structure/union-find/union-find.hpp"
#include "../../graph/matrix_tree_theorem.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(1000000007);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> costs;
  std::vector<Edge<int>> edges;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    --a; --b;
    edges.emplace_back(a, b, c);
    costs.emplace_back(c);
  }
  std::sort(costs.begin(), costs.end());
  costs.erase(std::unique(costs.begin(), costs.end()), costs.end());
  std::vector<std::vector<Edge<int>>> divided(costs.size());
  for (int i = 0; i < m; ++i) {
    divided[std::distance(costs.begin(), std::lower_bound(costs.begin(), costs.end(), edges[i].cost))].emplace_back(edges[i]);
  }
  UnionFind uf(n);
  long long cost = 0;
  ModInt way = 1;
  for (int i = 0; i < costs.size(); ++i) {
    std::vector<int> vers;
    for (Edge<int> &e : divided[i]) {
      e.src = uf.root(e.src);
      e.dst = uf.root(e.dst);
      if (e.src != e.dst) {
        vers.emplace_back(e.src);
        vers.emplace_back(e.dst);
      }
    }
    if (vers.empty()) continue;
    for (const Edge<int> &e : divided[i]) {
      if (uf.unite(e.src, e.dst)) cost += e.cost;
    }
    std::sort(vers.begin(), vers.end());
    vers.erase(std::unique(vers.begin(), vers.end()), vers.end());
    int sz = vers.size();
    UnionFind span(sz);
    for (Edge<int> &e : divided[i]) {
      if (e.src != e.dst) {
        e.src = std::distance(vers.begin(), std::lower_bound(vers.begin(), vers.end(), e.src));
        e.dst = std::distance(vers.begin(), std::lower_bound(vers.begin(), vers.end(), e.dst));
        span.unite(e.src, e.dst);
      }
    }
    std::vector<std::vector<Edge<int>>> divided2(sz);
    for (const Edge<int> &e : divided[i]) {
      if (e.src != e.dst) divided2[span.root(e.src)].emplace_back(e);
    }
    for (int j = 0; j < sz; ++j) {
      if (divided2[j].size() > 0) {
        std::vector<int> comp;
        for (const Edge<int> &e : divided2[j]) {
          comp.emplace_back(e.src);
          comp.emplace_back(e.dst);
        }
        std::sort(comp.begin(), comp.end());
        comp.erase(std::unique(comp.begin(), comp.end()), comp.end());
        std::vector<std::vector<Edge<int>>> graph(comp.size());
        for (Edge<int> &e : divided2[j]) {
          e.src = std::distance(comp.begin(), std::lower_bound(comp.begin(), comp.end(), e.src));
          e.dst = std::distance(comp.begin(), std::lower_bound(comp.begin(), comp.end(), e.dst));
          graph[e.src].emplace_back(e.src, e.dst, e.cost);
          graph[e.dst].emplace_back(e.dst, e.src, e.cost);
        }
        way *= matrix_tree_theorem(graph, ModInt(0));
      }
    }
  }
  std::cout << cost << ' ' << way << '\n';
  return 0;
}
