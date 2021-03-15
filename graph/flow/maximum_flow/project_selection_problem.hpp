#pragma once
#include <cassert>
#include <limits>
#include <vector>

template <template <typename> class C, typename T>
struct ProjectSelectionProblem {
  ProjectSelectionProblem(int n) : n(n) {}

  void add_neq(int u, int v, T cost) {
    assert(cost >= 0);
    us.emplace_back(u);
    vs.emplace_back(v);
    costs.emplace_back(cost);
  }

  void add(int v, bool group, T cost) {
    if (cost < 0) {
      cost = -cost;
      res += cost;
      group = !group;
    }
    if (group) {
      add_neq(-2, v, cost);  // -2 represents S.
    } else {
      add_neq(v, -1, cost);  // -1 represents T.
    }
  }

  void add_or(const std::vector<int> &v, bool group, T cost) {
    assert(cost >= 0);
    add(n, group, cost);
    if (group) {
      for (int vi : v) add_neq(n, vi, inf);
    } else {
      for (int vi : v) add_neq(vi, n, inf);
    }
    ++n;
  }

  void add_or(int u, int v, bool group, T cost) { add_or({u, v}, group, cost); }

  void add_eq(const std::vector<int> &v, bool group, T cost) {
    assert(cost <= 0);
    cost = -cost;
    res += cost;
    add_or(v, !group, cost);
  }

  void add_eq(int u, int v, bool group, T cost) { add_eq({u, v}, group, cost); }

  T solve() {
    C<T> flow(n + 2);
    int neq_sz = costs.size();
    for (int i = 0; i < neq_sz; ++i) {
      flow.add_edge(us[i] < 0 ? us[i] + n + 2 : us[i], vs[i] < 0 ? vs[i] + n + 2 : vs[i], costs[i]);
    }
    return flow.maximum_flow(n, n + 1, inf) - res;
  }

private:
  const T inf = std::numeric_limits<T>::max();
  int n;
  T res = 0;
  std::vector<int> us, vs;
  std::vector<T> costs;
};
