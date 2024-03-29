#ifndef EMTHRM_MATH_BIGINT_HPP_
#define EMTHRM_MATH_BIGINT_HPP_

#include <algorithm>
#include <cassert>
#include <cmath>
#include <compare>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace emthrm {

template <int LOG_B = 9, int B = 1000000000>  // B = 10^{LOG_B}
struct BigInt {
  int sgn;
  std::vector<int> data;

  BigInt(const long long val = 0) { *this = val; }
  BigInt(const std::string& s) { *this = s; }

  std::vector<long long> convert_base(const int next_log_b,
                                      const int next_b) const {
    assert(next_b == std::llround(std::pow(10, next_log_b)));
    const int max_base = std::max(LOG_B, next_log_b);
    std::vector<long long> p(max_base + 1, 1);
    for (int i = 1; i <= max_base; ++i) {
      p[i] = p[i - 1] * 10;
    }
    std::vector<long long> res;
    long long cur_val = 0;
    int cur_log_b = 0;
    for (const int e : data) {
      cur_val += p[cur_log_b] * e;
      cur_log_b += LOG_B;
      for (; cur_log_b >= next_log_b; cur_log_b -= next_log_b) {
        res.emplace_back(cur_val % next_b);
        cur_val /= next_b;
      }
    }
    res.emplace_back(cur_val);
    while (!res.empty() && res.back() == 0) res.pop_back();
    return res;
  }

  int digit_sum() const {
    assert(sgn == 1);
    int res = 0;
    for (char c : to_string()) res += c - '0';
    return res;
  }

  int length() const {
    if (data.empty()) return 0;
    int res = LOG_B * (data.size() - 1);
    for (int tmp = data.back(); tmp > 0; tmp /= 10) {
      ++res;
    }
    return res;
  }

  BigInt pow(BigInt exponent) const {
    BigInt res = 1, tmp = *this;
    for (; exponent > 0; exponent /= 2) {
      if (exponent.data.front() & 1) res *= tmp;
      tmp *= tmp;
    }
    return res;
  }

  long long to_llong() const {
    assert(*this >= std::numeric_limits<long long>::min() &&
           *this <= std::numeric_limits<long long>::max());
    long long res = 0;
    for (int i = std::ssize(data) - 1; i >= 0; --i) {
      res = res * B + data[i];
    }
    return res;
  }

  std::string to_string() const {
    std::stringstream ss;
    ss << *this;
    std::string res;
    ss >> res;
    return res;
  }

  void trim() {
    while (!data.empty() && data.back() == 0) data.pop_back();
    if (data.empty()) sgn = 1;
  }

  BigInt& operator=(long long val) {
    if (val < 0) {
      sgn = -1;
      val = -val;
    } else {
      sgn = 1;
    }
    data.clear();
    for (; val > 0; val /= B) {
      data.emplace_back(val % B);
    }
    return *this;
  }
  BigInt& operator=(const std::string& s) {
    sgn = 1;
    data.clear();
    if (!s.empty()) {
      int tail = 0;
      if (s.front() == '-') {
        sgn = -1;
        tail = 1;
      } else if (s.front() == '+') {
        tail = 1;
      }
      for (int i = s.length() - 1; i >= tail; i -= LOG_B) {
        int val = 0;
        for (int j = std::max(tail, i - LOG_B + 1); j <= i; ++j) {
          val = val * 10 + (s[j] - '0');
        }
        data.emplace_back(val);
      }
    }
    trim();
    return *this;
  }
  BigInt& operator=(const BigInt& x) = default;

  BigInt& operator+=(const BigInt& x) {
    if (sgn != x.sgn) return x.data.empty() ? *this : *this -= -x;
    if (data.size() < x.data.size()) data.resize(x.data.size(), 0);
    bool carry = false;
    for (int i = 0; std::cmp_less(i, x.data.size()) || carry; ++i) {
      if (std::cmp_equal(i, data.size())) data.emplace_back(0);
      data[i] += (std::cmp_less(i, x.data.size()) ? x.data[i] : 0) + carry;
      if (data[i] >= B) {
        carry = true;
        data[i] -= B;
      } else {
        carry = false;
      }
    }
    return *this;
  }

  BigInt& operator-=(const BigInt& x) {
    if (sgn != x.sgn) return *this += -x;
    if ((sgn == 1 ? *this : -*this) < (x.sgn == 1 ? x : -x)) {
      return *this = -(x - *this);
    }
    bool carry = false;
    for (int i = 0; std::cmp_less(i, data.size()) || carry; ++i) {
      data[i] -= (std::cmp_less(i, x.data.size()) ? x.data[i] : 0) + carry;
      if (data[i] < 0) {
        carry = true;
        data[i] += B;
      } else {
        carry = false;
      }
    }
    trim();
    return *this;
  }

