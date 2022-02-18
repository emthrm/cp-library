#pragma once
#include <algorithm>
#include <iterator>
#include <vector>

template <typename T>
T kita_masa(const std::vector<T>& c, const std::vector<T>& a,
            const long long n) {
  const int k = c.size();
  if (n < k) return a[n];
  std::vector<T> coefficient[3]{std::vector<T>(k, 0),
                                std::vector<T>(k, 0),
                                std::vector<T>(k, 0)};
  if (k == 1) {
    coefficient[0][0] = c[0] * a[0];
  } else {
    coefficient[0][1] = 1;
  }
  const auto succ = [&c, k, &coefficient]() -> void {
    for (int i = 0; i < k - 1; ++i) {
      coefficient[0][i] += coefficient[0].back() * c[i + 1];
    }
    coefficient[0].back() *= c[0];
    std::rotate(coefficient[0].begin(),
                std::next(coefficient[0].begin(), k - 1), coefficient[0].end());
  };
  for (int bit = 62 - __builtin_clzll(n); bit >= 0; --bit) {
    for (int i = 1; i < 3; ++i) {
      std::copy(coefficient[0].begin(), coefficient[0].end(),
                coefficient[i].begin());
    }
    for (T& e : coefficient[1]) e *= coefficient[2][0];
    for (int i = 1; i < k; ++i) {
      succ();
      for (int j = 0; j < k; ++j) {
        coefficient[1][j] += coefficient[2][i] * coefficient[0][j];
      }
    }
    coefficient[0].swap(coefficient[1]);
    if (n >> bit & 1) succ();
  }
  T res = 0;
  for (int i = 0; i < k; ++i) {
    res += coefficient[0][i] * a[i];
  }
  return res;
}
