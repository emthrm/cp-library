#pragma once
#include <utility>

long long floor_sum(long long a, long long b, long long m, long long n) {
  long long res = 0;
  if (a < 0) {
    long long nxt_a = a % m;
    if (nxt_a < 0) nxt_a += m;
    res -= n * (n - 1) / 2 * ((nxt_a - a) / m);
    a = nxt_a;
  }
  if (b < 0) {
    long long nxt_b = b % m;
    if (nxt_b < 0) nxt_b += m;
    res -= n * ((nxt_b - b) / m);
    b = nxt_b;
  }
  while (true) {
    if (a >= m) {
      res += n * (n - 1) / 2 * (a / m);
      a %= m;
    }
    if (b >= m) {
      res += n * (b / m);
      b %= m;
    }
    const long long y_max = a * n + b;
    if (y_max < m) break;
    b = y_max % m;
    n = y_max / m;
    std::swap(a, m);
  }
  return res;
}
