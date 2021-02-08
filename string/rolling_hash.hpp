#pragma once
#include <algorithm>
#include <string>
#include <vector>

template <typename T = std::string>
struct RollingHash {
  T str;

  RollingHash(const T &s, const int base = 10007, const int md = 1000000007) : str(s), base(base), md(md) {
    int n = str.size();
    hash_val.resize(n + 1);
    hash_val[0] = 0;
    power.resize(n + 1);
    power[0] = 1;
    for (int i = 0; i < n; ++i) {
      hash_val[i + 1] = (hash_val[i] * base % md + str[i]) % md;
      power[i + 1] = power[i] * base % md;
    }
  }

  long long get(int left, int right) const {
    long long res = hash_val[right] - hash_val[left] * power[right - left] % md;
    return res < 0 ? res + md : res;
  }

  void add(const T &t) {
    for (auto c : t) {
      hash_val.emplace_back((hash_val.back() * base % md + c) % md);
      power.emplace_back(power.back() * base % md);
    }
  }

  int lcp(int i, int j) const {
    int n = str.size(), lb = 0, ub = n + 1 - std::max(i, j);
    while (ub - lb > 1) {
      int mid = (lb + ub) >> 1;
      (get(i, i + mid) == get(j, j + mid) ? lb : ub) = mid;
    }
    return lb;
  }

  template <typename U>
  int lcp(const RollingHash<U> &t, int i, int j) const {
    int lb = 0, ub = std::min(static_cast<int>(str.size()) - i, static_cast<int>(t.str.size()) - j) + 1;
    while (ub - lb > 1) {
      int mid = (lb + ub) >> 1;
      (get(i, i + mid) == t.get(j, j + mid) ? lb : ub) = mid;
    }
    return lb;
  }

private:
  int base, md;
  std::vector<long long> hash_val, power;
};
