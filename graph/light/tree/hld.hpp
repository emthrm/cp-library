#pragma once
#include <algorithm>
#include <utility>
#include <vector>

struct HLD {
  std::vector<int> parent, subtree, id, inv, head;

  HLD(const std::vector<std::vector<int>> &graph, int root = 0) : graph(graph) {
    int n = graph.size();
    parent.assign(n, -1);
    subtree.assign(n, 1);
    id.resize(n);
    inv.resize(n);
    head.resize(n);
    dfs1(root);
    head[root] = root;
    int now_id = 0;
    dfs2(root, now_id);
  }

  template <typename Fn>
  void v_update(int u, int v, Fn f) const {
    while (true) {
      if (id[u] > id[v]) std::swap(u, v);
      f(std::max(id[head[v]], id[u]), id[v] + 1);
      if (head[u] == head[v]) return;
      v = parent[head[v]];
    }
  }

  template <typename T, typename F, typename G>
  T v_query(int u, int v, F f, G g, const T UNITY) const {
    T left = UNITY, right = UNITY;
    while (true) {
      if (id[u] > id[v]) {
        std::swap(u, v);
        std::swap(left, right);
      }
      left = g(left, f(std::max(id[head[v]], id[u]), id[v] + 1));
      if (head[u] == head[v]) break;
      v = parent[head[v]];
    }
    return g(left, right);
  }

  template <typename Fn>
  void subtree_v_update(int ver, Fn f) const { f(id[ver], id[ver] + subtree[ver]); }

  template <typename T, typename Fn>
  T subtree_v_query(int ver, Fn f) const { return f(id[ver], id[ver] + subtree[ver]); }

  template <typename Fn>
  void e_update(int u, int v, Fn f) const {
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

  template <typename T, typename F, typename G>
  T e_query(int u, int v, F f, G g, const T UNITY) const {
    T left = UNITY, right = UNITY;
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
  void subtree_e_update(int ver, Fn f) const { f(id[ver], id[ver] + subtree[ver] - 1); }

  template <typename T, typename Fn>
  T subtree_e_query(int ver, Fn f) const { return f(id[ver], id[ver] + subtree[ver] - 1); }

  int lca(int u, int v) const {
    while (true) {
      if (id[u] > id[v]) std::swap(u, v);
      if (head[u] == head[v]) return u;
      v = parent[head[v]];
    }
  }

private:
  std::vector<std::vector<int>> graph;

  void dfs1(int ver) {
    for (int &e : graph[ver]) {
      if (e != parent[ver]) {
        parent[e] = ver;
        dfs1(e);
        subtree[ver] += subtree[e];
        if (subtree[e] > subtree[graph[ver].front()]) std::swap(e, graph[ver].front());
      }
    }
  }

  void dfs2(int ver, int &now_id) {
    id[ver] = now_id++;
    inv[id[ver]] = ver;
    for (int e : graph[ver]) {
      if (e != parent[ver]) {
        head[e] = (e == graph[ver].front() ? head[ver] : e);
        dfs2(e, now_id);
      }
    }
  }
};
