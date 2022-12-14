/*
 * @brief 数学/基底
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2416"

#include <bitset>
#include <functional>
#include <iostream>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/math/basis.hpp"

int main() {
  constexpr int D = 60;
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<std::vector<Edge<long long>>> graph(n);
  while (m--) {
    int f, t;
    long long p;
    std::cin >> f >> t >> p;
    graph[f].emplace_back(f, t, p);
    graph[t].emplace_back(t, f, p);
  }
  std::vector<long long> x(n, -1);
  x[0] = 0;
  Basis<D> basis;
  const std::function<void(int, int)> dfs = [&graph, &x, &basis, &dfs](
      const int par, const int ver) {
    for (const Edge<long long>& e : graph[ver]) {
      if (e.dst != par) {
        if (x[e.dst] == -1) {
          x[e.dst] = x[ver] ^ e.cost;
          dfs(ver, e.dst);
        } else {
          basis.add(x[ver] ^ x[e.dst] ^ e.cost);
        }
      }
    }
  };
  dfs(-1, 0);
  while (q--) {
    int a, b;
    std::cin >> a >> b;
    std::bitset<D> ans(x[a] ^ x[b]);
    for (int i = 0; i < basis.rank(); ++i) {
      if (!ans[basis.msb[i]]) ans ^= basis.v[i];
    }
    std::cout << ans.to_ulong() << '\n';
  }
  return 0;
}
