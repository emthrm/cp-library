#pragma once
#include <cassert>
#include <limits>
#include <vector>

template <template <typename> class C, typename T>
struct ProjectSelectionProblem {
  ProjectSelectionProblem(int n) : n(n) {}

  void add_diff(int u, int v, T cost) {
    assert(cost >= 0);
    diff_u.emplace_back(u);
    diff_v.emplace_back(v);
    diff_cost.emplace_back(cost);
  }

  void add_same(int u, int v, int group, T cost) {
    assert(cost <= 0);
    cost = -cost;
    res += cost;
    add(n, group ^ 1, cost);
    if (group == 0) {
      add_diff(n, u, inf);
      add_diff(n, v, inf);
    } else if (group == 1) {
      add_diff(u, n, inf);
      add_diff(v, n, inf);
    }
    ++n;
  }

  void add(int ver, int group, T cost) {
    if (cost < 0) {
      cost = -cost;
      res += cost;
      add(ver, group ^ 1, cost);
    } else {
      if (group == 0) {
        add_diff(ver, -1, cost);
      } else {
        add_diff(-2, ver, cost);
      }
    }
  }

  T solve() {
    C<T> flow(n + 2);
    int diff_sz = diff_u.size();
    for (int i = 0; i < diff_sz; ++i) {
      if (diff_u[i] < 0) diff_u[i] += n + 2;
      if (diff_v[i] < 0) diff_v[i] += n + 2;
      flow.add_edge(diff_u[i], diff_v[i], diff_cost[i]);
    }
    int same_sz = same_u.size();
    for (int i = 0; i < same_sz; ++i) {
      if (same_u[i] < 0) same_u[i] += n + 2;
      if (same_v[i] < 0) same_v[i] += n + 2;
      flow.add_edge(same_u[i], same_v[i], same_cost[i]);
    }
    return flow.maximum_flow(n, n + 1, inf) - res;
  }

private:
  int n;
  const T inf = std::numeric_limits<T>::max();
  T res = 0;
  std::vector<int> diff_u, diff_v, same_u, same_v;
  std::vector<T> diff_cost, same_cost;
};
