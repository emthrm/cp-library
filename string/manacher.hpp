#pragma once
#include <vector>

struct Manacher {
  template <typename T>
  Manacher(const T &s) {
    T str;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      str.push_back(s[i]);
      if (i + 1 < n) str.push_back('$');
    }
    n = str.size();
    radius.resize(n);
    int j = 1;
    for (int i = 0; i < n;) {
      while (i - j >= 0 && i + j < n && str[i - j] == str[i + j]) ++j;
      radius[i] = j;
      int k = 1;
      while (i - k >= 0 && i + k < n && k + radius[i - k] < j) {
        radius[i + k] = radius[i - k];
        ++k;
      }
      i += k;
      j -= k;
    }
  }

  int odd(int idx) const { return (radius[idx * 2] + 1) / 2; }

  int even(int idx) const { return radius[idx * 2 + 1] / 2; }

  bool is_palindrome(int left, int right) const {
    int mid = (left + right - 1) / 2;
    return (((right - left) & 1) ? odd(mid) * 2 - 1 : even(mid) * 2) >= right - left;
  }

private:
  std::vector<int> radius;
};
