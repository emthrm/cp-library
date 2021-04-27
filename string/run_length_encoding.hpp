#pragma once
#include <string>
#include <utility>
#include <vector>

template <typename T = char, typename U = std::string>
std::vector<std::pair<T, int>> run_length_encoding(const U &s) {
  int n = s.size();
  std::vector<std::pair<T, int>> res;
  T now = s[0];
  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] != now) {
      res.emplace_back(now, cnt);
      cnt = 0;
    }
    now = s[i];
    ++cnt;
  }
  res.emplace_back(now, cnt);
  return res;
}
