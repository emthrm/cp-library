/**
 * @brief Morris-Pratt algorithm
 * @docs docs/string/knuth-morris-pratt.md
 */

#pragma once
#include <string>
#include <vector>

struct MorrisPratt {
  std::vector<int> border;

  MorrisPratt(const std::string &s) : str(s) {
    int n = str.length();
    border.assign(1, -1);
    for (int i = 0; i < n; ++i) solve(i);
  }

  void add(char c) {
    int idx = str.length();
    str += c;
    solve(idx);
  }

  std::vector<int> match(const std::string &t) const {
    int n = str.length(), m = t.length();
    std::vector<int> res;
    int k = 0;
    for (int i = 0; i < m; ++i) {
      while (k >= 0 && t[i] != str[k]) k = border[k];
      if (++k == n) res.emplace_back(i - n + 1);
    }
    return res;
  }

  int period(int idx) const { return idx - border[idx]; }

private:
  int j = -1;
  std::string str;

  void solve(int idx) {
    while (j >= 0 && str[idx] != str[j]) j = border[j];
    border.emplace_back(++j);
  }
};
