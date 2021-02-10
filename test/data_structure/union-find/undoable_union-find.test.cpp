/*
 * @brief データ構造/union-find 木/undo 可能 union-find 木
 */
#define IGNORE
#define PROBLEM "https://codeforces.com/contest/1444/problem/C"

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <utility>
#include <vector>
#include "../../../graph/edge.hpp"
#include "../../../graph/is_bipartite.hpp"
#include "../../../data_structure/union-find/undoable_union-find.hpp"

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> c(n);
  std::vector<std::vector<int>> group(k);
  for (int i = 0; i < n; ++i) {
    std::cin >> c[i];
    --c[i];
    group[c[i]].emplace_back(i);
  }
  std::vector<std::vector<std::vector<Edge<bool>>>> subgraph(k);
  for (int i = 0; i < k; ++i) subgraph[i].resize(group[i].size());
  std::vector<int> a(m), b(m);
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    std::cin >> a[i] >> b[i];
    --a[i];
    --b[i];
    graph[a[i]].emplace_back(b[i]);
    graph[b[i]].emplace_back(a[i]);
    if (c[a[i]] == c[b[i]]) {
      int g = c[a[i]];
      int u = std::lower_bound(group[g].begin(), group[g].end(), a[i]) - group[g].begin(), v = std::lower_bound(group[g].begin(), group[g].end(), b[i]) - group[g].begin();
      subgraph[g][u].emplace_back(u, v);
      subgraph[g][v].emplace_back(v, u);
    }
  }
  std::set<int> bad_group;
  std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> edges;
  std::vector<int> color(n, 0);
  for (int i = 0; i < k; ++i) {
    std::vector<int> color_i;
    if (is_bipartite(subgraph[i], color_i)) {
      for (int j = 0; j < group[i].size(); ++j) color[group[i][j]] = color_i[j];
    } else {
      bad_group.emplace(i);
    }
  }
  std::vector<int> id(n, -1), new_c;
  std::map<std::tuple<int, int, int>, int> mp;
  n = 0;
  for (int i = 0; i < k; ++i) {
    if (bad_group.count(i) == 1) continue;
    int cur = 0;
    for (int e : group[i]) {
      if (id[e] != -1) continue;
      id[e] = cur;
      new_c.emplace_back(i);
      new_c.emplace_back(i);
      mp[{i, cur, 0}] = n++;
      mp[{i, cur, 1}] = n++;
      std::queue<int> que({e});
      while (!que.empty()) {
        int ver = que.front(); que.pop();
        for (int dst : graph[ver]) {
          if (c[dst] == i && id[dst] == -1) {
            id[dst] = cur;
            que.emplace(dst);
          }
        }
      }
      ++cur;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (bad_group.count(c[a[i]]) == 1 || bad_group.count(c[b[i]]) == 1) continue;
    int u = mp[{c[a[i]], id[a[i]], color[a[i]]}], v = mp[{c[b[i]], id[b[i]], color[b[i]]}];
    if (u > v) std::swap(u, v);
    int u_group = new_c[u], v_group = new_c[v];
    if (u_group > v_group) std::swap(u_group, v_group);
    if (u_group < v_group) edges[{u_group, v_group}].emplace_back(u, v);
  }
  UndoableUnionFind uf(n * 2);
  for (int i = 0; i < n; i += 2) {
    uf.unite(i * 2, (i + 1) * 2 + 1);
    uf.unite(i * 2 + 1, (i + 1) * 2);
  }
  uf.snap();
  long long ans = static_cast<long long>(k - bad_group.size()) * (k - bad_group.size() - 1) / 2;
  for (auto it = edges.begin(); it != edges.end(); ++it) {
    const std::vector<std::pair<int, int>> &edge = it->second;
    std::set<int> vers;
    for (const std::pair<int, int> &e : edge) {
      int u, v; std::tie(u, v) = e;
      uf.unite(u * 2, v * 2 + 1);
      uf.unite(u * 2 + 1, v * 2);
      vers.emplace(u);
      vers.emplace(v);
    }
    bool is_bi = true;
    for (int ver : vers) is_bi &= !uf.same(ver * 2, ver * 2 + 1);
    ans -= !is_bi;
    uf.rollback();
  }
  std::cout << ans << '\n';
  return 0;
}
