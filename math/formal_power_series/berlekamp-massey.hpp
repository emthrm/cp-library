#include <algorithm>
#include <utility>
#include <vector>

template <typename T>
std::vector<T> berlekamp_massey(const std::vector<T>& s) {
  const int n = s.size();
  std::vector<T> b{1}, c{1};
  int m = b.size(), l = c.size(), f = -1;
  T prv_delta = 1;
  for (int i = 0; i < n; ++i) {
    T delta = 0;
    for (int j = 0; j < l; ++j) {
      delta += c[j] * s[i - (l - j - 1)];
    }
    if (delta == 0) continue;
    const T mul = -delta / prv_delta;
    const int shift = i - f;
    if (m + shift > l) {
      const std::vector<T> nxt_b = c;
      c.insert(c.begin(), m + shift - l, 0);
      for (int j = 0; j < m; ++j) {
        c[j] += mul * b[j];
      }
      b = nxt_b;
      m += shift;
      std::swap(m, l);
      f = i;
      prv_delta = delta;
    } else {
      for (int j = 0; j < m; ++j) {
        c[l - 1 - shift - j] += mul * b[m - 1 - j];
      }
    }
  }
  std::reverse(c.begin(), c.end());
  return c;
}
