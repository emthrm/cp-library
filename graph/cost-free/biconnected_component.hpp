#pragma once
#include <algorithm>
#include <set>
#include <utility>
#include <vector>

#include "./lowlink.hpp"

struct BiconnectedComponent : Lowlink {
  std::vector<int> id;
  std::vector<std::vector<int>> vertices, cutpoint;
  std::vector<std::vector<std::pair<int, int>>> block;

  BiconnectedComponent(const std::vector<std::vector<int>>& graph,
                       const bool is_full_ver = false)
      : Lowlink(graph), is_full_ver(is_full_ver) {
    const int n = graph.size();
    id.assign(n, -2);
    if (is_full_ver) {
      cutpoint.resize(n);
      is_articulation_point.assign(n, false);
      for (const int articulation_point : this->articulation_points) {
        is_articulation_point[articulation_point] = true;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (id[i] == -2) {
        id[i] = -1;
        dfs(-1, i);
      }
    }
    const int m = vertices.size();
    for (int i = 0; i < m; ++i) {
      std::sort(block[i].begin(), block[i].end());
    }
    if (is_full_ver) {
      for (int i = 0; i < m; ++i) {
        std::sort(vertices[i].begin(), vertices[i].end());
      }
      for (int i = 0; i < n; ++i) {
        std::sort(cutpoint[i].begin(), cutpoint[i].end());
      }
    }
  }

 private:
  const bool is_full_ver;
  std::vector<bool> is_articulation_point;
  std::vector<std::pair<int, int>> tmp;

  void dfs(const int par, const int ver) {
    for (const int e : this->graph[ver]) {
      if (e == par) continue;
      if (id[e] == -2 || this->order[ver] > this->order[e]) {
        tmp.emplace_back(std::minmax(ver, e));
      }
      if (id[e] == -2) {
        id[e] = -1;
        dfs(ver, e);
        if (this->order[ver] <= this->lowlink[e]) {
          const int idx = block.size();
          block.emplace_back();
          std::set<int> st;
          while (true) {
            const std::pair<int, int> pr = tmp.back();
            tmp.pop_back();
            block.back().emplace_back(pr);
            if (is_full_ver) {
              st.emplace(pr.first);
              st.emplace(pr.second);
            }
            if (pr == static_cast<std::pair<int, int>>(std::minmax(ver, e))) {
              break;
            }
          }
          if (is_full_ver) {
            vertices.emplace_back();
            for (const int el : st) {
              vertices.back().emplace_back(el);
              if (is_articulation_point[el]) {
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
