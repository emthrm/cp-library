#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

template <int Log10Base = 9, int Base = 1000000000>  // Base = 10^{Log10Base}
struct BigInt {
  int sign; std::vector<int> dat;
  BigInt(long long val = 0) { *this = val; }
  BigInt(const std::string &s) { *this = s; }
  std::vector<long long> convert_base(int new_lg10_base, int new_base) const {
    assert(new_base == static_cast<int>(std::round(std::pow(10, new_lg10_base))));
    int mx_base = std::max(Log10Base, new_lg10_base);
    std::vector<long long> p(mx_base + 1, 1);
    for (int i = 1; i <= mx_base; ++i) p[i] = p[i - 1] * 10;
    std::vector<long long> res;
    long long now_val = 0;
    int now_lg10_base = 0;
    for (int e : dat) {
      now_val += p[now_lg10_base] * e;
      now_lg10_base += Log10Base;
      while (now_lg10_base >= new_lg10_base) {
        res.emplace_back(now_val % new_base);
        now_val /= new_base;
        now_lg10_base -= new_lg10_base;
      }
    }
    res.emplace_back(now_val);
    while (!res.empty() && res.back() == 0) res.pop_back();
    return res;
  }
  int digit_sum() const {
    assert(sign == 1);
    std::string s = to_string();
    int res = 0;
    for (char c : s) res += c - '0';
    return res;
  }
  int length() const {
    if (dat.empty()) return 0;
    int res = Log10Base * (dat.size() - 1), tmp = dat.back();
    while (tmp > 0) { ++res; tmp /= 10; }
    return res;
  }
  BigInt pow(BigInt exponent) const {
    BigInt res = 1, tmp = *this;
    while (exponent > 0) {
      if (exponent.dat[0] & 1) res *= tmp;
      tmp *= tmp;
      exponent /= 2;
    }
    return res;
  }
  long long to_llong() const {
    assert(*this >= std::numeric_limits<long long>::min() && *this <= std::numeric_limits<long long>::max());
    long long res = 0;
    for (int i = static_cast<int>(dat.size()) - 1; i >= 0; --i) (res *= Base) += dat[i];
    return res;
  }
  std::string to_string() const { std::stringstream ss; ss << *this; std::string res; ss >> res; return res; }
  void trim() {
    while (!dat.empty() && dat.back() == 0) dat.pop_back();
    if (dat.empty()) sign = 1;
  }
  BigInt &operator=(long long val) {
    sign = 1;
    if (val < 0) { sign = -1; val = -val;}
    dat.clear();
    for (; val > 0; val /= Base) dat.emplace_back(val % Base);
    return *this;
  }
  BigInt &operator=(const std::string &s) {
    sign = 1;
    dat.clear();
    if (!s.empty()) {
      int tail = 0;
      if (s[tail] == '-') {
        sign = -1;
        ++tail;
      } else if (s[tail] == '+') {
        ++tail;
      }
      for (int i = s.length() - 1; i >= tail; i -= Log10Base) {
        int val = 0;
        for (int j = std::max(tail, i - Log10Base + 1); j <= i; ++j) val = val * 10 + (s[j] - '0');
        dat.emplace_back(val);
      }
    }
    trim();
    return *this;
  }
  BigInt &operator=(const BigInt &x) {
    sign = x.sign;
    dat.resize(x.dat.size());
    std::copy(x.dat.begin(), x.dat.end(), dat.begin());
    return *this;
  }
  BigInt &operator+=(const BigInt &x) {
    if (sign == x.sign) {
      bool carry = false;
      for (int i = 0; i < std::max(dat.size(), x.dat.size()) || carry; ++i) {
        if (i == dat.size()) dat.emplace_back(0);
        dat[i] += (i < x.dat.size() ? x.dat[i] : 0) + carry;
        carry = dat[i] >= Base;
        if (carry) dat[i] -= Base;
      }
    } else {
      *this -= -x;
    }
    return *this;
  }
  BigInt &operator-=(const BigInt &x) {
    if (sign == x.sign) {
      BigInt abs_this = *this, abs_x = x;
      abs_this.sign = 1; abs_x.sign = 1;
      if (abs_this >= abs_x) {
        bool carry = false;
        for (int i = 0; i < dat.size() || carry; ++i) {
          dat[i] -= (i < x.dat.size() ? x.dat[i] : 0) + carry;
          carry = dat[i] < 0;
          if (carry) dat[i] += Base;
        }
        trim();
      } else {
        *this = -(x - *this);
      }
    } else {
      *this += -x;
    }
    return *this;
  }
  BigInt &operator*=(const BigInt &x) {
    constexpr int new_log10_base = 6, new_base = 1000000;
    std::vector<long long> this6 = convert_base(new_log10_base, new_base), x6 = x.convert_base(new_log10_base, new_base);
    std::vector<long long> res = karatsuba(this6, 0, this6.size(), x6, 0, x6.size());
    for (int i = 0; i < res.size(); ++i) {
      long long quo = res[i] / new_base;
      if (quo > 0) {
        if (i + 1 == res.size()) res.emplace_back(0);
        res[i + 1] += quo;
      }
      res[i] %= new_base;
    }
    std::string s = (sign * x.sign == 1 ? "+" : "-");
    for (int i = static_cast<int>(res.size()) - 1; i >= 0; --i) {
      std::string tmp = std::to_string(res[i]);
      for (int i = 0; i < new_log10_base - tmp.size(); ++i) s += '0';
      s += tmp;
    }
    return *this = s;
  }
  BigInt &operator/=(int x) { return *this = divide(x).first; }
  BigInt &operator/=(const BigInt &x) { return *this = divide(x).first; }
  BigInt &operator%=(int x) { return *this = divide(x).second; }
  BigInt &operator%=(const BigInt &x) { return *this = divide(x).second; }
  bool operator==(const BigInt &x) const {
    if (sign != x.sign || dat.size() != x.dat.size()) return false;
    int sz = dat.size();
    for (int i = 0; i < sz; ++i) if (dat[i] != x.dat[i]) return false;
    return true;
  }
  bool operator!=(const BigInt &x) const { return !(*this == x); }
  bool operator<(const BigInt &x) const {
    if (sign != x.sign) return sign < x.sign;
    if (dat.size() != x.dat.size()) return sign * dat.size() < x.sign * x.dat.size();
    for (int i = static_cast<int>(dat.size()) - 1; i >= 0; --i) {
      if (dat[i] != x.dat[i]) return dat[i] * sign < x.dat[i] * x.sign;
    }
    return false;
  }
  bool operator<=(const BigInt &x) const { return !(x < *this); }
  bool operator>(const BigInt &x) const { return x < *this; }
  bool operator>=(const BigInt &x) const { return !(*this < x); }
  BigInt &operator++() { return *this += 1; }
  BigInt operator++(int) { BigInt res = *this; ++*this; return res; }
  BigInt &operator--() { return *this -= 1; }
  BigInt operator--(int) { BigInt res = *this; --*this; return res; }
  BigInt operator+() const { return *this; }
  BigInt operator-() const { BigInt res = *this; res.sign = -res.sign; return res; }
  BigInt operator+(const BigInt &x) const { return BigInt(*this) += x; }
  BigInt operator-(const BigInt &x) const { return BigInt(*this) -= x; }
  BigInt operator*(const BigInt &x) const { return BigInt(*this) *= x; }
  BigInt operator/(int x) const { return BigInt(*this) /= x; }
  BigInt operator/(const BigInt &x) const { return BigInt(*this) /= x; }
  BigInt operator%(int x) const { return BigInt(*this) %= x; }
  BigInt operator%(const BigInt &x) const { return BigInt(*this) %= x; }
  friend std::ostream &operator<<(std::ostream &os, const BigInt &x) {
    if (x.sign == -1) os << '-';
    os << (x.dat.empty() ? 0 : x.dat.back());
    for (int i = static_cast<int>(x.dat.size()) - 2; i >= 0; --i) os << std::setw(Log10Base) << std::setfill('0') << x.dat[i];
    return os;
  }
  friend std::istream &operator>>(std::istream &is, BigInt &x) { std::string s; is >> s; x = s; return is; }
private:
  std::vector<long long> karatsuba(std::vector<long long> &a, int a_l, int a_r, std::vector<long long> &b, int b_l, int b_r) const {
    int a_len = a_r - a_l, b_len = b_r - b_l;
    if (a_len < b_len) return karatsuba(b, b_l, b_r, a, a_l, a_r);
    std::vector<long long> res(a_len + b_len, 0);
    if (b_len <= 32) {
      for (int i = a_l; i < a_r; ++i) for (int j = b_l; j < b_r; ++j) res[(i - a_l) + (j - b_l)] += a[i] * b[j];
    } else {
      int mid = (a_len + 1) / 2, n = std::min(a_len, mid);
      for (int i = a_l; i + mid < a_r; ++i) a[i] += a[i + mid];
      for (int i = b_l; i + mid < b_r; ++i) b[i] += b[i + mid];
      std::vector<long long> tmp = karatsuba(a, a_l, a_l + mid, b, b_l, b_l + n);
      for (int i = 0; i < tmp.size(); ++i) res[mid + i] = tmp[i];
      for (int i = a_l; i + mid < a_r; ++i) a[i] -= a[i + mid];
      for (int i = b_l; i + mid < b_r; ++i) b[i] -= b[i + mid];
      tmp = karatsuba(a, a_l, a_l + mid, b, b_l, b_l + n);
      for (int i = 0; i < tmp.size(); ++i) { res[i] += tmp[i]; res[mid + i] -= tmp[i]; }
      tmp = karatsuba(a, a_l + mid, a_r, b, b_l + n, b_r);
      for (int i = 0; i < tmp.size(); ++i) { res[mid + i] -= tmp[i]; res[(mid << 1) + i] += tmp[i]; }
    }
    while (!res.empty() && res.back() == 0) res.pop_back();
    return res;
  }
  std::pair<BigInt, int> divide(int x) const {
    assert(x != 0);
    BigInt dividend = *this;
    if (x < 0) { dividend.sign = -dividend.sign; x = -x; }
    long long rem = 0;
    for (int i = static_cast<int>(dividend.dat.size()) - 1; i >= 0; --i) {
      long long tmp = rem * Base + dividend.dat[i];
      dividend.dat[i] = static_cast<int>(tmp / x);
      rem = tmp % x;
    }
    dividend.trim();
    return {dividend, static_cast<int>(rem)};
  }
  std::pair<BigInt, BigInt> divide(const BigInt &x) const {
    assert(!x.dat.empty());
    int k = Base / (x.dat.back() + 1);
    BigInt dividend = *this, divisor = x;
    dividend.sign = 1; divisor.sign = 1;
    dividend *= k; divisor *= k;
    BigInt quo, rem = 0;
    quo.dat.resize(dividend.dat.size());
    int sz = divisor.dat.size();
    for (int i = static_cast<int>(dividend.dat.size()) - 1; i >= 0; --i) {
      rem.dat.insert(rem.dat.begin(), dividend.dat[i]);
      quo.dat[i] = static_cast<int>(((sz < rem.dat.size() ? static_cast<long long>(rem.dat[sz]) * Base : 0) + (sz - 1 < rem.dat.size() ? rem.dat[sz - 1] : 0)) / divisor.dat.back());
      rem -= divisor * quo.dat[i];
      while (rem.sign == -1) { rem += divisor; --quo.dat[i];  }
    }
    quo.sign = sign * x.sign; rem.sign = sign;
    quo.trim(); rem.trim();
    return {quo, rem / k};
  }
};
namespace std {
template <int Log10Base, int Base>
BigInt<Log10Base, Base> __gcd(BigInt<Log10Base, Base> a, BigInt<Log10Base, Base> b) { while (!b.dat.empty()) std::swap(a %= b, b); return a; }
template <int Log10Base, int Base>
BigInt<Log10Base, Base> __lcm(const BigInt<Log10Base, Base> &a, const BigInt<Log10Base, Base> &b) { return a / std::__gcd(a, b) * b; }
template <int Log10Base, int Base>
BigInt<Log10Base, Base> abs(const BigInt<Log10Base, Base> &x) { BigInt<Log10Base, Base> res = x; res.sign = 1; return res; }
template <int Log10Base, int Base>
BigInt<Log10Base, Base> max(const BigInt<Log10Base, Base> &a, const BigInt<Log10Base, Base> &b) { return a < b ? b : a; }
template <int Log10Base, int Base>
BigInt<Log10Base, Base> min(const BigInt<Log10Base, Base> &a, const BigInt<Log10Base, Base> &b) { return a < b ? a : b; }
}  // std
