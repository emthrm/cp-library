---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.01.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570"
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.02.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u52A0\u7B97)"
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.03.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6E1B\u7B97)"
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.04.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u4E57\u7B97)"
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.05.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u9664\u7B97)"
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.06.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u5270\u4F59\u6F14\u7B97)"
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.07.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u5927\u5C0F\u6BD4\u8F03)"
  - icon: ':x:'
    path: test/math/bigint.08.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u51AA\u6F14\u7B97)"
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.09.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6841\u548C)"
  - icon: ':x:'
    path: test/math/bigint.10.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6841\u6570)"
  - icon: ':heavy_check_mark:'
    path: test/math/twelvefold_way/pascal.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\
      \u89D2\u5F62"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/bigint.hpp\"\n#include <algorithm>\r\n#include <cassert>\r\
    \n#include <cmath>\r\n#include <iomanip>\r\n#include <iostream>\r\n#include <iterator>\r\
    \n#include <limits>\r\n#include <sstream>\r\n#include <string>\r\n#include <utility>\r\
    \n#include <vector>\r\n\r\ntemplate <int LogB = 9, int B = 1000000000>  // B =\
    \ 10^{LogB}\r\nstruct BigInt {\r\n  int sgn;\r\n  std::vector<int> data;\r\n \
    \ BigInt(const long long val = 0) { *this = val; }\r\n  BigInt(const std::string&\
    \ s) { *this = s; }\r\n  std::vector<long long> convert_base(const int next_log_b,\r\
    \n                                      const int next_b) const {\r\n    assert(next_b\
    \ == static_cast<int>(std::round(std::pow(10, next_log_b))));\r\n    const int\
    \ max_base = std::max(LogB, next_log_b);\r\n    std::vector<long long> p(max_base\
    \ + 1, 1);\r\n    for (int i = 1; i <= max_base; ++i) {\r\n      p[i] = p[i -\
    \ 1] * 10;\r\n    }\r\n    std::vector<long long> res;\r\n    long long cur_val\
    \ = 0;\r\n    int cur_log_b = 0;\r\n    for (const int e : data) {\r\n      cur_val\
    \ += p[cur_log_b] * e;\r\n      cur_log_b += LogB;\r\n      for (; cur_log_b >=\
    \ next_log_b; cur_log_b -= next_log_b) {\r\n        res.emplace_back(cur_val %\
    \ next_b);\r\n        cur_val /= next_b;\r\n      }\r\n    }\r\n    res.emplace_back(cur_val);\r\
    \n    while (!res.empty() && res.back() == 0) res.pop_back();\r\n    return res;\r\
    \n  }\r\n  int digit_sum() const {\r\n    assert(sgn == 1);\r\n    int res = 0;\r\
    \n    for (char c : to_string()) res += c - '0';\r\n    return res;\r\n  }\r\n\
    \  int length() const {\r\n    if (data.empty()) return 0;\r\n    int res = LogB\
    \ * (data.size() - 1);\r\n    for (int tmp = data.back(); tmp > 0; tmp /= 10)\
    \ {\r\n      ++res;\r\n    }\r\n    return res;\r\n  }\r\n  BigInt pow(BigInt\
    \ exponent) const {\r\n    BigInt res = 1, tmp = *this;\r\n    for (; exponent\
    \ > 0; exponent /= 2) {\r\n      if (exponent.data.front() & 1) res *= tmp;\r\n\
    \      tmp *= tmp;\r\n    }\r\n    return res;\r\n  }\r\n  long long to_llong()\
    \ const {\r\n    assert(*this >= std::numeric_limits<long long>::min() &&\r\n\
    \           *this <= std::numeric_limits<long long>::max());\r\n    long long\
    \ res = 0;\r\n    for (int i = static_cast<int>(data.size()) - 1; i >= 0; --i)\
    \ {\r\n      res = res * B + data[i];\r\n    }\r\n    return res;\r\n  }\r\n \
    \ std::string to_string() const {\r\n    std::stringstream ss;\r\n    ss << *this;\r\
    \n    std::string res;\r\n    ss >> res;\r\n    return res;\r\n  }\r\n  void trim()\
    \ {\r\n    while (!data.empty() && data.back() == 0) data.pop_back();\r\n    if\
    \ (data.empty()) sgn = 1;\r\n  }\r\n  BigInt& operator=(long long val) {\r\n \
    \   if (val < 0) {\r\n      sgn = -1;\r\n      val = -val;\r\n    } else {\r\n\
    \      sgn = 1;\r\n    }\r\n    data.clear();\r\n    for (; val > 0; val /= B)\
    \ {\r\n      data.emplace_back(val % B);\r\n    }\r\n    return *this;\r\n  }\r\
    \n  BigInt& operator=(const std::string& s) {\r\n    sgn = 1;\r\n    data.clear();\r\
    \n    if (!s.empty()) {\r\n      int tail = 0;\r\n      if (s.front() == '-')\
    \ {\r\n        sgn = -1;\r\n        tail = 1;\r\n      } else if (s.front() ==\
    \ '+') {\r\n        tail = 1;\r\n      }\r\n      for (int i = s.length() - 1;\
    \ i >= tail; i -= LogB) {\r\n        int val = 0;\r\n        for (int j = std::max(tail,\
    \ i - LogB + 1); j <= i; ++j) {\r\n          val = val * 10 + (s[j] - '0');\r\n\
    \        }\r\n        data.emplace_back(val);\r\n      }\r\n    }\r\n    trim();\r\
    \n    return *this;\r\n  }\r\n  BigInt& operator=(const BigInt& x) = default;\r\
    \n  BigInt& operator+=(const BigInt& x) {\r\n    if (sgn != x.sgn) return *this\
    \ -= -x;\r\n    if (data.size() < x.data.size()) data.resize(x.data.size(), 0);\r\
    \n    bool carry = false;\r\n    for (int i = 0; i < x.data.size() || carry; ++i)\
    \ {\r\n      if (i == data.size()) data.emplace_back(0);\r\n      data[i] += (i\
    \ < x.data.size() ? x.data[i] : 0) + carry;\r\n      if (data[i] >= B) {\r\n \
    \       carry = true;\r\n        data[i] -= B;\r\n      } else {\r\n        carry\
    \ = false;\r\n      }\r\n    }\r\n    return *this;\r\n  }\r\n  BigInt& operator-=(const\
    \ BigInt& x) {\r\n    if (sgn != x.sgn) return *this += -x;\r\n    if ((sgn ==\
    \ 1 ? *this : -*this) < (x.sgn == 1 ? x : -x)) {\r\n      return *this = -(x -\
    \ *this);\r\n    }\r\n    bool carry = false;\r\n    for (int i = 0; i < data.size()\
    \ || carry; ++i) {\r\n      data[i] -= (i < x.data.size() ? x.data[i] : 0) + carry;\r\
    \n      if (data[i] < 0) {\r\n        carry = true;\r\n        data[i] += B;\r\
    \n      } else {\r\n        carry = false;\r\n      }\r\n    }\r\n    trim();\r\
    \n    return *this;\r\n  }\r\n  BigInt& operator*=(const BigInt& x) {\r\n    constexpr\
    \ int next_log_b = 6, next_b = 1000000;\r\n    std::vector<long long> this6 =\
    \ convert_base(next_log_b, next_b);\r\n    std::vector<long long> x6 = x.convert_base(next_log_b,\
    \ next_b);\r\n    std::vector<long long> res = karatsuba(&this6, 0, this6.size(),\r\
    \n                                           &x6, 0, x6.size());\r\n    for (int\
    \ i = 0; i < res.size(); ++i) {\r\n      const long long quo = res[i] / next_b;\r\
    \n      if (quo > 0) {\r\n        if (i + 1 == res.size()) {\r\n          res.emplace_back(quo);\r\
    \n        } else {\r\n          res[i + 1] += quo;\r\n        }\r\n        res[i]\
    \ %= next_b;\r\n      }\r\n    }\r\n    std::string s = (sgn * x.sgn == 1 ? \"\
    +\" : \"-\");\r\n    for (int i = static_cast<int>(res.size()) - 1; i >= 0; --i)\
    \ {\r\n      const std::string tmp = std::to_string(res[i]);\r\n      s += std::string(next_log_b\
    \ - tmp.length(), '0') + tmp;\r\n    }\r\n    return *this = s;\r\n  }\r\n  BigInt&\
    \ operator/=(int x) { return *this = divide(x).first; }\r\n  BigInt& operator/=(const\
    \ BigInt& x) { return *this = divide(x).first; }\r\n  BigInt& operator%=(int x)\
    \ { return *this = divide(x).second; }\r\n  BigInt& operator%=(const BigInt& x)\
    \ { return *this = divide(x).second; }\r\n  bool operator==(const BigInt& x) const\
    \ {\r\n    if (sgn != x.sgn || data.size() != x.data.size()) return false;\r\n\
    \    const int n = data.size();\r\n    for (int i = 0; i < n; ++i) {\r\n     \
    \ if (data[i] != x.data[i]) return false;\r\n    }\r\n    return true;\r\n  }\r\
    \n  bool operator!=(const BigInt& x) const { return !(*this == x); }\r\n  bool\
    \ operator<(const BigInt& x) const {\r\n    if (sgn != x.sgn) return sgn < x.sgn;\r\
    \n    if (data.size() != x.data.size()) {\r\n      return sgn * data.size() <\
    \ x.sgn * x.data.size();\r\n    }\r\n    for (int i = static_cast<int>(data.size())\
    \ - 1; i >= 0; --i) {\r\n      if (data[i] != x.data[i]) return data[i] * sgn\
    \ < x.data[i] * x.sgn;\r\n    }\r\n    return false;\r\n  }\r\n  bool operator<=(const\
    \ BigInt& x) const { return !(x < *this); }\r\n  bool operator>(const BigInt&\
    \ x) const { return x < *this; }\r\n  bool operator>=(const BigInt& x) const {\
    \ return !(*this < x); }\r\n  BigInt& operator++() { return *this += 1; }\r\n\
    \  BigInt operator++(int) {\r\n    const BigInt res = *this;\r\n    ++*this;\r\
    \n    return res;\r\n  }\r\n  BigInt& operator--() { return *this -= 1; }\r\n\
    \  BigInt operator--(int) {\r\n    const BigInt res = *this;\r\n    --*this;\r\
    \n    return res;\r\n  }\r\n  BigInt operator+() const { return *this; }\r\n \
    \ BigInt operator-() const {\r\n    BigInt res = *this;\r\n    res.sgn = -res.sgn;\r\
    \n    return res;\r\n  }\r\n  BigInt operator+(const BigInt& x) const { return\
    \ BigInt(*this) += x; }\r\n  BigInt operator-(const BigInt& x) const { return\
    \ BigInt(*this) -= x; }\r\n  BigInt operator*(const BigInt& x) const { return\
    \ BigInt(*this) *= x; }\r\n  BigInt operator/(int x) const { return BigInt(*this)\
    \ /= x; }\r\n  BigInt operator/(const BigInt& x) const { return BigInt(*this)\
    \ /= x; }\r\n  BigInt operator%(int x) const { return BigInt(*this) %= x; }\r\n\
    \  BigInt operator%(const BigInt& x) const { return BigInt(*this) %= x; }\r\n\
    \  friend std::ostream& operator<<(std::ostream& os, const BigInt& x) {\r\n  \
    \  if (x.sgn == -1) os << '-';\r\n    os << (x.data.empty() ? 0 : x.data.back());\r\
    \n    for (int i = static_cast<int>(x.data.size()) - 2; i >= 0; --i) {\r\n   \
    \   os << std::setw(LogB) << std::setfill('0') << x.data[i];\r\n    }\r\n    return\
    \ os;\r\n  }\r\n  friend std::istream& operator>>(std::istream& is, BigInt& x)\
    \ {\r\n    std::string s;\r\n    is >> s;\r\n    x = s;\r\n    return is;\r\n\
    \  }\r\n private:\r\n  std::vector<long long> karatsuba(\r\n      std::vector<long\
    \ long>* a, const int a_l, const int a_r,\r\n      std::vector<long long>* b,\
    \ const int b_l, const int b_r) const {\r\n    const int a_len = a_r - a_l, b_len\
    \ = b_r - b_l;\r\n    if (a_len < b_len) return karatsuba(b, b_l, b_r, a, a_l,\
    \ a_r);\r\n    std::vector<long long> res(a_len + b_len, 0);\r\n    if (b_len\
    \ <= 32) {\r\n      for (int i = a_l; i < a_r; ++i) {\r\n        for (int j =\
    \ b_l; j < b_r; ++j) {\r\n          res[(i - a_l) + (j - b_l)] += (*a)[i] * (*b)[j];\r\
    \n        }\r\n      }\r\n    } else {\r\n      const int mid = (a_len + 1) /\
    \ 2, n = std::min(a_len, mid);\r\n      for (int i = a_l; i + mid < a_r; ++i)\
    \ {\r\n        (*a)[i] += (*a)[i + mid];\r\n      }\r\n      for (int i = b_l;\
    \ i + mid < b_r; ++i) {\r\n        (*b)[i] += (*b)[i + mid];\r\n      }\r\n  \
    \    std::vector<long long> tmp =\r\n          karatsuba(a, a_l, a_l + mid, b,\
    \ b_l, b_l + n);\r\n      std::copy(tmp.begin(), tmp.end(), std::next(res.begin(),\
    \ mid));\r\n      for (int i = a_l; i + mid < a_r; ++i) {\r\n        (*a)[i] -=\
    \ (*a)[i + mid];\r\n      }\r\n      for (int i = b_l; i + mid < b_r; ++i) {\r\
    \n        (*b)[i] -= (*b)[i + mid];\r\n      }\r\n      tmp = karatsuba(a, a_l,\
    \ a_l + mid, b, b_l, b_l + n);\r\n      for (int i = 0; i < tmp.size(); ++i) {\r\
    \n        res[i] += tmp[i];\r\n        res[mid + i] -= tmp[i];\r\n      }\r\n\
    \      tmp = karatsuba(a, a_l + mid, a_r, b, b_l + n, b_r);\r\n      for (int\
    \ i = 0; i < tmp.size(); ++i) {\r\n        res[mid + i] -= tmp[i];\r\n       \
    \ res[(mid << 1) + i] += tmp[i];\r\n      }\r\n    }\r\n    while (!res.empty()\
    \ && res.back() == 0) res.pop_back();\r\n    return res;\r\n  }\r\n  std::pair<BigInt,\
    \ int> divide(int x) const {\r\n    assert(x != 0);\r\n    BigInt dividend = *this;\r\
    \n    if (x < 0) {\r\n      dividend.sgn = -dividend.sgn;\r\n      x = -x;\r\n\
    \    }\r\n    long long rem = 0;\r\n    for (int i = static_cast<int>(dividend.data.size())\
    \ - 1; i >= 0; --i) {\r\n      const long long tmp = rem * B + dividend.data[i];\r\
    \n      dividend.data[i] = tmp / x;\r\n      rem = tmp % x;\r\n    }\r\n    dividend.trim();\r\
    \n    return {dividend, static_cast<int>(rem)};\r\n  }\r\n  std::pair<BigInt,\
    \ BigInt> divide(const BigInt& x) const {\r\n    assert(!x.data.empty());\r\n\
    \    const int k = B / (x.data.back() + 1);\r\n    const BigInt dividend = (sgn\
    \ == 1 ? *this : -*this) * k;\r\n    const BigInt divisor = (x.sgn == 1 ? x :\
    \ -x) * k;\r\n    BigInt quo, rem = 0;\r\n    quo.data.resize(dividend.data.size());\r\
    \n    const int n = divisor.data.size();\r\n    for (int i = static_cast<int>(dividend.data.size())\
    \ - 1; i >= 0; --i) {\r\n      rem.data.emplace(rem.data.begin(), dividend.data[i]);\r\
    \n      quo.data[i] =\r\n          ((n < rem.data.size() ? static_cast<long long>(rem.data[n])\
    \ * B : 0)\r\n           + (n - 1 < rem.data.size() ? rem.data[n - 1] : 0))\r\n\
    \          / divisor.data.back();\r\n      rem -= divisor * quo.data[i];\r\n \
    \     while (rem.sgn == -1) {\r\n        rem += divisor;\r\n        --quo.data[i];\r\
    \n      }\r\n    }\r\n    quo.sgn = sgn * x.sgn;\r\n    quo.trim();\r\n    rem.sgn\
    \ = sgn;\r\n    rem.trim();\r\n    return {quo, rem / k};\r\n  }\r\n};\r\nnamespace\
    \ std {\r\ntemplate <int LogB, int B>\r\nBigInt<LogB, B> __gcd(BigInt<LogB, B>\
    \ a, BigInt<LogB, B> b) {\r\n  while (!b.data.empty()) std::swap(a %= b, b);\r\
    \n  return a;\r\n}\r\ntemplate <int LogB, int B>\r\nBigInt<LogB, B> __lcm(const\
    \ BigInt<LogB, B>& a, const BigInt<LogB, B>& b) {\r\n  return a / std::__gcd(a,\
    \ b) * b;\r\n}\r\ntemplate <int LogB, int B>\r\nBigInt<LogB, B> abs(const BigInt<LogB,\
    \ B>& x) { return x.sgn == 1 ? x : -x; }\r\ntemplate <int LogB, int B>\r\nBigInt<LogB,\
    \ B> max(const BigInt<LogB, B>& a, const BigInt<LogB, B>& b) {\r\n  return a <\
    \ b ? b : a;\r\n}\r\ntemplate <int LogB, int B>\r\nBigInt<LogB, B> min(const BigInt<LogB,\
    \ B>& a, const BigInt<LogB, B>& b) {\r\n  return a < b ? a : b;\r\n}\r\n}  //\
    \ namespace std\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cassert>\r\n#include <cmath>\r\
    \n#include <iomanip>\r\n#include <iostream>\r\n#include <iterator>\r\n#include\
    \ <limits>\r\n#include <sstream>\r\n#include <string>\r\n#include <utility>\r\n\
    #include <vector>\r\n\r\ntemplate <int LogB = 9, int B = 1000000000>  // B = 10^{LogB}\r\
    \nstruct BigInt {\r\n  int sgn;\r\n  std::vector<int> data;\r\n  BigInt(const\
    \ long long val = 0) { *this = val; }\r\n  BigInt(const std::string& s) { *this\
    \ = s; }\r\n  std::vector<long long> convert_base(const int next_log_b,\r\n  \
    \                                    const int next_b) const {\r\n    assert(next_b\
    \ == static_cast<int>(std::round(std::pow(10, next_log_b))));\r\n    const int\
    \ max_base = std::max(LogB, next_log_b);\r\n    std::vector<long long> p(max_base\
    \ + 1, 1);\r\n    for (int i = 1; i <= max_base; ++i) {\r\n      p[i] = p[i -\
    \ 1] * 10;\r\n    }\r\n    std::vector<long long> res;\r\n    long long cur_val\
    \ = 0;\r\n    int cur_log_b = 0;\r\n    for (const int e : data) {\r\n      cur_val\
    \ += p[cur_log_b] * e;\r\n      cur_log_b += LogB;\r\n      for (; cur_log_b >=\
    \ next_log_b; cur_log_b -= next_log_b) {\r\n        res.emplace_back(cur_val %\
    \ next_b);\r\n        cur_val /= next_b;\r\n      }\r\n    }\r\n    res.emplace_back(cur_val);\r\
    \n    while (!res.empty() && res.back() == 0) res.pop_back();\r\n    return res;\r\
    \n  }\r\n  int digit_sum() const {\r\n    assert(sgn == 1);\r\n    int res = 0;\r\
    \n    for (char c : to_string()) res += c - '0';\r\n    return res;\r\n  }\r\n\
    \  int length() const {\r\n    if (data.empty()) return 0;\r\n    int res = LogB\
    \ * (data.size() - 1);\r\n    for (int tmp = data.back(); tmp > 0; tmp /= 10)\
    \ {\r\n      ++res;\r\n    }\r\n    return res;\r\n  }\r\n  BigInt pow(BigInt\
    \ exponent) const {\r\n    BigInt res = 1, tmp = *this;\r\n    for (; exponent\
    \ > 0; exponent /= 2) {\r\n      if (exponent.data.front() & 1) res *= tmp;\r\n\
    \      tmp *= tmp;\r\n    }\r\n    return res;\r\n  }\r\n  long long to_llong()\
    \ const {\r\n    assert(*this >= std::numeric_limits<long long>::min() &&\r\n\
    \           *this <= std::numeric_limits<long long>::max());\r\n    long long\
    \ res = 0;\r\n    for (int i = static_cast<int>(data.size()) - 1; i >= 0; --i)\
    \ {\r\n      res = res * B + data[i];\r\n    }\r\n    return res;\r\n  }\r\n \
    \ std::string to_string() const {\r\n    std::stringstream ss;\r\n    ss << *this;\r\
    \n    std::string res;\r\n    ss >> res;\r\n    return res;\r\n  }\r\n  void trim()\
    \ {\r\n    while (!data.empty() && data.back() == 0) data.pop_back();\r\n    if\
    \ (data.empty()) sgn = 1;\r\n  }\r\n  BigInt& operator=(long long val) {\r\n \
    \   if (val < 0) {\r\n      sgn = -1;\r\n      val = -val;\r\n    } else {\r\n\
    \      sgn = 1;\r\n    }\r\n    data.clear();\r\n    for (; val > 0; val /= B)\
    \ {\r\n      data.emplace_back(val % B);\r\n    }\r\n    return *this;\r\n  }\r\
    \n  BigInt& operator=(const std::string& s) {\r\n    sgn = 1;\r\n    data.clear();\r\
    \n    if (!s.empty()) {\r\n      int tail = 0;\r\n      if (s.front() == '-')\
    \ {\r\n        sgn = -1;\r\n        tail = 1;\r\n      } else if (s.front() ==\
    \ '+') {\r\n        tail = 1;\r\n      }\r\n      for (int i = s.length() - 1;\
    \ i >= tail; i -= LogB) {\r\n        int val = 0;\r\n        for (int j = std::max(tail,\
    \ i - LogB + 1); j <= i; ++j) {\r\n          val = val * 10 + (s[j] - '0');\r\n\
    \        }\r\n        data.emplace_back(val);\r\n      }\r\n    }\r\n    trim();\r\
    \n    return *this;\r\n  }\r\n  BigInt& operator=(const BigInt& x) = default;\r\
    \n  BigInt& operator+=(const BigInt& x) {\r\n    if (sgn != x.sgn) return *this\
    \ -= -x;\r\n    if (data.size() < x.data.size()) data.resize(x.data.size(), 0);\r\
    \n    bool carry = false;\r\n    for (int i = 0; i < x.data.size() || carry; ++i)\
    \ {\r\n      if (i == data.size()) data.emplace_back(0);\r\n      data[i] += (i\
    \ < x.data.size() ? x.data[i] : 0) + carry;\r\n      if (data[i] >= B) {\r\n \
    \       carry = true;\r\n        data[i] -= B;\r\n      } else {\r\n        carry\
    \ = false;\r\n      }\r\n    }\r\n    return *this;\r\n  }\r\n  BigInt& operator-=(const\
    \ BigInt& x) {\r\n    if (sgn != x.sgn) return *this += -x;\r\n    if ((sgn ==\
    \ 1 ? *this : -*this) < (x.sgn == 1 ? x : -x)) {\r\n      return *this = -(x -\
    \ *this);\r\n    }\r\n    bool carry = false;\r\n    for (int i = 0; i < data.size()\
    \ || carry; ++i) {\r\n      data[i] -= (i < x.data.size() ? x.data[i] : 0) + carry;\r\
    \n      if (data[i] < 0) {\r\n        carry = true;\r\n        data[i] += B;\r\
    \n      } else {\r\n        carry = false;\r\n      }\r\n    }\r\n    trim();\r\
    \n    return *this;\r\n  }\r\n  BigInt& operator*=(const BigInt& x) {\r\n    constexpr\
    \ int next_log_b = 6, next_b = 1000000;\r\n    std::vector<long long> this6 =\
    \ convert_base(next_log_b, next_b);\r\n    std::vector<long long> x6 = x.convert_base(next_log_b,\
    \ next_b);\r\n    std::vector<long long> res = karatsuba(&this6, 0, this6.size(),\r\
    \n                                           &x6, 0, x6.size());\r\n    for (int\
    \ i = 0; i < res.size(); ++i) {\r\n      const long long quo = res[i] / next_b;\r\
    \n      if (quo > 0) {\r\n        if (i + 1 == res.size()) {\r\n          res.emplace_back(quo);\r\
    \n        } else {\r\n          res[i + 1] += quo;\r\n        }\r\n        res[i]\
    \ %= next_b;\r\n      }\r\n    }\r\n    std::string s = (sgn * x.sgn == 1 ? \"\
    +\" : \"-\");\r\n    for (int i = static_cast<int>(res.size()) - 1; i >= 0; --i)\
    \ {\r\n      const std::string tmp = std::to_string(res[i]);\r\n      s += std::string(next_log_b\
    \ - tmp.length(), '0') + tmp;\r\n    }\r\n    return *this = s;\r\n  }\r\n  BigInt&\
    \ operator/=(int x) { return *this = divide(x).first; }\r\n  BigInt& operator/=(const\
    \ BigInt& x) { return *this = divide(x).first; }\r\n  BigInt& operator%=(int x)\
    \ { return *this = divide(x).second; }\r\n  BigInt& operator%=(const BigInt& x)\
    \ { return *this = divide(x).second; }\r\n  bool operator==(const BigInt& x) const\
    \ {\r\n    if (sgn != x.sgn || data.size() != x.data.size()) return false;\r\n\
    \    const int n = data.size();\r\n    for (int i = 0; i < n; ++i) {\r\n     \
    \ if (data[i] != x.data[i]) return false;\r\n    }\r\n    return true;\r\n  }\r\
    \n  bool operator!=(const BigInt& x) const { return !(*this == x); }\r\n  bool\
    \ operator<(const BigInt& x) const {\r\n    if (sgn != x.sgn) return sgn < x.sgn;\r\
    \n    if (data.size() != x.data.size()) {\r\n      return sgn * data.size() <\
    \ x.sgn * x.data.size();\r\n    }\r\n    for (int i = static_cast<int>(data.size())\
    \ - 1; i >= 0; --i) {\r\n      if (data[i] != x.data[i]) return data[i] * sgn\
    \ < x.data[i] * x.sgn;\r\n    }\r\n    return false;\r\n  }\r\n  bool operator<=(const\
    \ BigInt& x) const { return !(x < *this); }\r\n  bool operator>(const BigInt&\
    \ x) const { return x < *this; }\r\n  bool operator>=(const BigInt& x) const {\
    \ return !(*this < x); }\r\n  BigInt& operator++() { return *this += 1; }\r\n\
    \  BigInt operator++(int) {\r\n    const BigInt res = *this;\r\n    ++*this;\r\
    \n    return res;\r\n  }\r\n  BigInt& operator--() { return *this -= 1; }\r\n\
    \  BigInt operator--(int) {\r\n    const BigInt res = *this;\r\n    --*this;\r\
    \n    return res;\r\n  }\r\n  BigInt operator+() const { return *this; }\r\n \
    \ BigInt operator-() const {\r\n    BigInt res = *this;\r\n    res.sgn = -res.sgn;\r\
    \n    return res;\r\n  }\r\n  BigInt operator+(const BigInt& x) const { return\
    \ BigInt(*this) += x; }\r\n  BigInt operator-(const BigInt& x) const { return\
    \ BigInt(*this) -= x; }\r\n  BigInt operator*(const BigInt& x) const { return\
    \ BigInt(*this) *= x; }\r\n  BigInt operator/(int x) const { return BigInt(*this)\
    \ /= x; }\r\n  BigInt operator/(const BigInt& x) const { return BigInt(*this)\
    \ /= x; }\r\n  BigInt operator%(int x) const { return BigInt(*this) %= x; }\r\n\
    \  BigInt operator%(const BigInt& x) const { return BigInt(*this) %= x; }\r\n\
    \  friend std::ostream& operator<<(std::ostream& os, const BigInt& x) {\r\n  \
    \  if (x.sgn == -1) os << '-';\r\n    os << (x.data.empty() ? 0 : x.data.back());\r\
    \n    for (int i = static_cast<int>(x.data.size()) - 2; i >= 0; --i) {\r\n   \
    \   os << std::setw(LogB) << std::setfill('0') << x.data[i];\r\n    }\r\n    return\
    \ os;\r\n  }\r\n  friend std::istream& operator>>(std::istream& is, BigInt& x)\
    \ {\r\n    std::string s;\r\n    is >> s;\r\n    x = s;\r\n    return is;\r\n\
    \  }\r\n private:\r\n  std::vector<long long> karatsuba(\r\n      std::vector<long\
    \ long>* a, const int a_l, const int a_r,\r\n      std::vector<long long>* b,\
    \ const int b_l, const int b_r) const {\r\n    const int a_len = a_r - a_l, b_len\
    \ = b_r - b_l;\r\n    if (a_len < b_len) return karatsuba(b, b_l, b_r, a, a_l,\
    \ a_r);\r\n    std::vector<long long> res(a_len + b_len, 0);\r\n    if (b_len\
    \ <= 32) {\r\n      for (int i = a_l; i < a_r; ++i) {\r\n        for (int j =\
    \ b_l; j < b_r; ++j) {\r\n          res[(i - a_l) + (j - b_l)] += (*a)[i] * (*b)[j];\r\
    \n        }\r\n      }\r\n    } else {\r\n      const int mid = (a_len + 1) /\
    \ 2, n = std::min(a_len, mid);\r\n      for (int i = a_l; i + mid < a_r; ++i)\
    \ {\r\n        (*a)[i] += (*a)[i + mid];\r\n      }\r\n      for (int i = b_l;\
    \ i + mid < b_r; ++i) {\r\n        (*b)[i] += (*b)[i + mid];\r\n      }\r\n  \
    \    std::vector<long long> tmp =\r\n          karatsuba(a, a_l, a_l + mid, b,\
    \ b_l, b_l + n);\r\n      std::copy(tmp.begin(), tmp.end(), std::next(res.begin(),\
    \ mid));\r\n      for (int i = a_l; i + mid < a_r; ++i) {\r\n        (*a)[i] -=\
    \ (*a)[i + mid];\r\n      }\r\n      for (int i = b_l; i + mid < b_r; ++i) {\r\
    \n        (*b)[i] -= (*b)[i + mid];\r\n      }\r\n      tmp = karatsuba(a, a_l,\
    \ a_l + mid, b, b_l, b_l + n);\r\n      for (int i = 0; i < tmp.size(); ++i) {\r\
    \n        res[i] += tmp[i];\r\n        res[mid + i] -= tmp[i];\r\n      }\r\n\
    \      tmp = karatsuba(a, a_l + mid, a_r, b, b_l + n, b_r);\r\n      for (int\
    \ i = 0; i < tmp.size(); ++i) {\r\n        res[mid + i] -= tmp[i];\r\n       \
    \ res[(mid << 1) + i] += tmp[i];\r\n      }\r\n    }\r\n    while (!res.empty()\
    \ && res.back() == 0) res.pop_back();\r\n    return res;\r\n  }\r\n  std::pair<BigInt,\
    \ int> divide(int x) const {\r\n    assert(x != 0);\r\n    BigInt dividend = *this;\r\
    \n    if (x < 0) {\r\n      dividend.sgn = -dividend.sgn;\r\n      x = -x;\r\n\
    \    }\r\n    long long rem = 0;\r\n    for (int i = static_cast<int>(dividend.data.size())\
    \ - 1; i >= 0; --i) {\r\n      const long long tmp = rem * B + dividend.data[i];\r\
    \n      dividend.data[i] = tmp / x;\r\n      rem = tmp % x;\r\n    }\r\n    dividend.trim();\r\
    \n    return {dividend, static_cast<int>(rem)};\r\n  }\r\n  std::pair<BigInt,\
    \ BigInt> divide(const BigInt& x) const {\r\n    assert(!x.data.empty());\r\n\
    \    const int k = B / (x.data.back() + 1);\r\n    const BigInt dividend = (sgn\
    \ == 1 ? *this : -*this) * k;\r\n    const BigInt divisor = (x.sgn == 1 ? x :\
    \ -x) * k;\r\n    BigInt quo, rem = 0;\r\n    quo.data.resize(dividend.data.size());\r\
    \n    const int n = divisor.data.size();\r\n    for (int i = static_cast<int>(dividend.data.size())\
    \ - 1; i >= 0; --i) {\r\n      rem.data.emplace(rem.data.begin(), dividend.data[i]);\r\
    \n      quo.data[i] =\r\n          ((n < rem.data.size() ? static_cast<long long>(rem.data[n])\
    \ * B : 0)\r\n           + (n - 1 < rem.data.size() ? rem.data[n - 1] : 0))\r\n\
    \          / divisor.data.back();\r\n      rem -= divisor * quo.data[i];\r\n \
    \     while (rem.sgn == -1) {\r\n        rem += divisor;\r\n        --quo.data[i];\r\
    \n      }\r\n    }\r\n    quo.sgn = sgn * x.sgn;\r\n    quo.trim();\r\n    rem.sgn\
    \ = sgn;\r\n    rem.trim();\r\n    return {quo, rem / k};\r\n  }\r\n};\r\nnamespace\
    \ std {\r\ntemplate <int LogB, int B>\r\nBigInt<LogB, B> __gcd(BigInt<LogB, B>\
    \ a, BigInt<LogB, B> b) {\r\n  while (!b.data.empty()) std::swap(a %= b, b);\r\
    \n  return a;\r\n}\r\ntemplate <int LogB, int B>\r\nBigInt<LogB, B> __lcm(const\
    \ BigInt<LogB, B>& a, const BigInt<LogB, B>& b) {\r\n  return a / std::__gcd(a,\
    \ b) * b;\r\n}\r\ntemplate <int LogB, int B>\r\nBigInt<LogB, B> abs(const BigInt<LogB,\
    \ B>& x) { return x.sgn == 1 ? x : -x; }\r\ntemplate <int LogB, int B>\r\nBigInt<LogB,\
    \ B> max(const BigInt<LogB, B>& a, const BigInt<LogB, B>& b) {\r\n  return a <\
    \ b ? b : a;\r\n}\r\ntemplate <int LogB, int B>\r\nBigInt<LogB, B> min(const BigInt<LogB,\
    \ B>& a, const BigInt<LogB, B>& b) {\r\n  return a < b ? a : b;\r\n}\r\n}  //\
    \ namespace std\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/bigint.hpp
  requiredBy: []
  timestamp: '2022-02-19 23:06:53+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/bigint.07.test.cpp
  - test/math/twelvefold_way/pascal.test.cpp
  - test/math/bigint.01.test.cpp
  - test/math/bigint.05.test.cpp
  - test/math/bigint.02.test.cpp
  - test/math/bigint.10.test.cpp
  - test/math/bigint.08.test.cpp
  - test/math/bigint.03.test.cpp
  - test/math/bigint.06.test.cpp
  - test/math/bigint.04.test.cpp
  - test/math/bigint.09.test.cpp
