#pragma once

template <typename Real = double, typename F, typename T>
Real aliens_dp(const F calc, const int d, const T& max_abs_c, int repeat) {
  const auto l = [calc, d](const Real lambda) -> Real {
    return -lambda * d + calc(lambda);
  };
  Real ub = max_abs_c * 3, lb = -ub;
  while (repeat--) {
    const Real mid1 = (lb + lb + ub) / 3, mid2 = (lb + ub + ub) / 3;
    if (l(mid1) > l(mid2)) {
      ub = mid2;
    } else {
      lb = mid1;
    }
  }
  return l(ub);
}
