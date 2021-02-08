/*
 * @brief グラフ/二重頂点連結成分分解
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc045/tasks/arc045_d"

#include <functional>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include "../../data_structure/union-find/union-find.hpp"
#include "../../graph/edge.hpp"
#include "../../graph/biconnected_component.hpp"

int main() {
  int n;
  std::cin >> n;
  n = 2 * n + 1;
  std::vector<std::vector<int>> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    int xi, yi;
    std::cin >> xi >> yi;
    --xi; --yi;
    x[xi].emplace_back(i);
    y[yi].emplace_back(i);
  }
  UnionFind uf(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j + 1 < x[i].size(); ++j) uf.unite(x[i][j], x[i][j + 1]);
    for (int j = 0; j + 1 < y[i].size(); ++j) uf.unite(y[i][j], y[i][j + 1]);
  }
  std::map<int, std::vector<int>> mp;
  for (int i = 0; i < n; ++i) mp[uf.root(i)].emplace_back(i);
  int odd = 0;
  for (const std::pair<int, std::vector<int>> &pr : mp) odd += pr.second.size() & 1;
  std::vector<bool> ans(n, false);
  if (odd == 1) {
    for (const std::pair<int, std::vector<int>> &pr : mp) {
      const std::vector<int> &vers = pr.second;
      if (vers.size() % 2 == 0) continue;
      if (vers.size() == 1) {
        ans[vers[0]] = true;
        continue;
      }
      std::map<int, int> idx;
      for (int i = 0; i < vers.size(); ++i) idx[vers[i]] = i;
      std::vector<std::vector<Edge<bool>>> graph(vers.size());
      for (int i = 0; i < n; ++i) {
        std::vector<int> tmp;
        for (int j = 0; j < x[i].size(); ++j) {
          if (idx.count(x[i][j]) == 1) tmp.emplace_back(idx[x[i][j]]);
        }
        for (int j = 0; j + 1 < tmp.size(); ++j) {
          graph[tmp[j]].emplace_back(tmp[j], tmp[j + 1]);
          graph[tmp[j + 1]].emplace_back(tmp[j + 1], tmp[j]);
        }
        if (tmp.size() >= 3) {
          graph[tmp.front()].emplace_back(tmp.front(), tmp.back());
          graph[tmp.back()].emplace_back(tmp.back(), tmp.front());
        }
        tmp.clear();
        for (int j = 0; j < y[i].size(); ++j) {
          if (idx.count(y[i][j]) == 1) tmp.emplace_back(idx[y[i][j]]);
        }
        for (int j = 0; j + 1 < tmp.size(); ++j) {
          graph[tmp[j]].emplace_back(tmp[j], tmp[j + 1]);
          graph[tmp[j + 1]].emplace_back(tmp[j + 1], tmp[j]);
        }
        if (tmp.size() >= 3) {
          graph[tmp.front()].emplace_back(tmp.front(), tmp.back());
          graph[tmp.back()].emplace_back(tmp.back(), tmp.front());
        }
      }
      BiconnectedComponent<bool> bc(graph, true);
      std::map<int, int> ap_idx;
      for (int i = 0; i < bc.ap.size(); ++i) ap_idx[bc.ap[i]] = i;
      for (int i = 0; i < vers.size(); ++i) {
        if (ap_idx.count(i) == 0) ans[vers[i]] = true;
      }
      int sz = bc.vertices.size(), m = sz + bc.ap.size();
      std::vector<std::vector<int>> bctree(m);
      std::vector<int> cnt(m);
      for (int i = 0; i < sz; ++i) cnt[i] = bc.vertices[i].size();
      for (int i = 0; i < vers.size(); ++i) {
        if (ap_idx.count(i) == 1) {
          for (int e : bc.cutpoint[i]) {
            --cnt[e];
            bctree[e].emplace_back(sz + ap_idx[i]);
            bctree[sz + ap_idx[i]].emplace_back(e);
          }
          cnt[sz + ap_idx[i]] = 1;
        }
      }
      std::vector<int> subtree(m), odd_child(m, 0);
      std::function<void(int, int)> dfs1 = [&bctree, &cnt, &subtree, &odd_child, &dfs1](int par, int ver) -> void {
        subtree[ver] = cnt[ver];
        for (int e : bctree[ver]) {
          if (e != par) {
            dfs1(ver, e);
            odd_child[ver] += subtree[e] % 2;
            subtree[ver] += subtree[e];
          }
        }
      };
      dfs1(-1, 0);
      std::function<void(int, int, int)> dfs2 = [&ans, &vers, &bc, sz, &bctree, &subtree, &odd_child, &dfs2](int par, int ver, int tmp) -> void {
        if (ver >= sz && odd_child[ver] == 0 && tmp % 2 == 0) ans[vers[bc.ap[ver - sz]]] = true;
        for (int e : bctree[ver]) {
          if (e != par) dfs2(ver, e, tmp + subtree[ver] - subtree[e]);
        }
      };
      dfs2(-1, 0, 0);
    }
  }
  for (bool e : ans) std::cout << (e ? "OK\n" : "NG\n");
  return 0;
}
