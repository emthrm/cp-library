#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_MULTIPOINT_EVALUATION_HPP_
#define EMTHRM_MATH_FORMAL_POWER_SERIES_MULTIPOINT_EVALUATION_HPP_

#include <algorithm>
#include <iterator>
#include <vector>

namespace emthrm {

template <template <typename> class C, typename T>
struct MultipointEvaluation {
  std::vector<T> f_x;
  std::vector<C<T>> subproduct_tree;

  explicit MultipointEvaluation(const std::vector<T> &xs)
      : f_x(xs.size()), subproduct_tree(xs.size() << 1), n(xs.size()) {
    std::transform(xs.begin(), xs.end(), std::next(subproduct_tree.begin(), n),
                   [](const T& x) -> C<T> { return C<T>{-x, 1}; });
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

}  // namespace emthrm

#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_MULTIPOINT_EVALUATION_HPP_
