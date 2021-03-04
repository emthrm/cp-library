/**
 * @brief 第1種スターリング数の数表 形式的冪級数版
 * @docs docs/math/twelvefold_way/stirling_number/stirling_number.md
 */

#pragma once
#include <vector>
#include "../../fps/fps.hpp"

template <typename T>
std::vector<T> stirling_number_of_the_first_kind_init_with_fps(int n) {
  if (n == 0) return {1};
  FPS<T> stirling{0, 1};
  for (int i = 30 - __builtin_clz(n); i >= 0; --i) {
    stirling *= stirling.translate(-(static_cast<int>(stirling.co.size()) - 1));
    // stirling *= stirling.translate(stirling.co.size() - 1);
    if (n >> i & 1) {
      int deg = stirling.co.size() - 1;
      stirling.co.emplace_back(0);
      for (int i = deg; i >= 0; --i) stirling.co[i + 1] = stirling.co[i];
      stirling.co[0] = 0;
      for (int i = 0; i <= deg; ++i) stirling.co[i] += stirling.co[i + 1] * (-deg);
    }
  }
  return stirling.co;
}
