/**
 * @brief 第1種スターリング数の数表 形式的冪級数版2
 * @docs docs/math/twelvefold_way/stirling_number/stirling_number_of_the_first_kind.md
 */

#pragma once
#include <vector>
#include "../../fps/fps.hpp"

template <typename T>
std::vector<T> stirling_number_of_the_first_kind_init_with_fps2(int n) {
  if (n == 0) return {1};
  std::vector<FPS<T>> stirling;
  stirling.reserve(n);
  for (int i = 0; i < n; ++i) {
    stirling.emplace_back(FPS<T>{-i, 1});
    // stirling.emplace_back(FPS<T>{i, 1});
  }
  while (stirling.size() > 1) {
    int sz = stirling.size();
    std::vector<FPS<T>> nx;
    nx.reserve(sz + (sz & 1));
    for (int i = 0; i + 1 < sz; i += 2) nx.emplace_back(stirling[i] * stirling[i + 1]);
    if (sz & 1) nx.emplace_back(stirling.back());
    stirling.swap(nx);
  }
  return stirling[0].co;
}
