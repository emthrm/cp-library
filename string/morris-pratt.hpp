/**
 * @brief Morris–Pratt algorithm
 * @docs docs/string/knuth-morris-pratt.md
 */

#pragma once
#include <string>
#include <vector>

struct MorrisPratt {
  std::string s;
  std::vector<int> border;

  explicit MorrisPratt(const std::string& s) : s(s), border({-1}), j(-1) {
    const int n = s.length();
    for (int i = 0; i < n; ++i) {
      solve(i);
    }
  }

  void add(const char c) {
    s += c;
    solve(s.length() - 1);
  }

  std::vector<int> match(const std::string& t) const {
    const int n = s.length(), m = t.length();
    std::vector<int> res;
    for (int i = 0, k = 0; i < m; ++i) {
      while (k >= 0 && t[i] != s[k]) k = border[k];
      if (++k == n) res.emplace_back(i - n + 1);
    }
    return res;
  }

  int period(const int idx) const { return idx - border[idx]; }

 private:
  int j;

  void solve(const int idx) {
    while (j >= 0 && s[idx] != s[j]) j = border[j];
    border.emplace_back(++j);
  }
};
