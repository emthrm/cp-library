#pragma once
#include <functional>

void convert_online_dp_to_offline_dp(const int n, const std::function<void(int, int, int)> induce) {
  std::function<void(const int, const int)> solve = [&solve, &induce](const int l, const int r) -> void {
    if (r <= l + 1) return;
    const int m = (l + r) >> 1;
    solve(l, m);
    induce(l, m, r);
    solve(m, r);
  };
  solve(0, n);
}
