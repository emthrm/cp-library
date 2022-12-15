#ifndef EMTHRM_STRING_RUN_LENGTH_ENCODING_HPP_
#define EMTHRM_STRING_RUN_LENGTH_ENCODING_HPP_

#include <utility>
#include <vector>

namespace emthrm {

template <typename T = char, typename U>
std::vector<std::pair<T, int>> run_length_encoding(const U& s) {
  const int n = s.size();
  std::vector<std::pair<T, int>> res;
  if (n == 0) return res;
  T ch = s.front();
  int num = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] != ch) {
      res.emplace_back(ch, num);
      num = 0;
    }
    ch = s[i];
    ++num;
  }
  res.emplace_back(ch, num);
  return res;
}

}  // namespace emthrm

#endif  // EMTHRM_STRING_RUN_LENGTH_ENCODING_HPP_