  BigInt& operator*=(const BigInt& x) {
    constexpr int next_log_b = 6, next_b = 1000000;
    std::vector<long long> this6 = convert_base(next_log_b, next_b);
    std::vector<long long> x6 = x.convert_base(next_log_b, next_b);
    std::vector<long long> res = karatsuba(&this6, 0, this6.size(),
                                           &x6, 0, x6.size());
    for (int i = 0; std::cmp_less(i, res.size()); ++i) {
      const long long quo = res[i] / next_b;
      if (quo > 0) {
        if (std::cmp_equal(i + 1, res.size())) {
          res.emplace_back(quo);
        } else {
          res[i + 1] += quo;
        }
        res[i] %= next_b;
      }
    }
    std::string s = (sgn * x.sgn == 1 ? "+" : "-");
    for (int i = std::ssize(res) - 1; i >= 0; --i) {
      const std::string tmp = std::to_string(res[i]);
      s += std::string(next_log_b - tmp.length(), '0') + tmp;
    }
    return *this = s;
  }

  BigInt& operator/=(const int x) { return *this = divide(x).first; }
  BigInt& operator/=(const BigInt& x) { return *this = divide(x).first; }
  BigInt& operator%=(const int x) { return *this = divide(x).second; }
  BigInt& operator%=(const BigInt& x) { return *this = divide(x).second; }

  std::strong_ordering operator<=>(const BigInt& x) const {
    if (sgn != x.sgn) return sgn <=> x.sgn;
    if (data.size() != x.data.size()) {
      return sgn * data.size() <=> x.sgn * x.data.size();
    }
    for (int i = std::ssize(data) - 1; i >= 0; --i) {
      if (data[i] != x.data[i]) return data[i] * sgn <=> x.data[i] * x.sgn;
    }
    return std::strong_ordering::equivalent;
  }
  bool operator==(const BigInt& x) const {
    if (sgn != x.sgn || data.size() != x.data.size()) return false;
    const int n = data.size();
    for (int i = 0; i < n; ++i) {
      if (data[i] != x.data[i]) return false;
    }
    return true;
  }

  BigInt& operator++() { return *this += 1; }
  BigInt operator++(int) {
    const BigInt res = *this;
    ++*this;
    return res;
  }
  BigInt& operator--() { return *this -= 1; }
  BigInt operator--(int) {
    const BigInt res = *this;
    --*this;
    return res;
  }

  BigInt operator+() const { return *this; }
  BigInt operator-() const {
    BigInt res = *this;
    if (!res.data.empty()) res.sgn = -res.sgn;
    return res;
  }

  BigInt operator+(const BigInt& x) const { return BigInt(*this) += x; }
  BigInt operator-(const BigInt& x) const { return BigInt(*this) -= x; }
  BigInt operator*(const BigInt& x) const { return BigInt(*this) *= x; }
  BigInt operator/(const int x) const { return BigInt(*this) /= x; }
  BigInt operator/(const BigInt& x) const { return BigInt(*this) /= x; }
  BigInt operator%(const int x) const { return BigInt(*this) %= x; }
  BigInt operator%(const BigInt& x) const { return BigInt(*this) %= x; }

  friend std::ostream& operator<<(std::ostream& os, const BigInt& x) {
    if (x.sgn == -1) os << '-';
    os << (x.data.empty() ? 0 : x.data.back());
    for (int i = std::ssize(x.data) - 2; i >= 0; --i) {
      os << std::setw(LOG_B) << std::setfill('0') << x.data[i];
    }
    return os;
  }
  friend std::istream& operator>>(std::istream& is, BigInt& x) {
    std::string s;
    is >> s;
    x = s;
    return is;
  }

