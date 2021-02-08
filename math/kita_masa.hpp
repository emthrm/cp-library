#pragma once
#include <algorithm>
#include <vector>

template <typename T>
T kita_masa(const std::vector<T> &c, const std::vector<T> &a, long long n) {
  int k = c.size();
  std::vector<T> coefficient((k << 1) - 1, 0);
  coefficient[0] = 1;
  int now = 0;
  std::vector<std::vector<T>> base(2, std::vector<T>((k << 1) - 1, 0));
  base[now][1] = 1;
  for (; n > 0; n >>= 1) {
    if (n & 1) {
      fill(base[now ^ 1].begin(), base[now ^ 1].end(), 0);
      for (int i = 0; i < k; ++i) for (int j = 0; j < k; ++j) base[now ^ 1][i + j] += coefficient[i] * base[now][j];
      fill(coefficient.begin(), coefficient.end(), 0);
      for (int i = (k << 1) - 2; i >= k; --i) {
        coefficient[i] += base[now ^ 1][i];
        for (int j = 0; j < k; ++j) coefficient[i - k + j] += coefficient[i] * c[j];
      }
      for (int i = 0; i < k; ++i) coefficient[i] += base[now ^ 1][i];
    }
    fill(base[now ^ 1].begin(), base[now ^ 1].end(), 0);
    for (int i = 0; i < k; ++i) for (int j = 0; j < k; ++j) base[now ^ 1][i + j] += base[now][i] * base[now][j];
    now ^= 1;
    for (int i = (k << 1) - 2; i >= k; --i) for (int j = 0; j < k; ++j) base[now][i - k + j] += base[now][i] * c[j];
  }
  T res = 0;
  for (int i = 0; i < k; ++i) res += coefficient[i] * a[i];
  return res;
}
