#pragma once
#include <algorithm>
#include <utility>
#include <vector>

#include "../edge.hpp"

template <typename CostType>
struct HeavyLightDecomposition {
  std::vector<int> parent, subtree, id, inv, head;
  std::vector<CostType> cost;

  explicit HeavyLightDecomposition(
      const std::vector<std::vector<Edge<CostType>>>& graph,
      const int root = 0)
      : graph(graph) {
    const int n = graph.size();
    parent.assign(n, -1);
    subtree.assign(n, 1);
    dfs1(root);
    id.resize(n);
    inv.resize(n);
    head.assign(n, root);
    int cur_id = 0;
    dfs2(root, &cur_id);
  }

  template <typename Fn>
  void update_v(int u, int v, const Fn f) const {
    while (true) {
      if (id[u] > id[v]) std::swap(u, v);
      f(std::max(id[head[v]], id[u]), id[v] + 1);
      if (head[u] == head[v]) break;
      v = parent[head[v]];
    }
  }

  template <typename F, typename G, typename T>
  T query_v(int u, int v, const F f, const G g, const T id_t) const {
    T left = id_t, right = id_t;
    while (true) {
      if (id_t[u] > id_t[v]) {
        std::swap(u, v);
        std::swap(left, right);
      }
      left = g(left, f(std::max(id_t[head[v]], id_t[u]), id_t[v] + 1));
      if (head[u] == head[v]) break;
      v = parent[head[v]];
    }
    return g(left, right);
  }

  template <typename Fn>
  void update_subtree_v(const int ver, const Fn f) const {
    f(id[ver], id[ver] + subtree[ver]);
  }

  template <typename T, typename Fn>
  T query_subtree_v(const int ver, const Fn f) const {
    return f(id[ver], id[ver] + subtree[ver]);
  }

  template <typename Fn>
  void update_e(int u, int v, const Fn f) const {
    while (true) {
      if (id[u] > id[v]) std::swap(u, v);
      if (head[u] == head[v]) {
        f(id[u], id[v]);
        break;
      } else {
        f(id[head[v]] - 1, id[v]);
        v = parent[head[v]];
      }
    }
  }

  template <typename F, typename G, typename T>
  T query_e(int u, int v, const F f, const G g, const T id_t) const {
    T left = id_t, right = id_t;
    while (true) {
      if (id[u] > id[v]) {
        std::swap(u, v);
        std::swap(left, right);
      }
      if (head[u] == head[v]) {
        left = g(left, f(id[u], id[v]));
        break;
      } else {
        left = g(left, f(id[head[v]] - 1, id[v]));
        v = parent[head[v]];
      }
    }
    return g(left, right);
  }

  template <typename Fn>
  void update_subtree_e(const int ver, const Fn f) const {
    f(id[ver], id[ver] + subtree[ver] - 1);
  }

  template <typename T, typename Fn>
  T query_subtree_e(const int ver, const Fn f) const {
    return f(id[ver], id[ver] + subtree[ver] - 1);
  }

  int lowest_common_ancestor(int u, int v) const {
    while (true) {
      if (id[u] > id[v]) std::swap(u, v);
      if (head[u] == head[v]) break;
      v = parent[head[v]];
    }
    return u;
  }

 private:
  std::vector<std::vector<Edge<CostType>>> graph;

  void dfs1(const int ver) {
    for (int i = 0; i < graph[ver].size(); ++i) {
      Edge<CostType>& e = graph[ver][i];
      if (e.dst != parent[ver]) {
        parent[e.dst] = ver;
        dfs1(e.dst);
        subtree[ver] += subtree[e.dst];
        if (subtree[e.dst] > subtree[graph[ver].front().dst]) {
          std::swap(e, graph[ver].front());
        }
      }
    }
  }

  void dfs2(const int ver, int* cur_id) {
    id[ver] = (*cur_id)++;
    inv[id[ver]] = ver;
    for (const Edge<CostType>& e : graph[ver]) {
      if (e.dst != parent[ver]) {
        head[e.dst] = (e.dst == graph[ver].front().dst ? head[ver] : e.dst);
        cost.emplace_back(e.cost);
        dfs2(e.dst, cur_id);
      }
    }
  }
};