 private:
  std::vector<long long> karatsuba(
      std::vector<long long>* a, const int a_l, const int a_r,
      std::vector<long long>* b, const int b_l, const int b_r) const {
    const int a_len = a_r - a_l, b_len = b_r - b_l;
    if (a_len < b_len) return karatsuba(b, b_l, b_r, a, a_l, a_r);
    std::vector<long long> res(a_len + b_len, 0);
    if (b_len <= 32) {
      for (int i = a_l; i < a_r; ++i) {
        for (int j = b_l; j < b_r; ++j) {
          res[(i - a_l) + (j - b_l)] += (*a)[i] * (*b)[j];
        }
      }
    } else {
      const int mid = (a_len + 1) / 2, n = std::min(b_len, mid);
      for (int i = a_l; i + mid < a_r; ++i) {
        (*a)[i] += (*a)[i + mid];
      }
      for (int i = b_l; i + mid < b_r; ++i) {
        (*b)[i] += (*b)[i + mid];
      }
      std::ranges::copy(karatsuba(a, a_l, a_l + mid, b, b_l, b_l + n),
                        std::next(res.begin(), mid));
      for (int i = a_l; i + mid < a_r; ++i) {
        (*a)[i] -= (*a)[i + mid];
      }
      for (int i = b_l; i + mid < b_r; ++i) {
        (*b)[i] -= (*b)[i + mid];
      }
      std::vector<long long> tmp =
          karatsuba(a, a_l, a_l + mid, b, b_l, b_l + n);
      for (int i = 0; std::cmp_less(i, tmp.size()); ++i) {
        res[i] += tmp[i];
        res[mid + i] -= tmp[i];
      }
      tmp = karatsuba(a, a_l + mid, a_r, b, b_l + n, b_r);
      for (int i = 0; std::cmp_less(i, tmp.size()); ++i) {
        res[mid + i] -= tmp[i];
        res[(mid << 1) + i] += tmp[i];
      }
    }
    while (!res.empty() && res.back() == 0) res.pop_back();
    return res;
  }

  std::pair<BigInt, int> divide(int x) const {
    assert(x != 0);
    BigInt dividend = *this;
    if (x < 0) {
      dividend.sgn = -dividend.sgn;
      x = -x;
    }
    long long rem = 0;
    for (int i = std::ssize(dividend.data) - 1; i >= 0; --i) {
      const long long tmp = rem * B + dividend.data[i];
      dividend.data[i] = tmp / x;
      rem = tmp % x;
    }
    dividend.trim();
    return {dividend, static_cast<int>(rem)};
  }

  std::pair<BigInt, BigInt> divide(const BigInt& x) const {
    assert(!x.data.empty());
    const int k = B / (x.data.back() + 1);
    const BigInt dividend = (sgn == 1 ? *this : -*this) * k;
    const BigInt divisor = (x.sgn == 1 ? x : -x) * k;
    BigInt quo, rem = 0;
    quo.data.resize(dividend.data.size());
    const int n = divisor.data.size();
    for (int i = std::ssize(dividend.data) - 1; i >= 0; --i) {
      rem.data.emplace(rem.data.begin(), dividend.data[i]);
      quo.data[i] =
          ((std::cmp_less(n, rem.data.size()) ?
            static_cast<long long>(rem.data[n]) * B : 0)
           + (std::cmp_less(n - 1, rem.data.size()) ? rem.data[n - 1] : 0))
          / divisor.data.back();
      rem -= divisor * quo.data[i];
      while (rem.sgn == -1) {
        rem += divisor;
        --quo.data[i];
      }
    }
    quo.sgn = sgn * x.sgn;
    quo.trim();
    rem.sgn = sgn;
    rem.trim();
    return {quo, rem / k};
  }
};

}  // namespace emthrm

namespace std {

template <int LOG_B, int B>
emthrm::BigInt<LOG_B, B> gcd(emthrm::BigInt<LOG_B, B> a,
                             emthrm::BigInt<LOG_B, B> b) {
  while (!b.data.empty()) std::swap(a %= b, b);
  return a;
}

template <int LOG_B, int B>
emthrm::BigInt<LOG_B, B> lcm(const emthrm::BigInt<LOG_B, B>& a,
                             const emthrm::BigInt<LOG_B, B>& b) {
  return a / std::__gcd(a, b) * b;
}

template <int LOG_B, int B>
emthrm::BigInt<LOG_B, B> abs(const emthrm::BigInt<LOG_B, B>& x) {
  return x.sgn == 1 ? x : -x;
}

template <int LOG_B, int B>
emthrm::BigInt<LOG_B, B> max(const emthrm::BigInt<LOG_B, B>& a,
                             const emthrm::BigInt<LOG_B, B>& b) {
  return a < b ? b : a;
}

template <int LOG_B, int B>
emthrm::BigInt<LOG_B, B> min(const emthrm::BigInt<LOG_B, B>& a,
                             const emthrm::BigInt<LOG_B, B>& b) {
  return a < b ? a : b;
}

}  // namespace std

#endif  // EMTHRM_MATH_BIGINT_HPP_
