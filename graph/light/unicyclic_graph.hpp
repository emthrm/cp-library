#pragma once
#include <queue>
#include <vector>

struct UnicyclicGraph {
  std::vector<int> loop, belong, mp;
  std::vector<bool> is_in_loop;
  std::vector<std::vector<std::vector<int>>> forest;
  std::vector<std::vector<int>> inv;

  UnicyclicGraph(int n) : n(n), is_in_loop(n, false), belong(n, -1), mp(n, -1), graph(n) {}

  void add_edge(int src_i, int dst_i) {
    int id = src.size();
    graph[src_i].emplace_back(id);
    graph[dst_i].emplace_back(id);
    src.emplace_back(src_i);
    dst.emplace_back(dst_i);
  }

  void build() {
    dfs(-1, 0);
    for (int i = 0; i < n; ++i) {
      if (is_in_loop[i] && graph[i].size() > 2) {
        int idx = forest.size();
        forest.emplace_back(std::vector<std::vector<int>>(1));
        belong[i] = idx;
        mp[i] = 0;
        inv.emplace_back(std::vector<int>{i});
        std::queue<int> que({i});
        while (!que.empty()) {
          int ver = que.front();
          que.pop();
          for (int id : graph[ver]) {
            int to = destination(id, ver);
            if (belong[to] == -1 && !is_in_loop[to]) {
              int nx = forest[idx].size();
              forest[idx].emplace_back();
              forest[idx][mp[ver]].emplace_back(nx);
              forest[idx][nx].emplace_back(mp[ver]);
              belong[to] = idx;
              mp[to] = nx;
              inv[idx].emplace_back(to);
              que.emplace(to);
            }
          }
        }
      }
    }
  }

private:
  int n;
  std::vector<std::vector<int>> graph;
  std::vector<int> src, dst;

  int destination(int id, int s) const {
    return src[id] == s ? dst[id] : src[id];
  }

  bool dfs(int prev_id, int ver) {
    loop.emplace_back(ver);
    is_in_loop[ver] = true;
    for (int id : graph[ver]) {
      if (id != prev_id) {
        int to = destination(id, ver);
        if (is_in_loop[to]) {
          for (int i = static_cast<int>(loop.size()) - 2; i >= 0; --i) {
            if (loop[i] == to) {
              for (int j = 0; j < i; ++j) is_in_loop[loop[j]] = false;
              loop.erase(loop.begin(), loop.begin() + i);
              break;
            }
          }
          return true;
        }
        if (dfs(id, to)) return true;
      }
    }
    is_in_loop[ver] = false;
    loop.pop_back();
    return false;
  }
};
