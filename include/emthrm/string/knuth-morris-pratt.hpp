/**
 * @brief Knuth–Morris–Pratt algorithm
 * @docs docs/string/knuth-morris-pratt.md
 */

#ifndef EMTHRM_STRING_KNUTH_MORRIS_PRATT_HPP_
#define EMTHRM_STRING_KNUTH_MORRIS_PRATT_HPP_

#include <string>
#include <vector>

namespace emthrm {

template <typename T = std::string>
struct KnuthMorrisPratt {
  std::vector<int> border;

  explicit KnuthMorrisPratt(const T& s) : s(s) {
    const int n = s.size();
    border.assign(n + 1, -1);
    for (int i = 0, j = -1; i < n; ++i) {
      while (j >= 0 && s[i] != s[j]) j = border[j];
      ++j;
      border[i + 1] = (i + 1 < n && s[i + 1] == s[j] ? border[j] : j);
    }
  }

  std::vector<int> match(const T& t) const {
    const int n = s.size(), m = t.size();
    std::vector<int> res;
    for (int i = 0, k = 0; i < m; ++i) {
      while (k >= 0 && t[i] != s[k]) k = border[k];
      if (++k == n) res.emplace_back(i - n + 1);
    }
    return res;
  }

 private:
  const T s;
};

}  // namespace emthrm

#endif  // EMTHRM_STRING_KNUTH_MORRIS_PRATT_HPP_
