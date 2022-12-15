#ifndef EMTHRM_STRING_Z_ALGORITHM_HPP_
#define EMTHRM_STRING_Z_ALGORITHM_HPP_

#include <algorithm>
#include <vector>

namespace emthrm {

template <typename T>
std::vector<int> z_algorithm(const T &s) {
  const int n = s.size();
  std::vector<int> res(n, 0);
  for (int i = 1, j = 0; i < n; ++i) {
    if (i + res[i - j] < j + res[j]) {
      res[i] = res[i - j];
    } else {
      res[i] = std::max(j + res[j] - i, 0);
      while (i + res[i] < n && s[i + res[i]] == s[res[i]]) ++res[i];
      j = i;
    }
  }
  res[0] = n;
  return res;
}

}  // namespace emthrm

#endif  // EMTHRM_STRING_Z_ALGORITHM_HPP_
