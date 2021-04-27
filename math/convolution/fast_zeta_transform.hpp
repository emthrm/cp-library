#pragma once
#include <vector>

template <typename Ring, typename Fn>
std::vector<Ring> fast_zeta_transform(
  std::vector<Ring> a,
  bool is_superset,
  const Ring ID = 0,
  Fn fn = [](const Ring &a, const Ring &b) -> Ring { return a + b; }
) {
  int n = a.size(), p = 1;
  while ((1 << p) < n) ++p;
  n = 1 << p;
  a.resize(n, ID);
  if (is_superset) {
    for (int i = 1; i < n; i <<= 1) for (int j = 0; j < n; ++j) {
      if ((j & i) == 0) a[j] = fn(a[j], a[j | i]);
    }
  } else {
    for (int i = 1; i < n; i <<= 1) for (int j = 0; j < n; ++j) {
      if ((j & i) == 0) a[j | i] = fn(a[j | i], a[j]);
    }
  }
  return a;
}
