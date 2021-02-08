/**
 * @brief ベル数の数表 $n = k$ 版
 * @docs docs/math/twelvefold_way/bell_number/bell_number.md
 */

#pragma once
#include <vector>
#include "../../fps/fps.hpp"

template <typename T>
std::vector<T> bell_number_init_with_fps(int val) {
  FPS<T> bell(val);
  bell[1] = 1;
  bell = bell.exp(val);
  bell[0] -= 1;
  bell = bell.exp(val);
  T fact = 1;
  for (int i = 0; i <= val; ++i) {
    bell[i] *= fact;
    fact *= i + 1;
  }
  return bell.co;
}
