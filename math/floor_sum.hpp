#pragma once
#include <utility>

long long floor_sum(long long a, long long b, long long m, long long n) {
  long long res = 0;
  if (a < 0) {
    long long nx_a = a % m;
    if (nx_a < 0) nx_a += m;
    res -= (n * (n - 1) / 2) * ((nx_a - a) / m);
    a = nx_a;
  }
  if (b < 0) {
    long long nx_b = b % m;
    if (nx_b < 0) nx_b += m;
    res -= n * ((nx_b - b) / m);
    b = nx_b;
  }
  while (true) {
    if (a >= m) {
      res += (n * (n - 1) / 2) * (a / m);
      a %= m;
    }
    if (b >= m) {
      res += n * (b / m);
      b %= m;
    }
    long long y_max = a * n + b;
    if (y_max < m) break;
    b = y_max % m;
    n = y_max / m;
    std::swap(a, m);
  }
  return res;
}
