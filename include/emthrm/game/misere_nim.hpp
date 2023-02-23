#ifndef EMTHRM_GAME_MISERE_NIM_HPP_
#define EMTHRM_GAME_MISERE_NIM_HPP_

#include <algorithm>
#include <vector>

#include "emthrm/game/nim.hpp"

namespace emthrm {

template <typename T>
bool misere_nim(const std::vector<T>& a) {
  std::vector<T> positive;
  positive.reserve(a.size());
  for (const T e : a) {
    if (e > 0) positive.emplace_back(e);
  }
  if (positive.empty()) [[unlikely]] return true;
  return *std::max_element(positive.begin(), positive.end()) == 1 ?
         positive.size() % 2 == 0 : nim(positive);
}

}  // namespace emthrm

#endif  // EMTHRM_GAME_MISERE_NIM_HPP_
