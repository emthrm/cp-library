#pragma once
#include <functional>
#include <vector>

template <typename Ring>
std::vector<Ring> fast_zeta_transform(
    std::vector<Ring> a, const bool adds_superset, const Ring ID = 0,
    const std::function<Ring(const Ring&, const Ring&)> fn =
        [](const Ring& a, const Ring& b) -> Ring { return a + b; }) {
  int n = a.size(), p = 1;
  while ((1 << p) < n) ++p;
  n = 1 << p;
  a.resize(n, ID);
  if (adds_superset) {
    for (int i = 1; i < n; i <<= 1) {
      for (int s = 0; s < n; ++s) {
        if (s & i) continue;
        a[s] = fn(a[s], a[s | i]);
      }
    }
  } else {
    for (int i = 1; i < n; i <<= 1) {
      for (int s = 0; s < n; ++s) {
        if (s & i) continue;
        a[s | i] = fn(a[s | i], a[s]);
      }
    }
  }
  return a;
}