documentation_of: math/bigint.hpp
layout: document
title: "\u591A\u500D\u9577\u6574\u6570"
---


## 時間計算量

|アルゴリズム|時間計算量|
|:--:|:--:|
|カラツバ法 (Karatsuba algorithm)|$O(N^{\log 3}) \sim O(N^{1.585})$|
|Knuth's Algorithm D|$O(N^2)$|


## 参考

- https://lumakernel.github.io/ecasdqina/misc/BigInteger
- https://github.com/spaghetti-source/algorithm/blob/b9b6e0b7c50600d985b2c0114fb569ee2d3102dc/math/bigint.cc

カラツバ法
- http://xn--w6q13e505b.jp/method/karatsuba.html

Knuth's Algorithm D
- http://yamatyuu.net/computer/program/long/div/index.html


## ToDo

- https://qiita.com/square1001/items/1aa12e04934b6e749962
- http://xn--w6q13e505b.jp/method/
- http://poset.jp/ompa/node3.html
- 乗算の高速化
  - http://xn--w6q13e505b.jp/method/mult.html
  - http://fussy.web.fc2.com/algo/math3_mult.htm
  - ショーンハーゲ・ストラッセン法 (Schönhage–Strassen algorithm)
    - https://ja.wikipedia.org/wiki/%E3%82%B7%E3%83%A7%E3%83%BC%E3%83%B3%E3%83%8F%E3%83%BC%E3%82%B2%E3%83%BB%E3%82%B9%E3%83%88%E3%83%A9%E3%83%83%E3%82%BB%E3%83%B3%E6%B3%95
    - https://qiita.com/peria/items/fbdd52768b4659823d88
    - http://poset.jp/ompa/node5.html
    - https://qiita.com/peria/items/19e37b192cb62bdbc3a1
    - https://cookies.hatenablog.jp/entry/2018/12/18/092106
    - https://pisan-dub.jp/doc/2011/20110201001/2000/20000819001/0.pdf
  - Toom–Cook 法 (Toom-3)
    - https://en.wikipedia.org/wiki/Toom%E2%80%93Cook_multiplication
    - http://xn--w6q13e505b.jp/method/toomcook.html
    - https://azapen6.hatenablog.com/entry/2014/04/11/235315
    - https://www.mk-mode.com/blog/2013/04/29/cpp-big-multiply-toom-cook-3/
    - http://poset.jp/ompa/node4.html#SECTION00044000000000000000
