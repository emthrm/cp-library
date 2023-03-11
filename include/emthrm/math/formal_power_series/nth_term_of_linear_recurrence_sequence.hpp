#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_NTH_TERM_OF_LINEAR_RECURRENCE_SEQUENCE_HPP_
#define EMTHRM_MATH_FORMAL_POWER_SERIES_NTH_TERM_OF_LINEAR_RECURRENCE_SEQUENCE_HPP_

#include <cassert>

#include "emthrm/math/formal_power_series/bostan-mori.hpp"
#include "emthrm/math/formal_power_series/formal_power_series.hpp"

namespace emthrm {

template <typename T>
T nth_term_of_linear_recurrence_sequence(
    FormalPowerSeries<T> a, FormalPowerSeries<T> q, const long long n) {
  q.shrink();
  const int d = q.degree();
  assert(d >= 0 && q[0] != 0);
  if (a.degree() >= n) return a[n];
  assert(a.degree() >= d - 1);
  a.resize(d - 1);
  a *= q;
  a.resize(d - 1);
  return bostan_mori(a, q, n);
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_NTH_TERM_OF_LINEAR_RECURRENCE_SEQUENCE_HPP_
