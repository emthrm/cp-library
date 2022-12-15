#ifndef EMTHRM_DYNAMIC_PROGRAMMING_CONVERT_ONLINE_DP_TO_OFFLINE_DP_HPP_
#define EMTHRM_DYNAMIC_PROGRAMMING_CONVERT_ONLINE_DP_TO_OFFLINE_DP_HPP_

#include <functional>

namespace emthrm {

void convert_online_dp_to_offline_dp(
    const int n, const std::function<void(int, int, int)> induce) {
  const std::function<void(const int, const int)> solve =
      [induce, &solve](const int l, const int r) -> void {
        if (l + 1 == r) {
          // dp(l) <- dp(l) ･ b_l
          return;
        }
        const int m = (l + r) >> 1;
        solve(l, m);
        induce(l, m, r);
        solve(m, r);
      };
  if (n > 0) solve(0, n);
}

}  // namespace emthrm

#endif  // EMTHRM_DYNAMIC_PROGRAMMING_CONVERT_ONLINE_DP_TO_OFFLINE_DP_HPP_
