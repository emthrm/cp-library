---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/bigint.hpp
    title: "\u591A\u500D\u9577\u6574\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_8_B
    document_title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6841\u548C)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_8_B
  bundledCode: "#line 1 \"test/math/bigint.09.test.cpp\"\n/*\r\n * @brief \u6570\u5B66\
    /\u591A\u500D\u9577\u6574\u6570 (\u6841\u548C)\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_8_B\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"math/bigint.hpp\"\n#include <algorithm>\r\
    \n#include <cassert>\r\n#include <cmath>\r\n#include <iomanip>\r\n#line 7 \"math/bigint.hpp\"\
    \n#include <limits>\r\n#include <sstream>\r\n#include <string>\r\n#include <utility>\r\
    \n#include <vector>\r\n\r\ntemplate <int Log10Base = 9, int Base = 1000000000>\
    \  // Base = 10^{Log10Base}\r\nstruct BigInt {\r\n  int sign; std::vector<int>\
    \ dat;\r\n  BigInt(long long val = 0) { *this = val; }\r\n  BigInt(const std::string\
    \ &s) { *this = s; }\r\n  std::vector<long long> convert_base(int new_lg10_base,\
    \ int new_base) const {\r\n    assert(new_base == static_cast<int>(std::round(std::pow(10,\
    \ new_lg10_base))));\r\n    int mx_base = std::max(Log10Base, new_lg10_base);\r\
    \n    std::vector<long long> p(mx_base + 1, 1);\r\n    for (int i = 1; i <= mx_base;\
    \ ++i) p[i] = p[i - 1] * 10;\r\n    std::vector<long long> res;\r\n    long long\
    \ now_val = 0;\r\n    int now_lg10_base = 0;\r\n    for (int e : dat) {\r\n  \
    \    now_val += p[now_lg10_base] * e;\r\n      now_lg10_base += Log10Base;\r\n\
    \      while (now_lg10_base >= new_lg10_base) {\r\n        res.emplace_back(now_val\
    \ % new_base);\r\n        now_val /= new_base;\r\n        now_lg10_base -= new_lg10_base;\r\
    \n      }\r\n    }\r\n    res.emplace_back(now_val);\r\n    while (!res.empty()\
    \ && res.back() == 0) res.pop_back();\r\n    return res;\r\n  }\r\n  int digit_sum()\
    \ const {\r\n    assert(sign == 1);\r\n    std::string s = to_string();\r\n  \
    \  int res = 0;\r\n    for (char c : s) res += c - '0';\r\n    return res;\r\n\
    \  }\r\n  int length() const {\r\n    if (dat.empty()) return 0;\r\n    int res\
    \ = Log10Base * (dat.size() - 1), tmp = dat.back();\r\n    while (tmp > 0) { ++res;\
    \ tmp /= 10; }\r\n    return res;\r\n  }\r\n  BigInt pow(BigInt exponent) const\
    \ {\r\n    BigInt res = 1, tmp = *this;\r\n    while (exponent > 0) {\r\n    \
    \  if (exponent.dat[0] & 1) res *= tmp;\r\n      tmp *= tmp;\r\n      exponent\
    \ /= 2;\r\n    }\r\n    return res;\r\n  }\r\n  long long to_llong() const {\r\
    \n    assert(*this >= std::numeric_limits<long long>::min() && *this <= std::numeric_limits<long\
    \ long>::max());\r\n    long long res = 0;\r\n    for (int i = static_cast<int>(dat.size())\
    \ - 1; i >= 0; --i) (res *= Base) += dat[i];\r\n    return res;\r\n  }\r\n  std::string\
    \ to_string() const { std::stringstream ss; ss << *this; std::string res; ss >>\
    \ res; return res; }\r\n  void trim() {\r\n    while (!dat.empty() && dat.back()\
    \ == 0) dat.pop_back();\r\n    if (dat.empty()) sign = 1;\r\n  }\r\n  BigInt &operator=(long\
    \ long val) {\r\n    sign = 1;\r\n    if (val < 0) { sign = -1; val = -val;}\r\
    \n    dat.clear();\r\n    for (; val > 0; val /= Base) dat.emplace_back(val %\
    \ Base);\r\n    return *this;\r\n  }\r\n  BigInt &operator=(const std::string\
    \ &s) {\r\n    sign = 1;\r\n    dat.clear();\r\n    if (!s.empty()) {\r\n    \
    \  int tail = 0;\r\n      if (s[tail] == '-') {\r\n        sign = -1;\r\n    \
    \    ++tail;\r\n      } else if (s[tail] == '+') {\r\n        ++tail;\r\n    \
    \  }\r\n      for (int i = s.length() - 1; i >= tail; i -= Log10Base) {\r\n  \
    \      int val = 0;\r\n        for (int j = std::max(tail, i - Log10Base + 1);\
    \ j <= i; ++j) val = val * 10 + (s[j] - '0');\r\n        dat.emplace_back(val);\r\
    \n      }\r\n    }\r\n    trim();\r\n    return *this;\r\n  }\r\n  BigInt &operator=(const\
    \ BigInt &x) {\r\n    sign = x.sign;\r\n    dat.resize(x.dat.size());\r\n    std::copy(x.dat.begin(),\
    \ x.dat.end(), dat.begin());\r\n    return *this;\r\n  }\r\n  BigInt &operator+=(const\
    \ BigInt &x) {\r\n    if (sign == x.sign) {\r\n      bool carry = false;\r\n \
    \     for (int i = 0; i < std::max(dat.size(), x.dat.size()) || carry; ++i) {\r\
    \n        if (i == dat.size()) dat.emplace_back(0);\r\n        dat[i] += (i <\
    \ x.dat.size() ? x.dat[i] : 0) + carry;\r\n        carry = dat[i] >= Base;\r\n\
    \        if (carry) dat[i] -= Base;\r\n      }\r\n    } else {\r\n      *this\
    \ -= -x;\r\n    }\r\n    return *this;\r\n  }\r\n  BigInt &operator-=(const BigInt\
    \ &x) {\r\n    if (sign == x.sign) {\r\n      BigInt abs_this = *this, abs_x =\
    \ x;\r\n      abs_this.sign = 1; abs_x.sign = 1;\r\n      if (abs_this >= abs_x)\
    \ {\r\n        bool carry = false;\r\n        for (int i = 0; i < dat.size() ||\
    \ carry; ++i) {\r\n          dat[i] -= (i < x.dat.size() ? x.dat[i] : 0) + carry;\r\
    \n          carry = dat[i] < 0;\r\n          if (carry) dat[i] += Base;\r\n  \
    \      }\r\n        trim();\r\n      } else {\r\n        *this = -(x - *this);\r\
    \n      }\r\n    } else {\r\n      *this += -x;\r\n    }\r\n    return *this;\r\
    \n  }\r\n  BigInt &operator*=(const BigInt &x) {\r\n    constexpr int new_log10_base\
    \ = 6, new_base = 1000000;\r\n    std::vector<long long> this6 = convert_base(new_log10_base,\
    \ new_base), x6 = x.convert_base(new_log10_base, new_base);\r\n    std::vector<long\
    \ long> res = karatsuba(this6, 0, this6.size(), x6, 0, x6.size());\r\n    for\
    \ (int i = 0; i < res.size(); ++i) {\r\n      long long quo = res[i] / new_base;\r\
    \n      if (quo > 0) {\r\n        if (i + 1 == res.size()) res.emplace_back(0);\r\
    \n        res[i + 1] += quo;\r\n      }\r\n      res[i] %= new_base;\r\n    }\r\
    \n    std::string s = (sign * x.sign == 1 ? \"+\" : \"-\");\r\n    for (int i\
    \ = static_cast<int>(res.size()) - 1; i >= 0; --i) {\r\n      std::string tmp\
    \ = std::to_string(res[i]);\r\n      for (int i = 0; i < new_log10_base - tmp.size();\
    \ ++i) s += '0';\r\n      s += tmp;\r\n    }\r\n    return *this = s;\r\n  }\r\
    \n  BigInt &operator/=(int x) { return *this = divide(x).first; }\r\n  BigInt\
    \ &operator/=(const BigInt &x) { return *this = divide(x).first; }\r\n  BigInt\
    \ &operator%=(int x) { return *this = divide(x).second; }\r\n  BigInt &operator%=(const\
    \ BigInt &x) { return *this = divide(x).second; }\r\n  bool operator==(const BigInt\
    \ &x) const {\r\n    if (sign != x.sign || dat.size() != x.dat.size()) return\
    \ false;\r\n    int sz = dat.size();\r\n    for (int i = 0; i < sz; ++i) if (dat[i]\
    \ != x.dat[i]) return false;\r\n    return true;\r\n  }\r\n  bool operator!=(const\
    \ BigInt &x) const { return !(*this == x); }\r\n  bool operator<(const BigInt\
    \ &x) const {\r\n    if (sign != x.sign) return sign < x.sign;\r\n    if (dat.size()\
    \ != x.dat.size()) return sign * dat.size() < x.sign * x.dat.size();\r\n    for\
    \ (int i = static_cast<int>(dat.size()) - 1; i >= 0; --i) {\r\n      if (dat[i]\
    \ != x.dat[i]) return dat[i] * sign < x.dat[i] * x.sign;\r\n    }\r\n    return\
    \ false;\r\n  }\r\n  bool operator<=(const BigInt &x) const { return !(x < *this);\
    \ }\r\n  bool operator>(const BigInt &x) const { return x < *this; }\r\n  bool\
    \ operator>=(const BigInt &x) const { return !(*this < x); }\r\n  BigInt &operator++()\
    \ { return *this += 1; }\r\n  BigInt operator++(int) { BigInt res = *this; ++*this;\
    \ return res; }\r\n  BigInt &operator--() { return *this -= 1; }\r\n  BigInt operator--(int)\
    \ { BigInt res = *this; --*this; return res; }\r\n  BigInt operator+() const {\
    \ return *this; }\r\n  BigInt operator-() const { BigInt res = *this; res.sign\
    \ = -res.sign; return res; }\r\n  BigInt operator+(const BigInt &x) const { return\
    \ BigInt(*this) += x; }\r\n  BigInt operator-(const BigInt &x) const { return\
    \ BigInt(*this) -= x; }\r\n  BigInt operator*(const BigInt &x) const { return\
    \ BigInt(*this) *= x; }\r\n  BigInt operator/(int x) const { return BigInt(*this)\
    \ /= x; }\r\n  BigInt operator/(const BigInt &x) const { return BigInt(*this)\
    \ /= x; }\r\n  BigInt operator%(int x) const { return BigInt(*this) %= x; }\r\n\
    \  BigInt operator%(const BigInt &x) const { return BigInt(*this) %= x; }\r\n\
    \  friend std::ostream &operator<<(std::ostream &os, const BigInt &x) {\r\n  \
    \  if (x.sign == -1) os << '-';\r\n    os << (x.dat.empty() ? 0 : x.dat.back());\r\
    \n    for (int i = static_cast<int>(x.dat.size()) - 2; i >= 0; --i) os << std::setw(Log10Base)\
    \ << std::setfill('0') << x.dat[i];\r\n    return os;\r\n  }\r\n  friend std::istream\
    \ &operator>>(std::istream &is, BigInt &x) { std::string s; is >> s; x = s; return\
    \ is; }\r\nprivate:\r\n  std::vector<long long> karatsuba(std::vector<long long>\
    \ &a, int a_l, int a_r, std::vector<long long> &b, int b_l, int b_r) const {\r\
    \n    int a_len = a_r - a_l, b_len = b_r - b_l;\r\n    if (a_len < b_len) return\
    \ karatsuba(b, b_l, b_r, a, a_l, a_r);\r\n    std::vector<long long> res(a_len\
    \ + b_len, 0);\r\n    if (b_len <= 32) {\r\n      for (int i = a_l; i < a_r; ++i)\
    \ for (int j = b_l; j < b_r; ++j) res[(i - a_l) + (j - b_l)] += a[i] * b[j];\r\
    \n    } else {\r\n      int mid = (a_len + 1) / 2, n = std::min(a_len, mid);\r\
    \n      for (int i = a_l; i + mid < a_r; ++i) a[i] += a[i + mid];\r\n      for\
    \ (int i = b_l; i + mid < b_r; ++i) b[i] += b[i + mid];\r\n      std::vector<long\
    \ long> tmp = karatsuba(a, a_l, a_l + mid, b, b_l, b_l + n);\r\n      for (int\
    \ i = 0; i < tmp.size(); ++i) res[mid + i] = tmp[i];\r\n      for (int i = a_l;\
    \ i + mid < a_r; ++i) a[i] -= a[i + mid];\r\n      for (int i = b_l; i + mid <\
    \ b_r; ++i) b[i] -= b[i + mid];\r\n      tmp = karatsuba(a, a_l, a_l + mid, b,\
    \ b_l, b_l + n);\r\n      for (int i = 0; i < tmp.size(); ++i) { res[i] += tmp[i];\
    \ res[mid + i] -= tmp[i]; }\r\n      tmp = karatsuba(a, a_l + mid, a_r, b, b_l\
    \ + n, b_r);\r\n      for (int i = 0; i < tmp.size(); ++i) { res[mid + i] -= tmp[i];\
    \ res[(mid << 1) + i] += tmp[i]; }\r\n    }\r\n    while (!res.empty() && res.back()\
    \ == 0) res.pop_back();\r\n    return res;\r\n  }\r\n  std::pair<BigInt, int>\
    \ divide(int x) const {\r\n    assert(x != 0);\r\n    BigInt dividend = *this;\r\
    \n    if (x < 0) { dividend.sign = -dividend.sign; x = -x; }\r\n    long long\
    \ rem = 0;\r\n    for (int i = static_cast<int>(dividend.dat.size()) - 1; i >=\
    \ 0; --i) {\r\n      long long tmp = rem * Base + dividend.dat[i];\r\n      dividend.dat[i]\
    \ = static_cast<int>(tmp / x);\r\n      rem = tmp % x;\r\n    }\r\n    dividend.trim();\r\
    \n    return {dividend, static_cast<int>(rem)};\r\n  }\r\n  std::pair<BigInt,\
    \ BigInt> divide(const BigInt &x) const {\r\n    assert(!x.dat.empty());\r\n \
    \   int k = Base / (x.dat.back() + 1);\r\n    BigInt dividend = *this, divisor\
    \ = x;\r\n    dividend.sign = 1; divisor.sign = 1;\r\n    dividend *= k; divisor\
    \ *= k;\r\n    BigInt quo, rem = 0;\r\n    quo.dat.resize(dividend.dat.size());\r\
    \n    int sz = divisor.dat.size();\r\n    for (int i = static_cast<int>(dividend.dat.size())\
    \ - 1; i >= 0; --i) {\r\n      rem.dat.insert(rem.dat.begin(), dividend.dat[i]);\r\
    \n      quo.dat[i] = static_cast<int>(((sz < rem.dat.size() ? static_cast<long\
    \ long>(rem.dat[sz]) * Base : 0) + (sz - 1 < rem.dat.size() ? rem.dat[sz - 1]\
    \ : 0)) / divisor.dat.back());\r\n      rem -= divisor * quo.dat[i];\r\n     \
    \ while (rem.sign == -1) { rem += divisor; --quo.dat[i];  }\r\n    }\r\n    quo.sign\
    \ = sign * x.sign; rem.sign = sign;\r\n    quo.trim(); rem.trim();\r\n    return\
    \ {quo, rem / k};\r\n  }\r\n};\r\nnamespace std {\r\ntemplate <int Log10Base,\
    \ int Base>\r\nBigInt<Log10Base, Base> __gcd(BigInt<Log10Base, Base> a, BigInt<Log10Base,\
    \ Base> b) { while (!b.dat.empty()) std::swap(a %= b, b); return a; }\r\ntemplate\
    \ <int Log10Base, int Base>\r\nBigInt<Log10Base, Base> __lcm(const BigInt<Log10Base,\
    \ Base> &a, const BigInt<Log10Base, Base> &b) { return a / std::__gcd(a, b) *\
    \ b; }\r\ntemplate <int Log10Base, int Base>\r\nBigInt<Log10Base, Base> abs(const\
    \ BigInt<Log10Base, Base> &x) { BigInt<Log10Base, Base> res = x; res.sign = 1;\
    \ return res; }\r\ntemplate <int Log10Base, int Base>\r\nBigInt<Log10Base, Base>\
    \ max(const BigInt<Log10Base, Base> &a, const BigInt<Log10Base, Base> &b) { return\
    \ a < b ? b : a; }\r\ntemplate <int Log10Base, int Base>\r\nBigInt<Log10Base,\
    \ Base> min(const BigInt<Log10Base, Base> &a, const BigInt<Log10Base, Base> &b)\
    \ { return a < b ? a : b; }\r\n}  // std\r\n#line 8 \"test/math/bigint.09.test.cpp\"\
    \n\r\nint main() {\r\n  while (true) {\r\n    BigInt<> x;\r\n    std::cin >> x;\r\
    \n    if (x == 0) break;\r\n    std::cout << x.digit_sum() << '\\n';\r\n  }\r\n\
    \  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6841\u548C\
    )\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_8_B\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../math/bigint.hpp\"\r\n\r\nint main()\
    \ {\r\n  while (true) {\r\n    BigInt<> x;\r\n    std::cin >> x;\r\n    if (x\
    \ == 0) break;\r\n    std::cout << x.digit_sum() << '\\n';\r\n  }\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn:
  - math/bigint.hpp
  isVerificationFile: true
  path: test/math/bigint.09.test.cpp
  requiredBy: []
  timestamp: '2021-03-04 17:06:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/bigint.09.test.cpp
layout: document
redirect_from:
- /verify/test/math/bigint.09.test.cpp
- /verify/test/math/bigint.09.test.cpp.html
title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6841\u548C)"
---
