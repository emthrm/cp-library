#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_PRODUCT_OF_POLYNOMIAL_SEQUENCE_HPP_
#define EMTHRM_MATH_FORMAL_POWER_SERIES_PRODUCT_OF_POLYNOMIAL_SEQUENCE_HPP_

#include <queue>
#include <vector>

namespace emthrm {

template <template <typename> class C, typename T>
C<T> product_of_polynomial_sequence(std::vector<C<T>> a) {
  const int n = a.size();
  if (n == 0) [[unlikely]] return C<T>{1};
  for (int i = 0; i < n; ++i) {
    a[i].shrink();
  }
  const auto compare = [&a](const int l, const int r) -> bool {
    return a[l].degree() > a[r].degree();
  };
  std::priority_queue<int, std::vector<int>, decltype(compare)> que(compare);
  for (int i = 0; i < n; ++i) {
    que.emplace(i);
  }
  while (que.size() > 1) {
    const int i = que.top();
    que.pop();
    const int j = que.top();
    que.pop();
    a[j] *= a[i];
    a[j].shrink();
    a[i].coef.clear();
    a[i].coef.shrink_to_fit();
    que.emplace(j);
  }
  return a[que.top()];
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_PRODUCT_OF_POLYNOMIAL_SEQUENCE_HPP_
