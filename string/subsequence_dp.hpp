#pragma once
#include <string>
#include <vector>

std::vector<std::vector<int>> nx_init(const std::string &s, const char basis = 'a', const int char_sz = 26) {
  int n = s.size();
  std::vector<std::vector<int>> nx(n, std::vector<int>(char_sz, n));
  nx[n - 1][s[n - 1] - basis] = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    for (int j = 0; j < char_sz; ++j) nx[i][j] = nx[i + 1][j];
    nx[i][s[i] - basis] = i;
  }
  return nx;
}
