#pragma once
#include <algorithm>
#include <string>
#include <vector>

std::vector<std::vector<int>> subsequence_dp(
    const std::string& s, const char basis = 'a', const int sigma = 26) {
  const int n = s.length();
  std::vector<std::vector<int>> nx(n, std::vector<int>(sigma, n));
  nx[n - 1][s[n - 1] - basis] = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    std::copy(nx[i + 1].begin(), nx[i + 1].end(), nx[i].begin());
    nx[i][s[i] - basis] = i;
  }
  return nx;
}