- 階乗
  - http://fussy.web.fc2.com/algo/math2_bignum.htm
- ニュートン・ラプソン除算 (Newton–Raphson division)
  - https://ja.wikipedia.org/wiki/%E9%99%A4%E7%AE%97_(%E3%83%87%E3%82%B8%E3%82%BF%E3%83%AB)#%E3%83%8B%E3%83%A5%E3%83%BC%E3%83%88%E3%83%B3-%E3%83%A9%E3%83%97%E3%82%BD%E3%83%B3%E9%99%A4%E7%AE%97
  - https://wiki2.org/en/Division_algorithm#Fast_division_methods
  - http://xn--w6q13e505b.jp/method/newton.html
  - http://www.hundredsoft.jp/win7blog/log/eid99.html
- 平方根
  - https://codeforces.com/blog/entry/22566
  - http://poset.jp/ompa/node2.html#SECTION00024000000000000000
  - http://www.prefield.com/algorithm/math/bignum.html


## Verified

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/2679/review/4092735/emthrm/C++14
- [加算](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_2_A/review/4092738/emthrm/C++14)
- [減算](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_2_B/review/4092740/emthrm/C++14)
- [乗算](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_2_F/review/4092742/emthrm/C++14)
- [除算](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_2_D/review/4092743/emthrm/C++14)
- [剰余演算](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_2_E/review/4092744/emthrm/C++14)
- [大小比較](https://atcoder.jp/contests/abc059/submissions/9334290)
- [冪演算](https://codeforces.com/problemsets/acmsguru/submission/99999/68307060)
- [桁和](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ITP1_8_B/review/4967090/emthrm/C++17)
- [桁数](https://onlinejudge.u-aizu.ac.jp/solutions/problem/0015/review/4092752/emthrm/C++14)
