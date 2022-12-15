/**
 * @brief 二部グラフの最大マッチング
 * @docs docs/graph/flow/matching/matching.md
 */

#ifndef EMTHRM_GRAPH_FLOW_MATCHING_BIPARTITE_MATCHING_HPP_
#define EMTHRM_GRAPH_FLOW_MATCHING_BIPARTITE_MATCHING_HPP_

#include <vector>

namespace emthrm {

struct BipartiteMatching {
  std::vector<int> match;

  explicit BipartiteMatching(const int n)
      : match(n, -1), n(n), t(0), is_alive(n, true), is_used(n, 0), graph(n) {}

  void add_edge(const int u, const int v) {
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }

  int solve() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (is_alive[i] && match[i] == -1) {
        ++t;
        res += dfs(i);
      }
    }
    return res;
  }

  void fix(const int ver) {
    is_alive[ver] = false;
    if (match[ver] != -1) is_alive[match[ver]] = false;
  }

  int activate(const int ver) {
    if (is_alive[ver]) return 0;
    is_alive[ver] = true;
    ++t;
    return dfs(ver) ? 1 : 0;
  }

  int deactivate(const int ver) {
    if (!is_alive[ver]) return 0;
    is_alive[ver] = false;
    const int m = match[ver];
    if (m == -1) return 0;
    match[ver] = match[m] = -1;
    ++t;
    return dfs(m) ? 0 : -1;
  }

 private:
  const int n;
  int t;
  std::vector<bool> is_alive;
  std::vector<int> is_used;
  std::vector<std::vector<int>> graph;

  bool dfs(const int ver) {
    is_used[ver] = t;
    for (const int dst : graph[ver]) {
      if (!is_alive[dst]) continue;
      const int m = match[dst];
      if (m == -1 || (is_used[m] < t && dfs(m))) {
        match[ver] = dst;
        match[dst] = ver;
        return true;
      }
    }
    return false;
  }
};

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_FLOW_MATCHING_BIPARTITE_MATCHING_HPP_
