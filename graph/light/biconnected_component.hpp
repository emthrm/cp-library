#pragma once
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include "lowlink.hpp"

struct BiconnectedComponent : Lowlink {
  std::vector<std::vector<std::pair<int, int>>> block;
  std::vector<int> id;
  std::vector<std::vector<int>> vertices, cutpoint;

  BiconnectedComponent(const std::vector<std::vector<int>> &graph, bool heavy = false) : Lowlink(graph), heavy(heavy) {
    int n = graph.size();
    id.assign(n, -2);
    if (heavy) {
      cutpoint.resize(n);
      is_ap.assign(n, false);
      for (int e : this->ap) is_ap[e] = true;
    }
    for (int i = 0; i < n; ++i) {
      if (id[i] == -2) {
        id[i] = -1;
        dfs(-1, i);
      }
    }
    // if (heavy) {
    //   int sz = vertices.size();
    //   for (int i = 0; i < sz; ++i) {
    //     std::sort(block[i].begin(), block[i].end());
    //     std::sort(vertices[i].begin(), vertices[i].end());
    //   }
    //   for (int i = 0; i < n; ++i) std::sort(cutpoint[i].begin(), cutpoint[i].end());
    // }
  }

private:
  using P = std::pair<int, int>;

  bool heavy;
  std::vector<bool> is_ap;
  std::vector<P> tmp;

  void dfs(int par, int ver) {
    for (int e : this->graph[ver]) {
      if (e == par) continue;
      if (id[e] == -2 || this->order[ver] > this->order[e]) tmp.emplace_back(std::minmax(ver, e));
      if (id[e] == -2) {
        id[e] = -1;
        dfs(ver, e);
        if (this->order[ver] <= this->lowlink[e]) {
          int idx = block.size();
          block.emplace_back();
          std::set<int> st;
          while (true) {
            P pr = tmp.back();
            block[idx].emplace_back(pr);
            if (heavy) {
              st.emplace(pr.first);
              st.emplace(pr.second);
            }
            tmp.pop_back();
            if (pr.first == std::min(ver, e) && pr.second == std::max(ver, e)) break;
          }
          if (heavy) {
            vertices.emplace_back();
            for (int el : st) {
              vertices[idx].emplace_back(el);
              if (is_ap[el]) {
                cutpoint[el].emplace_back(idx);
              } else {
                id[el] = idx;
              }
            }
          }
        }
      }
    }
  }
};
