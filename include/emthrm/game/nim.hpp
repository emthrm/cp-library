#ifndef EMTHRM_GAME_NIM_HPP_
#define EMTHRM_GAME_NIM_HPP_

#include <vector>

namespace emthrm {

template <typename T>
bool nim(const std::vector<T>& a) {
  long long x = 0;
  for (const T e : a) x ^= e;
  return x != 0;
}

}  // namespace emthrm

#endif  // EMTHRM_GAME_NIM_HPP_
