#pragma once
#include <functional>

void convert_online_dp_to_offline_dp(const int n, const std::function<void(int, int, int)> induce) {
  std::function<void(const int, const int)> solve = [&solve, &induce](const int l, const int r) -> void {
    if (l + 1 == r) {
      // dp(l) <- dp(l) ･ b_l.
      return;
    }
    const int m = (l + r) >> 1;
    solve(l, m);
    induce(l, m, r);
    solve(m, r);
  };
  if (n > 0) solve(0, n);
}
