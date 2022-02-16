#pragma once
#include <vector>

struct Manacher {
  template <typename T>
  explicit Manacher(const T& s) {
    T str;
    int n = s.size();
    str.reserve(n * 2 + 1);
    for (int i = 0; i < n; ++i) {
      str.push_back(s[i]);
      str.push_back('$');
    }
    str.pop_back();
    n = str.size();
    radius.resize(n);
    for (int i = 0, j = 1; i < n;) {
      while (i - j >= 0 && i + j < n && str[i - j] == str[i + j]) ++j;
      radius[i] = j;
      int k = 1;
      for (; i - k >= 0 && i + k < n && k + radius[i - k] < j; ++k) {
        radius[i + k] = radius[i - k];
      }
      i += k;
      j -= k;
    }
  }

  int odd(const int idx) const { return (radius[idx * 2] + 1) / 2; }

  int even(const int idx) const { return radius[idx * 2 + 1] / 2; }

  bool is_palindrome(const int left, const int right) const {
    const int mid = (left + right - 1) / 2;
    return ((right - left) & 1 ? odd(mid) * 2 - 1 : even(mid) * 2)
           >= right - left;
  }

 private:
  std::vector<int> radius;
};
