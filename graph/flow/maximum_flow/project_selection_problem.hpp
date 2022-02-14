#pragma once
#include <cassert>
#include <limits>
#include <vector>

template <template <typename> class C, typename T>
struct ProjectSelectionProblem {
  explicit ProjectSelectionProblem(const int n)
      : inf(std::numeric_limits<T>::max()), n(n), res(0) {}

  void add_neq(const int u, const int v, const T cost) {
    assert(cost >= 0);
    us.emplace_back(u);
    vs.emplace_back(v);
    costs.emplace_back(cost);
  }

  void add(const int v, bool group, T cost) {
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

  void add_or(const std::vector<int>& v, const bool group, const T cost) {
    assert(cost >= 0);
    add(n, group, cost);
    if (group) {
      for (const int e : v) add_neq(n, e, inf);
    } else {
      for (const int e : v) add_neq(e, n, inf);
    }
    ++n;
  }

  void add_or(const int u, const int v, const bool group, const T cost) {
    add_or({u, v}, group, cost);
  }

  void add_eq(const std::vector<int>& v, const bool group, T cost) {
    assert(cost <= 0);
    cost = -cost;
    res += cost;
    add_or(v, !group, cost);
  }

  void add_eq(const int u, const int v, const bool group, const T cost) {
    add_eq({u, v}, group, cost);
  }

  T solve() {
    C<T> mf(n + 2);
    const int neq_size = costs.size();
    for (int i = 0; i < neq_size; ++i) {
      mf.add_edge(us[i] < 0 ? us[i] + n + 2 : us[i],
                  vs[i] < 0 ? vs[i] + n + 2 : vs[i], costs[i]);
    }
    return mf.maximum_flow(n, n + 1, inf) - res;
  }

private:
  const T inf;
  int n;
  T res;
  std::vector<int> us, vs;
  std::vector<T> costs;
};
