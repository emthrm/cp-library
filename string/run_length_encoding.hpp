#pragma once
#include <utility>
#include <vector>

template <typename T = char, typename U>
std::vector<std::pair<T, int>> run_length_encoding(const U& s) {
  const int n = s.size();
  std::vector<std::pair<T, int>> res;
  if (n == 0) return res;
  T ch = s.front();
  int num = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] != ch) {
      res.emplace_back(ch, num);
      num = 0;
    }
    ch = s[i];
    ++num;
  }
  res.emplace_back(ch, num);
  return res;
}
