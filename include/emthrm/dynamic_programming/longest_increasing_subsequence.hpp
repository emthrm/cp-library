#ifndef EMTHRM_DYNAMIC_PROGRAMMING_LONGEST_INCREASING_SUBSEQUENCE_HPP_
#define EMTHRM_DYNAMIC_PROGRAMMING_LONGEST_INCREASING_SUBSEQUENCE_HPP_

#include <algorithm>
#include <iterator>
#include <limits>
#include <vector>

namespace emthrm {

template <bool IS_STRICT = true, typename T>
std::vector<T> longest_increasing_subsequence(const std::vector<T>& a) {
  const T inf = std::numeric_limits<T>::max();
  const int n = a.size();
  std::vector<int> idx(n);
  std::vector<T> tmp(n, inf);
  for (int i = 0; i < n; ++i) {
    idx[i] = std::distance(
        tmp.begin(),
        IS_STRICT ? std::lower_bound(tmp.begin(), tmp.end(), a[i]) :
                    std::upper_bound(tmp.begin(), tmp.end(), a[i]));
    tmp[idx[i]] = a[i];
  }
  int res_size =
      std::distance(tmp.begin(), std::lower_bound(tmp.begin(), tmp.end(), inf));
  std::vector<T> res(res_size--);
  for (int i = n - 1; res_size >= 0 && i >= 0; --i) {
    if (idx[i] == res_size) res[res_size--] = a[i];
  }
  return res;
}

}  // namespace emthrm

#endif  // EMTHRM_DYNAMIC_PROGRAMMING_LONGEST_INCREASING_SUBSEQUENCE_HPP_
