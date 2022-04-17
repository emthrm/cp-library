#pragma once
#include <algorithm>
#include <string>
#include <vector>

template <typename T = std::string>
struct RollingHash {
  T s;

  explicit RollingHash(const T& s, const int base = 10007,
                       const int mod = 1000000007)
      : base(base), mod(mod), hash({0}), power({1}) {
    const int n = s.size();
    this->s.reserve(n);
    hash.reserve(n + 1);
    power.reserve(n + 1);
    add(s);
  }

  long long get(const int left, const int right) const {
    const long long res =
        hash[right] - hash[left] * power[right - left] % mod;
    return res < 0 ? res + mod : res;
  }

  void add(const T& t) {
    for (const auto c : t) {
      s.push_back(c);
      const int hash_nxt = (hash.back() * base % mod + c) % mod;
      hash.emplace_back(hash_nxt);
      const int power_nxt = power.back() * base % mod;
      power.emplace_back(power_nxt);
    }
  }

  int longest_common_prefix(const int i, const int j) const {
    const int n = s.size();
    int lb = 0, ub = n + 1 - std::max(i, j);
    while (ub - lb > 1) {
      const int mid = (lb + ub) >> 1;
      (get(i, i + mid) == get(j, j + mid) ? lb : ub) = mid;
    }
    return lb;
  }

  template <typename U>
  int longest_common_prefix(const RollingHash<U>& t,
                            const int i, const int j) const {
    int lb = 0;
    int ub = std::min(static_cast<int>(s.size()) - i,
                      static_cast<int>(t.str.size()) - j)
             + 1;
    while (ub - lb > 1) {
      const int mid = (lb + ub) >> 1;
      (get(i, i + mid) == t.get(j, j + mid) ? lb : ub) = mid;
    }
    return lb;
  }

 private:
  const int base, mod;
  std::vector<long long> hash, power;
};
