#pragma once
#include <vector>

template <template <typename> class C, typename T>
struct MultipointEvaluation {
  std::vector<C<T>> node;
  std::vector<T> val;

  MultipointEvaluation(const std::vector<T> &xs) : n(xs.size()), val(xs.size()) {
    node.resize(n << 1);
    for (int i = 0; i < n; ++i) node[n + i] = C<T>{-xs[i], 1};
    for (int i = n - 1; i > 0; --i) node[i] = node[i << 1] * node[(i << 1) + 1];
  }

  void calc(const C<T> &f) { dfs(f, 1); }

private:
  int n;

  void dfs(C<T> poly, int pos) {
    poly %= node[pos];
    if (pos < n) {
      dfs(poly, pos << 1);
      dfs(poly, (pos << 1) + 1);
    } else {
      val[pos - n] = poly[0];
    }
  }
};
