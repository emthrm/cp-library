#ifndef EMTHRM_MATH_DIVISION_HPP_
#define EMTHRM_MATH_DIVISION_HPP_

#include <cassert>
#include <type_traits>

namespace emthrm {

#if __cplusplus >= 201402L
template <typename T, typename U>
std::common_type_t<T, U> floor_div(const T a, const U b) {
  assert(b != 0);
  return a / b - ((int{a < 0} ^ int{b < 0}) & int{a % b != 0});
}

template <typename T, typename U>
std::common_type_t<T, U> ceil_div(const T a, const U b) {
  assert(b != 0);
  return a / b + int{(a < 0) == (b < 0) && a % b != 0};
}
#else
template <typename T, typename U>
typename std::common_type<T, U>::type floor_div(const T a, const U b) {
  assert(b != 0);
  return a / b - ((int{a < 0} ^ int{b < 0}) & int{a % b != 0});
}

template <typename T, typename U>
typename std::common_type<T, U>::type ceil_div(const T a, const U b) {
  assert(b != 0);
  return a / b + int{(a < 0) == (b < 0) && a % b != 0};
}
#endif  // __cplusplus >= 201402L

}  // namespace emthrm

#endif  // EMTHRM_MATH_DIVISION_HPP_
