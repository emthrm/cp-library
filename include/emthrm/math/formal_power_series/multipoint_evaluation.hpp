#pragma once
#include <vector>

template <template <typename> class C, typename T>
struct MultipointEvaluation {
  std::vector<T> f_x;
  std::vector<C<T>> subproduct_tree;

  explicit MultipointEvaluation(const std::vector<T> &xs)
      : f_x(xs.size()), subproduct_tree(xs.size() << 1), n(xs.size()) {
    for (int i = 0; i < n; ++i) {
      subproduct_tree[i + n] = C<T>{-xs[i], 1};
    }
    for (int i = n - 1; i > 0; --i) {
      subproduct_tree[i] =
          subproduct_tree[i << 1] * subproduct_tree[(i << 1) + 1];
    }
  }

  void build(const C<T>& f) { dfs(f, 1); }

 private:
  const int n;

  void dfs(C<T> f, int node) {
    f %= subproduct_tree[node];
    if (node < n) {
      dfs(f, node << 1);
      dfs(f, (node << 1) + 1);
    } else {
      f_x[node - n] = f[0];
    }
  }
};
