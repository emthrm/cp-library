#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_HPP_
#define EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_HPP_

#include <numeric>
#include <vector>

#include "emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp"

namespace emthrm {

template <typename T>
std::vector<std::vector<T>> bell_number_init(const int n, const int k) {
  std::vector<std::vector<T>> b =
      stirling_number_of_the_second_kind_init<T>(n, k);
  for (int i = 0; i <= n; ++i) {
    std::partial_sum(b[i].begin(), b[i].end(), b[i].begin());
  }
  return b;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_HPP_
