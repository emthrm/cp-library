#ifndef EMTHRM_DYNAMIC_PROGRAMMING_CONVERT_ONLINE_DP_TO_OFFLINE_DP_HPP_
#define EMTHRM_DYNAMIC_PROGRAMMING_CONVERT_ONLINE_DP_TO_OFFLINE_DP_HPP_

#include <functional>
#include <numeric>

namespace emthrm {

void convert_online_dp_to_offline_dp(
    const int n, const std::function<void(int, int, int)> induce) {
  const auto solve = [induce](auto solve, const int l, const int r) -> void {
    if (l + 1 == r) {
      // dp(l) <- dp(l) ･ b_l
      return;
    }
    const int m = std::midpoint(l, r);
    solve(solve, l, m);
    induce(l, m, r);
    solve(solve, m, r);
  };
  if (n > 0) [[likely]] solve(solve, 0, n);
}

}  // namespace emthrm

#endif  // EMTHRM_DYNAMIC_PROGRAMMING_CONVERT_ONLINE_DP_TO_OFFLINE_DP_HPP_
