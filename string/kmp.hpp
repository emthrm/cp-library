/**
 * @brief KMP 法
 * @docs docs/string/kmp.md
 */

#pragma once
#include <string>
#include <vector>

template <typename T = std::string>
struct KMP {
  std::vector<int> border;

  KMP(const T &s) : str(s) {
    int n = str.size();
    border.resize(n + 1);
    border[0] = -1;
    int j = -1;
    for (int i = 0; i < n; ++i) {
      while (j >= 0 && str[i] != str[j]) j = border[j];
      ++j;
      border[i + 1] = i + 1 < n && str[i + 1] == str[j] ? border[j] : j;
    }
  }

  std::vector<int> match(const T &t) const {
    int n = str.size(), m = t.size();
    std::vector<int> res;
    int k = 0;
    for (int i = 0; i < m; ++i) {
      while (k >= 0 && t[i] != str[k]) k = border[k];
      if (++k == n) res.emplace_back(i - n + 1);
    }
    return res;
  }

private:
  T str;
};
